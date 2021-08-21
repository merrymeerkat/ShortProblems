from collections import deque

# record grid as 2d array for O(1) access
# BFS
    # start at (0,0), or top-left
    # enqueue neighbours according to step size
    # keep a visited[] array (visit each square only once)
    # keep a prev[] array to reconstruct path to final square, if any

# read input
m, n = map(int, input().split())
grid = [[] for i in range(m)]
for i in range(m):
    row = input()
    for ch in row:
        grid[i].append(int(ch))

# initialise queue
q = deque()
q.append((0,0))

# visited and previous arrays
visited = [0 for i in range(m * n)]
prev = [-1 for i in range(m * n)]
visited[0] = 1 # starting node has been visited
prev[0] = 0 # previous of origin is itself

# m = 3, n = 2
# [[0, 1],
#  [2, 3],
#  [4, 5]]
# id = row_pos * n + col_pos
# [0][0] -> 0, [0][1] -> 1, [2][1] -> 4 + 1 = 5, etc


# convenient direction array to find neighbours
# N, E, S, W
dr = [-1, 0, 1, 0]
dc = [0, 1, 0, -1]

# bfs
while q:
    curr_r, curr_c = q.popleft()
    step = grid[curr_r][curr_c]
    for i in range(4):
        nr = curr_r + (step * dr[i])
        nc = curr_c + (step * dc[i])
        if nr < 0 or nr >= m or nc < 0 or nc >= n:
            continue
        neighbour_id = nr * n + nc
        if visited[neighbour_id]:
            continue
        #print("visiting neighbour of id %s", neighbour_id)
        visited[neighbour_id] = 1
        prev[neighbour_id] = curr_r * n + curr_c
        q.append((nr, nc))

# count steps (or 0 if prev[target] = -1)
count = 0
curr_id = ((m - 1) * n) + n - 1
if prev[curr_id] == -1:
    print(-1)
else:
    while curr_id != 0:
        curr_id = prev[curr_id]
        count += 1
    print(count)

