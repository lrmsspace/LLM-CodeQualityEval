# You are given a binary array nums.
# We call a subarray alternating if no two adjacent elements in the subarray have the same value.
# Return the number of alternating subarrays in nums.
# Example 1:
# Input: nums = [0,1,1,1]
# Output: 5
# Explanation:
# The following subarrays are alternating: [0], [1], [1], [1], and [0,1].
# Example 2:
# Input: nums = [1,0,1,0]
# Output: 10
# Explanation:
# Every subarray of the array is alternating. There are 10 possible subarrays that we can choose.
# Constraints:
# 1 <= nums.length <= 105
# nums[i] is either 0 or 1.

class Solution(object):
    def countAlternatingSubarrays(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        n = len(nums)
        count = 0
        current_length = 0

        for i in range(n):
            if i == 0 or nums[i] != nums[i - 1]:
                current_length += 1
            else:
                current_length = 1

            count += current_length

        return count