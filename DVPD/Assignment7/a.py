import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
from statsmodels.tsa.seasonal import seasonal_decompose

flights = sns.load_dataset('flights')
flights['date'] = pd.to_datetime(flights['year'].astype(str) + '-' + flights['month'].astype(str) + '-01')
flights.set_index('date', inplace=True)
ts_data = flights['passengers']

plt.figure(figsize=(10, 4))
plt.plot(ts_data, label='Raw Passenger Data', color='blue')
plt.title('Monthly Airline Passengers (Raw)')
plt.xlabel('Date')
plt.ylabel('Passengers')
plt.legend()
plt.grid(True, linestyle='--', alpha=0.6)
plt.show()

rolling_mean = ts_data.rolling(window=12).mean()

plt.figure(figsize=(10, 4))
plt.plot(ts_data, label='Original Data', color='blue', alpha=0.5)
plt.plot(rolling_mean, label='12-Month Rolling Mean', color='red', linewidth=2)
plt.title('Airline Passengers with 12-Month Moving Average')
plt.legend()
plt.show()

decomposition = seasonal_decompose(ts_data, model='multiplicative')

fig = decomposition.plot()
fig.set_size_inches(10, 8)
plt.suptitle('Time Series Decomposition', y=1.02)
plt.show()