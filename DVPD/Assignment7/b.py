import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
import squarify

data = {
    'Category': ['Electronics', 'Clothing', 'Home & Garden', 'Sports', 'Books', 'Toys'],
    'Sales': [125000, 85000, 60000, 35000, 15000, 10000]
}
df = pd.DataFrame(data)
df = df.sort_values(by='Sales', ascending=False)

plt.figure(figsize=(10, 6))
colors = sns.color_palette('pastel')[0:len(df)]

labels = [f'{cat}\n${sales/1000}k' for cat, sales in zip(df['Category'], df['Sales'])]

squarify.plot(sizes=df['Sales'], label=labels, color=colors, alpha=0.8, text_kwargs={'fontsize':10, 'weight':'bold'})
plt.title('Sales by Product Category', fontsize=14)
plt.axis('off')
plt.show()