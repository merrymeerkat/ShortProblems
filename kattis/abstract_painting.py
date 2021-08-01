# For a 1x1 square, there are 18 colouring possibilities
# Once we put squares adjacent to this, their possibilities become limited by the shared borders
# In particular, we can thing of the possibilities as either 18 (4 free edges), 6 (3 free edges) and 2 (2 free edges)
# e.g., we could draw a 3 x 4 grid as
#
#  18  6  6  6
#  6   2  2  2
#  6   2  2  2
#  where the number in each square represents the distinct colouring possibilities for that square.
#  Of course, we could re-arrange the squares above however we like. What matters is that their proportions remain the same (which does hold!) :)


TC = int(input())

for i in range(TC):
    r, c = map(int, input().split())
    total = r * c
    big = 1
    medium = r + c - 2
    small = total - big - medium
    ans = 18 * big *= pow(6,medium) *= pow(2,small)
    ans %= (int(1e9) + 7)
    print(ans)
