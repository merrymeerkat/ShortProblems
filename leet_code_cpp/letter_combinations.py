

mapping = ["abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]

numbers = str(input())

lenght = len(numbers)

# Remove 1 from list (1 does not map to anything)
numbers = numbers.replace('1', '')

def trial5(numbers, answers):

    element = numbers[0]
    letters = mapping[int(element) - 2]

    #if this is the first time
    if answers == []:
        answers = list(letters)

    else:
        answers *= len(letters)
        idx = 0
        for letter in letters:
            for i in range(len(answers)/len(letters)):
                answers[idx] += letter
                idx += 1

    if len(numbers) == 1:
        return answers

    else:
       return trial5(numbers[1:], answers)


answers = trial5(numbers, [])
print(answers)
