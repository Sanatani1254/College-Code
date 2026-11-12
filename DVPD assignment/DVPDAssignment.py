import pandas as pd
import plotly.express as px
import streamlit as st

URL = "https://raw.githubusercontent.com/edusatyaki/Dataset/main/Sample%20-%20Superstore.csv"

st.set_page_config(page_title="Superstore EDA", layout="wide")
st.title("Superstore Sales Analytics")
st.caption("Interactive exploratory data analysis of sales, profit and products.")

@st.cache_data
def load_data(file=None):
    return pd.read_csv(file if file is not None else URL, encoding="latin-1")

uploaded = st.sidebar.file_uploader("Upload Superstore CSV (optional)", type="csv")
try:
    raw = load_data(uploaded)
except Exception as e:
    st.error(f"Could not load the dataset: {e}")
    st.stop()

required = ["Order Date", "Region", "Category", "Sub-Category", "Sales", "Profit"]
missing = [c for c in required if c not in raw.columns]
if missing:
    st.error("Missing required columns: " + ", ".join(missing))
    st.stop()

df = raw.drop_duplicates().copy()
df["Order Date"] = pd.to_datetime(df["Order Date"], errors="coerce")
for c in ["Sales", "Profit", "Quantity", "Discount"]:
    if c in df:
        df[c] = pd.to_numeric(df[c], errors="coerce")

before = len(df)
df = df.dropna(subset=["Order Date", "Sales", "Profit"]).copy()
removed = before - len(df)

for c in ["Region", "Category", "Sub-Category"]:
    df[c] = df[c].fillna("Unknown")
for c in ["Quantity", "Discount"]:
    if c in df:
        df[c] = df[c].fillna(df[c].median())

if df.empty:
    st.error("No valid records remain after cleaning.")
    st.stop()

st.sidebar.header("Filters")
regions = st.sidebar.multiselect("Region", sorted(df.Region.unique()), default=sorted(df.Region.unique()))
categories = st.sidebar.multiselect("Category", sorted(df.Category.unique()), default=sorted(df.Category.unique()))
dates = st.sidebar.date_input(
    "Order date range",
    value=(df["Order Date"].min().date(), df["Order Date"].max().date())
)
if not isinstance(dates, (tuple, list)) or len(dates) != 2:
    st.info("Select a start date and an end date.")
    st.stop()

start, end = dates
if start > end:
    st.sidebar.error("Start date must be before the end date.")
    st.stop()

data = df[
    df.Region.isin(regions) & df.Category.isin(categories)
    & (df["Order Date"] >= pd.Timestamp(start))
    & (df["Order Date"] < pd.Timestamp(end) + pd.Timedelta(days=1))
].copy()

if data.empty:
    st.warning("No records match the selected filters.")
    st.stop()

sales, profit = data.Sales.sum(), data.Profit.sum()
orders = data["Order ID"].nunique() if "Order ID" in data else len(data)
a, b, c, d = st.columns(4)
a.metric("Total Sales", f"${sales:,.0f}")
b.metric("Total Profit", f"${profit:,.0f}")
c.metric("Orders", f"{orders:,}")
d.metric("Profit Margin", f"{profit / sales:.1%}" if sales else "N/A")

st.header("Visual Analysis")
monthly = data.assign(Month=data["Order Date"].dt.to_period("M").dt.to_timestamp())
monthly = monthly.groupby("Month", as_index=False).Sales.sum()
category = data.groupby("Category", as_index=False).Sales.sum().sort_values("Sales", ascending=False)
subcategory = data.groupby("Sub-Category", as_index=False).Profit.sum().sort_values("Profit")
region = data.groupby("Region", as_index=False).Sales.sum().sort_values("Sales", ascending=False)

left, right = st.columns(2)
with left:
    st.plotly_chart(px.line(monthly, x="Month", y="Sales", markers=True,
                            title="Monthly Sales Trend"), use_container_width=True)
    st.plotly_chart(px.bar(category, x="Category", y="Sales", text_auto=".2s",
                            title="Sales by Category"), use_container_width=True)
    st.plotly_chart(px.bar(subcategory, x="Profit", y="Sub-Category", orientation="h",
                            title="Profit by Sub-Category", color="Profit",
                            color_continuous_scale="RdYlGn"), use_container_width=True)
with right:
    st.plotly_chart(px.bar(region, x="Region", y="Sales", text_auto=".2s",
                            title="Sales by Region"), use_container_width=True)
    if "Discount" in data:
        st.plotly_chart(px.scatter(data, x="Discount", y="Profit", color="Category",
                                   title="Discount vs Profit",
                                   hover_data=["Sales", "Sub-Category"]),
                        use_container_width=True)
    st.plotly_chart(px.box(data, x="Category", y="Profit", color="Category",
                           title="Profit Distribution by Category"),
                    use_container_width=True)

st.header("Key Insights")
st.write(f"- Total sales are **${sales:,.2f}** and total profit is **${profit:,.2f}**.")
st.write(f"- **{category.iloc[0].Category}** is the highest-sales category.")
st.write(f"- **{region.iloc[0].Region}** is the highest-sales region.")
st.write(f"- **{subcategory.iloc[0]['Sub-Category']}** has the lowest total sub-category profit.")
st.caption("These findings describe the currently selected filters.")

with st.expander("Data cleaning summary"):
    st.write(f"Original records: {len(raw):,}")
    st.write(f"Exact duplicate rows removed: {len(raw) - len(raw.drop_duplicates()):,}")
    st.write(f"Rows removed for missing/invalid date, sales or profit: {removed:,}")
    st.write("Missing Region, Category and Sub-Category values were labelled 'Unknown'.")
    st.write("Missing Quantity and Discount values were replaced with their column median.")

st.download_button(
    "Download filtered data as CSV",
    data.to_csv(index=False).encode("utf-8"),
    "filtered_superstore_data.csv",
    "text/csv"
)
