

#import sys
#while True:
 #   print("TRIAL ONE")
  #  line = sys.stdin.readline()

#wrong, but idk why (see below for a correct version I wrote earlier)
import sys
while True:
    for line in sys.stdin:

        print("eh:" + line + "end")
        if line == '':
            break

        character_count = [0 for i in range(128)]
        for letter in line:
            if (letter.isalpha):
                print(letter)
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




"""
THIS VERSION WORKS (BUT NOT ON KATTIS, SINCE KATTIS REQUIRES STDIN)

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



