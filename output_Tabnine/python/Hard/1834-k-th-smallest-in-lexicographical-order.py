#https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/
#Given two integers n and k, return the kth lexicographically smallest integer in the range [1, n].
# 
#Example 1:
#Input: n = 13, k = 2
#Output: 10
#Explanation: The lexicographical order is [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9], so the second smallest number is 10.
#Example 2:
#Input: n = 1, k = 1
#Output: 1
# 
#Constraints:
#	1 <= k <= n <= 109
class Solution(object):
    def findKthNumber(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: int
        """
        def count_smaller(x):
            count = 0
            for i in range(1, n+1):
                count += min(i // x, n // i)
            return count
        
        left, right = 1, n
        while left < right:
            mid = left + (right - left) // 2
            if count_smaller(mid) >= k:
                right = mid
            else:
                left = mid + 1
        return left
        