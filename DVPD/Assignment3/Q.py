import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import numpy as np

sns.set_theme(style="whitegrid")#grid

print("--- Step 1: Loading Dataset ---")
df = sns.load_dataset('titanic')
print("Dataset loaded successfully. Shape:", df.shape)#gives dimensions
print(df.head(), "\n")

print("--- Step 2: Univariate Analysis ---")
print("Summary Statistics (Numerical):\n", df.describe(), "\n")
print("Mode for all features:\n", df.mode().iloc[0], "\n")

plt.figure(figsize=(12, 5))
plt.subplot(1, 2, 1)
sns.histplot(df['age'].dropna(), kde=True, bins=30, color='blue')
plt.title('Histogram of Age')

plt.subplot(1, 2, 2)
sns.histplot(df['fare'], kde=True, bins=30, color='green')
plt.title('Histogram of Fare')
plt.tight_layout()
plt.show()

plt.figure(figsize=(12, 5))
plt.subplot(1, 2, 1)
sns.boxplot(y=df['age'], color='cyan')
plt.title('Box Plot of Age')

plt.subplot(1, 2, 2)
sns.boxplot(y=df['fare'], color='lightgreen')
plt.title('Box Plot of Fare')
plt.tight_layout()
plt.show()

print("--- Step 3: Bivariate Analysis (Generating Plots) ---")

plt.figure(figsize=(8, 5))
sns.scatterplot(x='age', y='fare', hue='survived', data=df, alpha=0.7)
plt.title('Scatter Plot: Age vs Fare (colored by Survival)')
plt.show()

sns.pairplot(df[['age', 'fare', 'survived', 'pclass']].dropna(), hue='survived', corner=True)
plt.suptitle('Pair Plot of Numerical Features', y=1.02)
plt.show()

plt.figure(figsize=(8, 6))
corr_matrix = df.select_dtypes(include=[np.number]).corr()
sns.heatmap(corr_matrix, annot=True, cmap='coolwarm', fmt=".2f", linewidths=0.5)
plt.title('Correlation Heatmap')
plt.show()

print("--- Step 4: Categorical Variable Analysis ---")
plt.figure(figsize=(12, 5))

plt.subplot(1, 2, 1)
sns.countplot(x='class', data=df, palette='Set2')
plt.title('Count Plot: Passengers per Class')

plt.subplot(1, 2, 2)
sns.barplot(x='class', y='survived', data=df, palette='Set2')
plt.title('Bar Chart: Survival Rate by Class')
plt.ylabel('Survival Probability')
plt.tight_layout()
plt.show()

print("--- Step 5: Identifying Outliers (IQR Method for 'Fare') ---")
Q1 = df['fare'].quantile(0.25)
Q3 = df['fare'].quantile(0.75)
IQR = Q3 - Q1
lower_bound = Q1 - 1.5 * IQR
upper_bound = Q3 + 1.5 * IQR

outliers = df[(df['fare'] < lower_bound) | (df['fare'] > upper_bound)]
print(f"IQR for Fare: {IQR:.2f}")
print(f"Lower Bound: {lower_bound:.2f}, Upper Bound: {upper_bound:.2f}")
print(f"Number of outlier records in 'Fare': {len(outliers)}")
print("First 5 Outliers:\n", outliers[['survived', 'pclass', 'sex', 'age', 'fare']].head(), "\n")
