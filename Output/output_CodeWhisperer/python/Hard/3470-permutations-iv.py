# Given two integers, n and k, an alternating permutation is a permutation of the first n positive integers such that no two adjacent elements are both odd or both even.
# Return the k-th alternating permutation sorted in lexicographical order. If there are fewer than k valid alternating permutations, return an empty list.
# Example 1:
# Input: n = 4, k = 6
# Output: [3,4,1,2]
# Explanation:
# The lexicographically-sorted alternating permutations of [1, 2, 3, 4] are:
# [1, 2, 3, 4]
# [1, 4, 3, 2]
# [2, 1, 4, 3]
# [2, 3, 4, 1]
# [3, 2, 1, 4]
# [3, 4, 1, 2] ← 6th permutation
# [4, 1, 2, 3]
# [4, 3, 2, 1]
# Since k = 6, we return [3, 4, 1, 2].
# Example 2:
# Input: n = 3, k = 2
# Output: [3,2,1]
# Explanation:
# The lexicographically-sorted alternating permutations of [1, 2, 3] are:
# [1, 2, 3]
# [3, 2, 1] ← 2nd permutation
# Since k = 2, we return [3, 2, 1].
# Example 3:
# Input: n = 2, k = 3
# Output: []
# Explanation:
# The lexicographically-sorted alternating permutations of [1, 2] are:
# [1, 2]
# [2, 1]
# There are only 2 alternating permutations, but k = 3, which is out of range. Thus, we return an empty list [].
# Constraints:
# 1 <= n <= 100
# 1 <= k <= 1015

class Solution(object):
    def permute(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[int]
        """
        MOD = 10**9 + 7
        dp = [[0] * (n + 1) for _ in range(n + 1)]
        dp[0][0] = 1
        for i in range(1, n + 1):
            for j in range(i + 1):
                if j == 0:
                    dp[i][j] = dp[i - 1][j + 1]
                elif j == i:
                    dp[i][j] = dp[i - 1][j - 1]
                else:
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD
        return dp[n][k] if k <= n else 0
    
        