import os
import pandas as pd
import plotly.express as px
import streamlit as st

st.set_page_config(page_title="Superstore Sales Dashboard", layout="wide")

# ============ STEP 1 + 2: Select the dataset and import it (from the internet) ============
URL = "https://raw.githubusercontent.com/edusatyaki/Dataset/main/Sample%20-%20Superstore.csv"
LOCAL = os.path.join(os.path.dirname(os.path.abspath(__file__)), "Sample - Superstore.csv")


@st.cache_data(show_spinner="Loading dataset")
def load_data(source):
    """Read a CSV from a URL, file path, or upload, and make Order Date a real date."""
    data = pd.read_csv(source, encoding="latin-1")
    data["Order Date"] = pd.to_datetime(data["Order Date"])
    return data


df = None
try:
    df = load_data(URL)                          # 1st choice: internet
except Exception:
    if os.path.exists(LOCAL):                    # 2nd choice: file in the same folder
        df = load_data(LOCAL)
    else:                                        # 3rd choice: upload by hand
        st.sidebar.warning("Could not load from the internet.")
        upload = st.sidebar.file_uploader("Upload the Superstore CSV", type="csv")
        if upload is not None:
            df = load_data(upload)
if df is None:
    st.title("Superstore Sales Dashboard")
    st.info("Check your internet connection, or upload the Superstore CSV in the sidebar.")
    st.stop()

needed = ["Order ID", "Order Date", "Region", "Category", "Sub-Category", "Sales", "Profit"]
missing = [c for c in needed if c not in df.columns]
if missing:
    st.error(f"The CSV is missing these columns: {', '.join(missing)}")
    st.stop()

# ============ STEP 5: Interactive filters (sidebar) ============
st.sidebar.header("Filters")
regions = st.sidebar.multiselect("Region", sorted(df["Region"].unique()),
                                 default=sorted(df["Region"].unique()))
cats = st.sidebar.multiselect("Category", sorted(df["Category"].unique()),
                              default=sorted(df["Category"].unique()))
start, end = df["Order Date"].min().date(), df["Order Date"].max().date()
dates = st.sidebar.date_input("Date range", (start, end), min_value=start, max_value=end)
if len(dates) != 2:
    st.info("Pick both a start and an end date.")
    st.stop()

# 'f' is the filtered table. Every KPI, chart and insight uses it.
f = df[df["Region"].isin(regions) & df["Category"].isin(cats)
       & df["Order Date"].between(pd.Timestamp(dates[0]), pd.Timestamp(dates[1]))]
if f.empty:
    st.warning("No data for these filters. Select more regions or widen the dates.")
    st.stop()

# ============ STEP 6: One canvas, consistent title ============
st.title("Superstore Sales Dashboard")
st.caption(f"Showing {f['Order ID'].nunique():,} orders")

# ============ STEP 3: KPI cards ============
total_sales = f["Sales"].sum()
total_profit = f["Profit"].sum()
orders = f["Order ID"].nunique()
aov = total_sales / orders

c1, c2, c3, c4 = st.columns(4)
c1.metric("Total Sales", f"${total_sales:,.0f}")
c2.metric("Total Profit", f"${total_profit:,.0f}")
c3.metric("Number of Orders", f"{orders:,}")
c4.metric("Average Order Value", f"${aov:,.0f}")

# ============ STEP 4: Charts ============
left, right = st.columns(2)

with left:
    st.subheader("Sales trend over months")
    monthly = (f.groupby(f["Order Date"].dt.to_period("M").dt.to_timestamp())["Sales"]
               .sum().reset_index())
    st.plotly_chart(px.line(monthly, x="Order Date", y="Sales", markers=True),
                    use_container_width=True)

with right:
    st.subheader("Sales by region / category")
    by = st.radio("Group by", ["Region", "Category"], horizontal=True)
    bar = f.groupby(by)["Sales"].sum().reset_index().sort_values("Sales")
    st.plotly_chart(px.bar(bar, x="Sales", y=by, orientation="h"),
                    use_container_width=True)

st.subheader("Tree map: sales by sub-category (colour = profit margin)")
t = f.groupby(["Category", "Sub-Category"])[["Sales", "Profit"]].sum().reset_index()
t["Margin"] = t["Profit"] / t["Sales"]
st.plotly_chart(px.treemap(t, path=["Category", "Sub-Category"], values="Sales",
                           color="Margin", color_continuous_scale="RdYlGn",
                           color_continuous_midpoint=0),
                use_container_width=True)

# ============ STEP 7: Key insights + export ============
st.subheader("Key insights")
best_region = f.groupby("Region")["Profit"].sum().idxmax()
top_sub = f.groupby("Sub-Category")["Sales"].sum().idxmax()
sub_profit = f.groupby("Sub-Category")["Profit"].sum()
worst_sub = sub_profit.idxmin()
peak = monthly.loc[monthly["Sales"].idxmax()]

insights = [
    f"Total sales were ${total_sales:,.0f} with ${total_profit:,.0f} profit "
    f"({total_profit / total_sales:.1%} margin).",
    f"Sales peaked in {peak['Order Date']:%B %Y} at ${peak['Sales']:,.0f}.",
    f"{best_region} is the most profitable region.",
    f"{top_sub} is the top-selling sub-category.",
    f"{worst_sub} has the lowest profit (${sub_profit.min():,.0f}).",
]
for line in insights:
    st.markdown(f"- {line}")

report = "# Key Insights\n\n" + "\n".join(f"- {i}" for i in insights)
st.download_button("Export insights (.md)", report, "insights.md")