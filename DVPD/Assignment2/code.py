import pandas as pd

print("Starting data cleaning process...\n")

df = pd.read_csv('/home/suryansh/Documents/College/DVPD/Assignment2/Titanic-Dataset.csv')

print("--- Dataset Structure ---")
df.info() 

print("\n--- First 5 Rows ---")
print(df.head())

print("\n--- Missing Values Before Cleaning ---")
print(df.isnull().sum())

df['Age'] = df['Age'].fillna(df['Age'].median())

mode_embarked = df['Embarked'].mode()[0]
df['Embarked'] = df['Embarked'].fillna(mode_embarked)

df = df.drop(columns=['Cabin'])

print(f"\n--- Duplicates Found: {df.duplicated().sum()} ---")
df = df.drop_duplicates()

df['Survived'] = df['Survived'].astype(int)
df['Pclass'] = df['Pclass'].astype(int)

if 'Sex' in df.columns:
    df['Sex'] = df['Sex'].str.strip().str.lower()
if 'Name' in df.columns:
    df['Name'] = df['Name'].str.strip()

df.to_csv('cleaned_titanic.csv', index=False)

print("\nSuccess! The dataset has been cleaned and saved as 'cleaned_titanic.csv'.")
