import sys

# takes in an int and an int list
def is_jolly(n, nums):
    prev = nums[0]
    st = set()
    for num in nums[1:]:
        diff = abs(prev - num)
        if diff < 1:
            return False
        if diff > (n-1):
            return False
        if diff in st:
            return False
        st.add(diff)
        prev = num
    return True

for line in sys.stdin:
    line = list(map(int,line.split()))
    n = line[0]
    nums = line[1:]
    #for i in nums:
    #    print(i)
    if is_jolly(n, nums):
        print("Jolly")
    else:
        print("Not jolly")
