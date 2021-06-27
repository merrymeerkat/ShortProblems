
N, Q = map(int, input().split())

par = []
for i in range(N):
    par.append(i)

rank = [0] * N

def get_root(a):
    parent = par[a]
    if parent == a:
        return a
    else:
        par[a] = get_root(parent)
        return par[a]

def join_set(a, b):
    ra = get_root(a)
    rb = get_root(b)
    if ra == rb: # sets are already joined
        return

    # keep the set that's tallest
    if rank[rb] > rank[ra]:
        join_set(b,a)
    else:
        par[rb] = ra

    # if both sets have the same rank, then the one that becomes root will have its rank incremented by 1
    if (rank[ra] == rank[rb]):
        rank[ra] += 1


for i in range(Q):
    line = input()
    op, a, b = line.split()
    a = int(a)
    b = int(b)

    if op == "?":
        if (get_root(a) == get_root(b)):
            print("yes")
        else:
            print("no")

    elif op == "=":
        join_set(a, b)


