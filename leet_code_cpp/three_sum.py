from typing import List

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:

        answers = []

        length = len(nums)

        nums.sort()

        for p2 in range(length - 2):

            # Skip duplicates
            if p2 > 0 and nums[p2] == nums[p2-1]:
                continue

            p1 = p2 + 1
            p3 = length - 1
            while (p1 < p3):
                num1 = nums[p1]
                num2 = nums[p2]
                num3 = nums[p3]
                if (num1 + num2 + num3 == 0):
                    if p1 != p2 != p3:
                        answers.append([num1, num2, num3])
                    p1 += 1
                    p3 -= 1
                elif (num1 + num2 + num3 < 0):
                    p1 += 1
                else:
                    p3 -= 1

        # Remove duplicates
        #not sure why this one doesn't work
        #for i in range(length - 1):
         #   for j in range(i + 1, length -1):
          #      if (answers[i] == answers[j]):
           #         answers.pop(i)


        # Remove duplicates from answers
        final_answer = []
        for answer in answers:
            if answer not in final_answer:
                final_answer.append(answer)

        return final_answer

nums1 = [-1,0,1,2,-1,-4]
nums2 = []
nums3 = [0]
print(Solution().threeSum(nums1))
