from typing import List

class Solution:

    # this one is wrong because I sorted the list... When in fact we care about the original indexes
    def wrong_twoSum(self, nums: List[int], target: int) -> List[int]:

        length = len(nums)

        nums.sort()

        i = 0
        j = length - 1

        answers = []

        while i != j:
            if nums[i] + nums[j] == target:
                answers.append(i)
                answers.append(j)
                break
            elif nums[i] + nums[j] < target:
                i += 1
            else:
                j -= 1

        return answers

    def twoSum(self, nums: List[int], target: int) -> List[int]:

        complements = {}
        answer = []

        for i in range(len(nums)):
            complement = target - nums[i]
            if complement in complements.keys():
                compIndex = complements[complement]
                return [compIndex, i]
            complements.update({nums[i] : i})



input1 = [2,7,11,15,9]
input2 = [3,2,4]
input3 = [3,3]
print(Solution().twoSum(input2, 6))



