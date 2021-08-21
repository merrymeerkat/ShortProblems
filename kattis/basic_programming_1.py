
def action_1(arr):
    print(7)

def action_2(arr):
    if arr[0] > arr[1]:
        print("Bigger")
    elif arr[0] < arr[1]:
        print("Smaller")
    else:
        print("Equal")

def action_3(arr):
    ls = sorted(arr[:3])
    print(ls[1])

def action_4(arr):
    print(sum(arr))

def action_5(arr):
    count = 0
    for num in arr:
        if num % 2 == 0:
            count += num
    print(count)

def action_6(arr):
    print(''.join(list(map(lambda x: chr((x % 26) + 97), arr))))

def action_7(arr):
    idx = 0
    seen = set()
    seen.add(idx)
    n = len(arr)
    while idx != n - 1:
        idx = arr[idx]
        if idx in seen:
            print("Cyclic")
            return
        if idx >= n or idx < 0:
            print("Out")
            return
        seen.add(idx)
    print("Done")

def hash(t):
    switcher = {
        1 : action_1,
        2 : action_2,
        3 : action_3,
        4 : action_4,
        5 : action_5,
        6 : action_6,
        7 : action_7
    }
    return switcher(t)


# main
N, t = map(int, input().split())
line = input()
arr = list(map(int, line.strip().split()))
#hash(t)(arr)
if t == 1:
    action_1(arr)
elif t == 2:
    action_2(arr)
elif t == 3:
    action_3(arr)
elif t == 4:
    action_4(arr)
elif t == 5:
    action_5(arr)
elif t == 6:
    action_6(arr)
elif t == 7:
    action_7(arr)


