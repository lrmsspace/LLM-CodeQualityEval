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
        def count(prefix):
            count, cur = 0, prefix
            while cur <= n:
                count += min(n+1, cur+1) - cur
                cur += prefix
            return count
        prefix = 1
        while k > 1:
            steps = count(prefix)
            if k > steps:
                k -= steps
                prefix += 1
            else:
                k -= 1
                prefix *= 10
        return prefix