
N, dom = input().split()
N = int(N)

val = [[11,11],
       [4,4],
       [3,3],
       [20,2],
       [10,10],
       [14,0],
       [0,0],
       [0,0]]

def hash_(x):
    switcher = {
        "A": 0,
        "K": 1,
        "Q": 2,
        "J": 3,
        "T": 4,
        "9": 5,
        "8": 6,
        "7": 7
    }
    return switcher.get(x, -1)

count = 0
for _ in range(4 * N):
    line = input()
    # if suit is dominant
    if line[1] == dom:
        count += val[hash_(line[0])][0]
    else:
        count += val[hash_(line[0])][1]

print(count)
