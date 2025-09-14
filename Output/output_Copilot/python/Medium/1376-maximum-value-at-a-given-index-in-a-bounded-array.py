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
        # 二分查找的边界条件
        left = 1
        right = maxSum

        while left < right:
            mid = (left + right + 1) // 2

            # 计算当前 mid 值下的数组和
            total = mid * n - (mid * (mid - 1) // 2) - ((mid - 1) * (mid - 1) // 2)

            # 如果 index 在前半部分，计算前半部分的和
            if index < n // 2:
                total -= (index * (index + 1)) // 2
            else:
                total -= ((n - index - 1) * (n - index)) // 2

            # 如果总和大于 maxSum，说明 mid 值过大，需要减小范围
            if total > maxSum:
                right = mid - 1
            else:
                left = mid

        return left        