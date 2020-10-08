
#this one is wrong
#see version (anagram_counting.py)
#although that one is also not 100% correct lol
#it gives WA in the second test case
# but i still haven't figured out why
# this version 2 is an attempt to redo the anagram_counting.py and hopefully get AC
#TO COMPLETE

import sys

for line in sys.stdin:
    if line == '':
        break

    character_count = {}

    for letter in line:
    # increment character count for that letter
    # for some reason, python considers '\n' and alpha...
    # so, even if we check isalpha(), we need the != '\n' bit
        if (letter != '\n'):
            if ord(letter) in character_count:
                character_count[ord(letter)] += 1
            else:
                character_count[ord(letter)] = 1

    possibilities = 1
    mult = 1

    for num in character_count:
        print(num, end = ' ')

    print()
    #for count in character_count:
     #   original_count = count
      #  while (count > 0):
       #     possibilities *= mult
   #         mult += 1
    #        count -= 1
        # division by letter count because we care about unique solutions
     #   possibilities //= original_count

    #print(possibilities)


