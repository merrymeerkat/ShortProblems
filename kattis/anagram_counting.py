import sys
while True:
    for line in sys.stdin:
        if line == '':
            break

        character_count = [0 for i in range(128)]

        for letter in line:
        # increment character count for that letter
        # for some reason, python considers '\n' and alpha...
        # so, even if we check isalpha(), we need the != '\n' bit
            if (letter != '\n'):
                character_count[ord(letter) - 1]+=1

        possibilities = 1
        mult = 1

        for count in character_count:
            if count == 0:
                continue

            original_count = count
            while (count > 0):
                possibilities *= mult
                mult += 1
                count -= 1
            # division by letter count because we care about unique solutions
            possibilities //= original_count

        print(possibilities)




"""
THIS VERSION WORKS AS WELL (BUT NOT ON KATTIS, SINCE KATTIS REQUIRES STDIN)

while True:
    line = input()
    if line:

        character_count = [0 for i in range(128)]
        for letter in line:
            character_count[ord(letter) - 1]+=1
        possibilities = 1
        mult = 1
        for count in character_count:
            if count == 0:
                continue

            original_count = count
            while (count > 0):
                possibilities *= mult
                mult += 1
                count -= 1

            possibilities //= original_count

        print(possibilities)
    else:
        break
"""



