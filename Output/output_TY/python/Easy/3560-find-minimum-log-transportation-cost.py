# You are given integers n, m, and k.
# There are two logs of lengths n and m units, which need to be transported in three trucks where each truck can carry one log with length at most k units.
# You may cut the logs into smaller pieces, where the cost of cutting a log of length x into logs of length len1 and len2 is cost = len1 * len2 such that len1 + len2 = x.
# Return the minimum total cost to distribute the logs onto the trucks. If the logs don't need to be cut, the total cost is 0.
# Example 1:
# Input: n = 6, m = 5, k = 5
# Output: 5
# Explanation:
# Cut the log with length 6 into logs with length 1 and 5, at a cost equal to 1 * 5 == 5. Now the three logs of length 1, 5, and 5 can fit in one truck each.
# Example 2:
# Input: n = 4, m = 4, k = 6
# Output: 0
# Explanation:
# The two logs can fit in the trucks already, hence we don't need to cut the logs.
# Constraints:
# 2 <= k <= 105
# 1 <= n, m <= 2 * k
# The input is generated such that it is always possible to transport the logs.

class Solution(object):
    def minCuttingCost(self, n, m, k):
        """
        :type n: int
        :type m: int
        :type k: int
        :rtype: int
        """
        # 如果两个日志都不需要切割，总成本为0
        if n <= k and m <= k:
            return 0
        
        # 如果只有一个日志超过k，则只需要切一次
        if (n > k and m <= k) or (n <= k and m > k):
            return n * 2 if n > k else m * 2
        
        # 如果两个日志都需要切割，则选择最小的切割成本
        return n + m - k