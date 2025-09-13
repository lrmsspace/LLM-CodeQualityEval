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
        def count_steps(n, prefix):
            cur = prefix
            next_prefix = prefix + 1
            steps = 0
            while cur <= n:
                steps += min(n + 1, next_prefix) - cur
                cur *= 10
                next_prefix *= 10
            return steps

        prefix = 1
        k -= 1      
        while k > 0:
            steps = count_steps(n, prefix)
            if steps <= k:
                prefix += 1
                k -= steps
            else:
                prefix *= 10
                k -= 1
        return prefix  