from typing import List

class Solution:
    def letterCombinations(self, digits: str) -> List[str]:

        # Remove 1 from list (1 does not map to anything)
        digits = digits.replace('1', '')

        answers = []

        for i in range(len(digits)):
            digits, answers = helper(digits, answers)

        return answers

def helper(digits, answers):

    mapping = ["abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]

    element = digits[0]
    letters = mapping[int(element) - 2]

            #if this is the first time
    if answers == []:
       answers = list(letters)

    else:
        answers *= len(letters)
        idx = 0
        for letter in letters:
            for i in range(int(len(answers)/len(letters))):
                answers[idx] += letter
                idx += 1

    return digits[1:], answers
   # if len(digits) == 1:
    #   return answers

   # else:
    #   return letterCombinations(digits[1:], answers)

print(Solution().letterCombinations("234"))


print(helper("23", []))

test_str = "23"
print(test_str[1:])
