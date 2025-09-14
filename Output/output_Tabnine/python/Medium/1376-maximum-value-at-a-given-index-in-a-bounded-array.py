#https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/
#You are given three positive integers: n, index, and maxSum. You want to construct an array nums (0-indexed) that satisfies the following conditions:
#	nums.length == n
#	nums[i] is a positive integer where 0 <= i < n.
#	abs(nums[i] - nums[i+1]) <= 1 where 0 <= i < n-1.
#	The sum of all the elements of nums does not exceed maxSum.
#	nums[index] is maximized.
#Return nums[index] of the constructed array.
#Note that abs(x) equals x if x >= 0, and -x otherwise.
# 
#Example 1:
#Input: n = 4, index = 2,  maxSum = 6
#Output: 2
#Explanation: nums = [1,2,2,1] is one array that satisfies all the conditions.
#There are no arrays that satisfy all the conditions and have nums[2] == 3, so 2 is the maximum nums[2].
#Example 2:
#Input: n = 6, index = 1,  maxSum = 10
#Output: 3
# 
#Constraints:
#	1 <= n <= maxSum <= 109
#	0 <= index < n
class Solution(object):
    def maxValue(self, n, index, maxSum):
        """
        :type n: int
        :type index: int
        :type maxSum: int
        :rtype: int
        """
        # If maxSum is less than n, it's impossible to construct an array with nums[index] maximized
        if maxSum < n:
            return -1
        
        # Calculate the minimum and maximum values for nums[index]
        min_val = maxSum - (n - 1) * 2
        max_val = maxSum - index * 2
        
        # If the minimum value is greater than the maximum value, it's impossible to construct an array with nums[index] maximized
        if min_val > max_val:
            return -1
        
        # If the minimum value is less than 0, it means we can't use any negative numbers, so we'll use the maximum value
        if min_val < 0:
            min_val = 0
        
        # Return the maximum value for nums[index]
        return max_val