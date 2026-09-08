import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.datasets import fetch_california_housing
from sklearn.preprocessing import MinMaxScaler

housing = fetch_california_housing()
df = pd.DataFrame(housing.data, columns=housing.feature_names)

feature_to_normalize = 'MedInc'

scaler = MinMaxScaler()
df['MedInc_Normalized'] = scaler.fit_transform(df[[feature_to_normalize]])

fig, axes = plt.subplots(1, 2, figsize=(12, 5))

sns.histplot(df[feature_to_normalize], bins=50, kde=True, ax=axes[0], color='blue')
axes[0].set_title('Original Distribution (MedInc)')
axes[0].set_xlabel('Median Income')

sns.histplot(df['MedInc_Normalized'], bins=50, kde=True, ax=axes[1], color='green')
axes[1].set_title('Normalized Distribution (Min-Max)')
axes[1].set_xlabel('Scaled Median Income (0 to 1)')

plt.tight_layout()
plt.show()

df['MedInc_Cut'] = pd.cut(df[feature_to_normalize], bins=5, labels=['Very Low', 'Low', 'Medium', 'High', 'Very High'])

df['MedInc_QCut'] = pd.qcut(df[feature_to_normalize], q=5, labels=['Very Low', 'Low', 'Medium', 'High', 'Very High'])

fig, axes = plt.subplots(1, 3, figsize=(18, 5))

sns.histplot(df[feature_to_normalize], bins=50, kde=False, ax=axes[0], color='gray')
axes[0].set_title('Original Continuous Distribution')

sns.countplot(data=df, x='MedInc_Cut', ax=axes[1], palette='viridis')
axes[1].set_title('Equal-Width Binning (pd.cut)')
axes[1].set_xlabel('Income Bins')

sns.countplot(data=df, x='MedInc_QCut', ax=axes[2], palette='magma')
axes[2].set_title('Equal-Frequency Binning (pd.qcut)')
axes[2].set_xlabel('Income Quantiles')

plt.tight_layout()
plt.show()