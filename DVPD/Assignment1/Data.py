import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

df = pd.read_csv('/home/suryansh/Downloads/Assignment1/Data.csv')

print("Dataset loaded successfully. First few rows:")
print(df.head())
print("\nGenerating plots... (Close each plot window to load the next one)")

plt.figure(figsize=(8, 5))
sns.barplot(data=df, x='region', y='sales', palette='viridis')
plt.title('Sales by Region (Bar)')
plt.xlabel('Region')
plt.ylabel('Sales')
plt.show() 

plt.figure(figsize=(8, 5))
sns.lineplot(data=df, x='region', y='sales', marker='o', color='blue')
plt.title('Sales by Region (Line)')
plt.xlabel('Region')
plt.ylabel('Sales')
plt.show()

plt.figure(figsize=(8, 5))
sns.scatterplot(data=df, x='region', y='sales', s=150, color='red')
plt.title('Sales vs. Region (Scatter)')
plt.xlabel('Region')
plt.ylabel('Sales')
plt.show()