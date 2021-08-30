import functools

def convert(lst):
    # input is of form upper-middle-lower-middle-...

    # first split by '-'
    lst = list(lst.split('-'))

    # revert
    lst.reverse()

    ## now, convert "upper" to 3, "middle" to 2, and "lower" to 1
    def hash(cl):
        if cl == "upper":
            return 3
        elif cl == "middle":
            return 2
        elif cl == "lower":
            return 1

    # create list with a unique hash for each social position (two people only share a hash if they are in the very same social class)
    out_list = [2,2,2,2,2,2,2,2,2,2]
    for idx,cl in enumerate(lst):
        num = hash(cl)
        out_list[idx] = num

    return out_list

def compare(tuple1, tuple2):
    if tuple1[1] > tuple2[1]:
        return -1
    elif tuple2[1] > tuple1[1]:
        return 1
    else: # same class, so sort by name
        if tuple1[0] < tuple2[0]:
            return -1
        else:
            return 1

TC = int(input())
for tc in range(TC):
    big_list = []
    N = int(input())
    for n in range(N):
        name, sc, c = input().split()
        name = name[:-1]
        big_list.append((name, convert(sc)))

    big_list.sort(key = functools.cmp_to_key(compare))
    for name,c in big_list:
        print(name)

    # print ending line: ======= ...
    for _ in range(30):
        print('-', end = '')
    print()

