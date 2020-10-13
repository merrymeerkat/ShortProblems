import sys

prices = []
for i in sys.stdin:
    prices.append(int(i))

# first value = number of books
length = int(prices[0])

# delete first value (not a price)
del prices[0]

prices.sort(reverse = True)
# order list of prices in descending order
"""
prices_ord = []
prices_ord.append(0)
for price in prices:
    num = price
    length_ord = len(prices_ord)
    for i in range(length_ord):
        if num >= prices_ord[i]:
            prices_ord.insert(i, num)
            break
"""

# For each group of three books, remove the cheapest
groups = int(length/3)
idx = 0
removed = 0
for i in range(groups):
    mini = min(prices[idx], prices[idx + 1], prices[idx + 2])
    removed += mini
    idx += 3

# Compute and output final discounted price
total = sum(prices) - removed
print(total)


