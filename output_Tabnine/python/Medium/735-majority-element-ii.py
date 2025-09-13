#https://leetcode.com/problems/majority-element-ii/
#Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
# 
#Example 1:
#Input: nums = [3,2,3]
#Output: [3]
#Example 2:
#Input: nums = [1]
#Output: [1]
#Example 3:
#Input: nums = [1,2]
#Output: [1,2]
# 
#Constraints:
#	1 <= nums.length <= 5 * 104
#	-109 <= nums[i] <= 109
# 
#Follow up: Could you solve the problem in linear time and in O(1) space?
class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        if len(nums) == 1:
            return nums
        
        candidate1, candidate2, count1, count2 = 0, 0, 0, 0
        for num in nums:
            if num == candidate1:
                count1 += 1
            elif num == candidate2:
                count2 += 1
            elif count1 == 0:
                candidate1 = num
                count1 = 1
            elif count2 == 0:
                candidate2 = num
                count2 = 1
            else:
                count1 -= 1
                count2 -= 1
        
        result = []
        for num in [candidate1, candidate2]:
            if nums.count(num) > len(nums) // 3:
                result.append(num)
        
        return result
        