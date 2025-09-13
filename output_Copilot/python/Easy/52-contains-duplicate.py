#https://leetcode.com/problems/contains-duplicate/
#Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
# 
#Example 1:
#Input: nums = [1,2,3,1]
#Output: true
#Explanation:
#The element 1 occurs at the indices 0 and 3.
#Example 2:
#Input: nums = [1,2,3,4]
#Output: false
#Explanation:
#All elements are distinct.
#Example 3:
#Input: nums = [1,1,1,3,3,4,3,2,4,2]
#Output: true
# 
#Constraints:
#	1 <= nums.length <= 105
#	-109 <= nums[i] <= 109
class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        # 1. 使用集合来存储已经遍历过的元素
        # 2. 遍历数组中的每个元素
        # 3. 如果当前元素已经在集合中，则返回 True，表示存在重复元素
        # 4. 否则，将当前元素添加到集合中
        # 5. 如果遍历结束后没有找到重复元素，则返回 False

        seen = set()
        for num in nums:
            if num in seen:
                return True
            seen.add(num)
        return False        