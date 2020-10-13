import sys

# the sorting and the frequent deletions make this solution too slow. See akcija_faster.py for a
# more efficient version

prices = []
for i in sys.stdin:
    prices.append(int(i))

# first value = number of books
length = int(prices[0])

# delete first value (not a price)
del prices[0]

# order list of prices in descending order
prices_ord = []
prices_ord.append(0)
for price in prices:
    num = price
    length_ord = len(prices_ord)
    for i in range(length_ord):
        if num >= prices_ord[i]:
            prices_ord.insert(i, num)
            break

# For each group of three books, remove the cheapest
groups = int(length/3)
idx = 0
for i in range(groups):
    mini = prices_ord.index(min(prices_ord[idx], prices_ord[idx + 1], prices_ord[idx + 2]))
    del prices_ord[mini]
    idx += 2

# Compute and output final discounted price
total = sum(prices_ord)
print(total)


