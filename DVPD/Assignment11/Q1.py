import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.datasets import load_iris
from sklearn.preprocessing import StandardScaler
from sklearn.decomposition import PCA
from pandas.plotting import parallel_coordinates

iris = load_iris()
X = iris.data
y = iris.target
target_names = iris.target_names

feature_names = iris.feature_names
df = pd.DataFrame(X, columns=feature_names)
df['Class'] = [target_names[i] for i in y]

scaler = StandardScaler()
X_scaled = scaler.fit_transform(X)

pca = PCA()
pca.fit(X_scaled)

explained_variance = pca.explained_variance_ratio_
print("Explained Variance Ratio of each component:")
for i, var in enumerate(explained_variance):
    print(f"Principal Component {i+1}: {var:.4f} ({var*100:.2f}%)")

plt.figure(figsize=(10, 5))
plt.plot(range(1, len(explained_variance) + 1), explained_variance, marker='o', label='Individual Explained Variance')
plt.plot(range(1, len(explained_variance) + 1), np.cumsum(explained_variance), marker='s', linestyle='--', label='Cumulative Explained Variance')
plt.title('Scree Plot of Explained Variance Ratio')
plt.xlabel('Principal Component')
plt.ylabel('Explained Variance Ratio')
plt.xticks(range(1, len(explained_variance) + 1))
plt.legend()
plt.grid(True)
plt.show()

X_pca = pca.transform(X_scaled)
df_pca = pd.DataFrame(X_pca[:, :2], columns=['PC1', 'PC2'])
df_pca['Class'] = df['Class']

plt.figure(figsize=(8, 6))
sns.scatterplot(data=df_pca, x='PC1', y='PC2', hue='Class', palette='viridis', s=100)
plt.title('PCA Projection (First Two Principal Components)')
plt.xlabel(f'PC1 ({explained_variance[0]*100:.2f}% Variance)')
plt.ylabel(f'PC2 ({explained_variance[1]*100:.2f}% Variance)')
plt.grid(True)
plt.show()

df_scaled = pd.DataFrame(X_scaled, columns=feature_names)
df_scaled['Class'] = df['Class']

plt.figure(figsize=(10, 6))
parallel_coordinates(df_scaled, class_column='Class', colormap='viridis', alpha=0.7)
plt.title('Parallel Coordinates Plot of Standardized Features')
plt.xlabel('Features')
plt.ylabel('Standardized Values')
plt.xticks(rotation=15)
plt.legend(loc='upper right')
plt.grid(True)
plt.show()