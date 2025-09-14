#https://leetcode.com/problems/single-number/
#Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
#You must implement a solution with a linear runtime complexity and use only constant extra space.
# 
#Example 1:
#Input: nums = [2,2,1]
#Output: 1
#Example 2:
#Input: nums = [4,1,2,1,2]
#Output: 4
#Example 3:
#Input: nums = [1]
#Output: 1
# 
#Constraints:
#	1 <= nums.length <= 3 * 104
#	-3 * 104 <= nums[i] <= 3 * 104
#	Each element in the array appears twice except for one element which appears only once.
class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # 1. 使用集合存储元素
        # 2. 遍历数组中的每个元素
        # 3. 如果元素在集合中，说明它是重复的，删除它
        # 4. 如果元素不在集合中，说明它是唯一的，添加到集合中
        # 5. 最后，集合中只会剩下一个元素，即为所求的唯一元素
        unique_elements = set()
        for num in nums:
            if num in unique_elements:
                unique_elements.remove(num)
            else:
                unique_elements.add(num)
        return unique_elements.pop() if unique_elements else None        