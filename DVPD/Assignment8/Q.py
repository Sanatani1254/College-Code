import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
import sklearn
from sklearn.datasets import load_iris
from sklearn.cluster import KMeans
from sklearn.neighbors import KNeighborsClassifier
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.metrics import accuracy_score

print(f"NumPy:        {np.__version__}")
print(f"Pandas:       {pd.__version__}")
print(f"Matplotlib:   {plt.matplotlib.__version__}")
print(f"Seaborn:      {sns.__version__}")
print(f"Scikit-learn: {sklearn.__version__}")

iris = load_iris()
df = pd.DataFrame(iris.data, columns=iris.feature_names)
df['target_species'] = iris.target

print("First 5 rows of the dataset:")
print(df.head(), "\n")

X = df.drop('target_species', axis=1)
y = df['target_species']

scaler = StandardScaler()
X_scaled = scaler.fit_transform(X)

X_train, X_test, y_train, y_test = train_test_split(X_scaled, y, test_size=0.3, random_state=42)

kmeans = KMeans(n_clusters=3, random_state=42, n_init=10)
df['kmeans_cluster'] = kmeans.fit_predict(X_scaled)

knn = KNeighborsClassifier(n_neighbors=5)
knn.fit(X_train, y_train)

y_pred = knn.predict(X_test)
accuracy = accuracy_score(y_test, y_pred)
print(f"KNN Classification Accuracy: {accuracy * 100:.2f}%\n")

fig, axes = plt.subplots(1, 2, figsize=(14, 5))

sns.scatterplot(
    ax=axes[0], data=df, 
    x='sepal length (cm)', y='sepal width (cm)', 
    hue='target_species', palette='viridis', s=100
)
axes[0].set_title('Actual Species (True Labels)')

sns.scatterplot(
    ax=axes[1], data=df, 
    x='sepal length (cm)', y='sepal width (cm)', 
    hue='kmeans_cluster', palette='Set1', s=100
)
axes[1].set_title('K-Means Discovered Clusters')

plt.tight_layout()
plt.show()