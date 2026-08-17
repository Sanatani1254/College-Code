
library(ggplot2)

df <- read.csv("Data.csv")

head(df)

ggplot(df, aes(x = region, y = sales, fill = region)) +
  geom_bar(stat = "identity") +
  labs(title = "Sales by Region", x = "Region", y = "Sales") +
  theme_minimal()

ggplot(df, aes(x = region, y = sales, color = region)) +
  geom_point(size = 5) +
  labs(title = "Sales vs. Region", x = "Region", y = "Sales") +
  theme_minimal()