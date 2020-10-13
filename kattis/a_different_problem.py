import sys

for line in sys.stdin:

    num1, num2 = line.split(' ')

    diff = abs(int(num1) - int(num2))

    print(diff)
