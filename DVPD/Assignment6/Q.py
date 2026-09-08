import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
from scipy.stats import chi2_contingency

df = sns.load_dataset('titanic').dropna(subset=['age', 'fare'])

numerical_cols = ['age', 'fare', 'pclass']
categorical_col1 = 'sex'
categorical_col2 = 'survived'

pearson_corr = df[numerical_cols].corr(method='pearson')

plt.figure(figsize=(6, 4))
sns.heatmap(pearson_corr, annot=True, cmap='coolwarm', fmt=".2f")
plt.title('Pearson Correlation Heatmap')
plt.show()

contingency_table = pd.crosstab(df[categorical_col1], df[categorical_col2])
chi2_stat, p_val, dof, expected = chi2_contingency(contingency_table)

print("--- Chi-Squared Test ---")
print(f"Chi2 Statistic: {chi2_stat:.4f}")
print(f"P-value: {p_val:.4e}")

covariance_matrix = df[numerical_cols].cov()
print("\n--- Covariance Matrix ---")
print(covariance_matrix)