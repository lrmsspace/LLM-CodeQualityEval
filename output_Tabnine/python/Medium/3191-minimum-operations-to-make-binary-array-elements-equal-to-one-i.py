# You are given a binary array nums.
# You can do the following operation on the array any number of times (possibly zero):
# Choose any 3 consecutive elements from the array and flip all of them.
# Flipping an element means changing its value from 0 to 1, and from 1 to 0.
# Return the minimum number of operations required to make all elements in nums equal to 1. If it is impossible, return -1.
# Example 1:
# Input: nums = [0,1,1,1,0,0]
# Output: 3
# Explanation:
# We can do the following operations:
# Choose the elements at indices 0, 1 and 2. The resulting array is nums = [1,0,0,1,0,0].
# Choose the elements at indices 1, 2 and 3. The resulting array is nums = [1,1,1,0,0,0].
# Choose the elements at indices 3, 4 and 5. The resulting array is nums = [1,1,1,1,1,1].
# Example 2:
# Input: nums = [0,1,1,1]
# Output: -1
# Explanation:
# It is impossible to make all elements equal to 1.
# Constraints:
# 3 <= nums.length <= 105
# 0 <= nums[i] <= 1

class Solution(object):
    def minOperations(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        ones = sum(nums)
        if ones == 0:
            return 0
        if ones % 3!= 0:
            return -1
        
        target = ones // 3
        left, right = 0, n - 1
        ans = 0
        
        while left < right:
            if nums[left] == target:
                left += 1
            elif nums[right] == target:
                right -= 1
            else:
                nums[left], nums[right] = nums[right], nums[left]
                ans += 1
                left += 1
                right -= 1
        
        return ans + (ones - 3 * target) % 2
        