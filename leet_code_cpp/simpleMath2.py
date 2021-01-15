import math

N, M = map(int, input().split())
#M = int(input())

ans = math.floor(math.pow(10,N)/M)
ans = ans % M

print(ans)


