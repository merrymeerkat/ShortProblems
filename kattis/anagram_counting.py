import sys
import typing

memo = [-1 for _ in range(120)]
def fact(n : int) -> int:
    if n == 1:
        return 1

    if memo[n] !=  -1:
        return memo[n]

    else:
        memo[n] = n * fact(n-1)
        return memo[n]


for word in sys.stdin:
    if word == '':
        break

    l = len(word) - 1
    #print(f'word is {word[:-1]} test')

    count = [0 for _ in range(128)]
    for letter in word[:-1]:
        count[ord(letter) - 1] += 1

    res = fact(l)
    for num in count:
        if num > 1:
            res = res // (fact (num))

    print(int(res))


