# You are given an array of positive integers nums and an integer k.
# You may perform at most k operations. In each operation, you can choose one element in the array and double its value. Each element can be doubled at most once.
# The score of a contiguous subarray is defined as the product of its length and the greatest common divisor (GCD) of all its elements.
# Your task is to return the maximum score that can be achieved by selecting a contiguous subarray from the modified array.
# Note:
# The greatest common divisor (GCD) of an array is the largest integer that evenly divides all the array elements.
# Example 1:
# Input: nums = [2,4], k = 1
# Output: 8
# Explanation:
# Double nums[0] to 4 using one operation. The modified array becomes [4, 4].
# The GCD of the subarray [4, 4] is 4, and the length is 2.
# Thus, the maximum possible score is 2 × 4 = 8.
# Example 2:
# Input: nums = [3,5,7], k = 2
# Output: 14
# Explanation:
# Double nums[2] to 14 using one operation. The modified array becomes [3, 5, 14].
# The GCD of the subarray [14] is 14, and the length is 1.
# Thus, the maximum possible score is 1 × 14 = 14.
# Example 3:
# Input: nums = [5,5,5], k = 1
# Output: 15
# Explanation:
# The subarray [5, 5, 5] has a GCD of 5, and its length is 3.
# Since doubling any element doesn't improve the score, the maximum score is 3 × 5 = 15.
# Constraints:
# 1 <= n == nums.length <= 1500
# 1 <= nums[i] <= 109
# 1 <= k <= n

class Solution(object):
    def maxGCDScore(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        from math import gcd
        from collections import defaultdict
        
        n = len(nums)
        max_score = 0
        
        # Precompute GCDs for all subarrays
        gcds = defaultdict(int)
        
        for i in range(n):
            current_gcd = nums[i]
            for j in range(i, n):
                current_gcd = gcd(current_gcd, nums[j])
                length = j - i + 1
                gcds[(i, j)] = current_gcd * length
        
        # Try doubling each element and calculate the maximum score
        for i in range(n):
            original_value = nums[i]
            nums[i] *= 2
            
            # Recompute GCDs after doubling
            for j in range(n):
                if j >= i:
                    current_gcd = nums[i]
                    for k in range(j, n):
                        current_gcd = gcd(current_gcd, nums[k])
                        length = k - j + 1
                        max_score = max(max_score, current_gcd * length)
            
            # Restore the original value
            nums[i] = original_value
        
        return max_score
        