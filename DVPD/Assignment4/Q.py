import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.datasets import load_iris

iris = load_iris()
df = pd.DataFrame(iris.data, columns=iris.feature_names)

df['species'] = pd.Categorical.from_codes(iris.target, iris.target_names)

sns.set_theme(style="whitegrid")

feature_to_plot = 'sepal length (cm)'

plt.figure(figsize=(12, 4))
plt.suptitle(f'Histogram of {feature_to_plot} with Varying Bin Sizes', fontsize=14)

plt.subplot(1, 2, 1)
sns.histplot(df[feature_to_plot], bins=30, color='skyblue')
plt.title('Number of Bins = 30 (Smaller Bin Size)')

plt.subplot(1, 2, 2)
sns.histplot(df[feature_to_plot], bins=10, color='salmon')
plt.title('Number of Bins = 10 (Larger Bin Size)')

plt.tight_layout()
plt.show()

plt.figure(figsize=(8, 5))
sns.boxplot(x='species', y=feature_to_plot, data=df, palette='Set2')
plt.title(f'Box Plot of {feature_to_plot} Grouped by Species')
plt.show()

plt.figure(figsize=(8, 6))
corr_matrix = df.select_dtypes(include=['float64', 'int64']).corr()

sns.heatmap(corr_matrix, annot=True, cmap='coolwarm', fmt=".2f", vmin=-1, vmax=1)
plt.title('Heatmap of Numerical Features Correlation Matrix')
plt.show()

feature_x = 'petal length (cm)'
feature_y = 'petal width (cm)'

plt.figure(figsize=(8, 5))
sns.scatterplot(x=feature_x, y=feature_y, hue='species', data=df, palette='Set1', s=80)
plt.title(f'Scatter Plot: {feature_x} vs {feature_y} Colored by Class')
plt.show()