#https://leetcode.com/problems/number-of-beautiful-partitions/
#You are given a string s that consists of the digits '1' to '9' and two integers k and minLength.
#A partition of s is called beautiful if:
#	s is partitioned into k non-intersecting substrings.
#	Each substring has a length of at least minLength.
#	Each substring starts with a prime digit and ends with a non-prime digit. Prime digits are '2', '3', '5', and '7', and the rest of the digits are non-prime.
#Return the number of beautiful partitions of s. Since the answer may be very large, return it modulo 109 + 7.
#A substring is a contiguous sequence of characters within a string.
# 
#Example 1:
#Input: s = "23542185131", k = 3, minLength = 2
#Output: 3
#Explanation: There exists three ways to create a beautiful partition:
#"2354 | 218 | 5131"
#"2354 | 21851 | 31"
#"2354218 | 51 | 31"
#Example 2:
#Input: s = "23542185131", k = 3, minLength = 3
#Output: 1
#Explanation: There exists one way to create a beautiful partition: "2354 | 218 | 5131".
#Example 3:
#Input: s = "3312958", k = 3, minLength = 1
#Output: 1
#Explanation: There exists one way to create a beautiful partition: "331 | 29 | 58".
# 
#Constraints:
#	1 <= k, minLength <= s.length <= 1000
#	s consists of the digits '1' to '9'.
class Solution(object):
    def beautifulPartitions(self, s, k, minLength):
        """
        :type s: str
        :type k: int
        :type minLength: int
        :rtype: int
        """
        # 质数数字集合
        prime_digits = {'2', '3', '5', '7'}
        # 非质数数字集合
        non_prime_digits = {'1', '4', '6', '8', '9'}
        # 模数
        mod = 10**9 + 7

        # 获取字符串长度
        n = len(s)
        # 初始化动态规划数组 dp，大小为 (n+1) x (k+1)
        dp = [[0] * (k + 1) for _ in range(n + 1)]
        # 初始化前缀和数组 prefix_sum，大小为 (n+1) x (k+1)
        prefix_sum = [[0] * (k + 1) for _ in range(n + 1)]

        # 设置初始条件：dp[0][0] = 1，表示空字符串可以分成0个子串
        dp[0][0] = 1

        # 遍历每个字符位置 i，从 1 到 n
        for i in range(1, n + 1):
            # 遍历每个子串数量 j，从 1 到 k
            for j in range(1, k + 1):
                # 遍历每个可能的起始位置 p，从 i - minLength 到 i - 1
                for p in range(i - minLength, i):
                    # 检查当前子串是否满足条件：以质数数字开头，以非质数数字结尾
                    if s[p] in prime_digits and s[i - 1] in non_prime_digits:
                        # 更新 dp[i][j]，表示将前 i 个字符分成 j 个子串的方案数
                        dp[i][j] += dp[p][j - 1]
                        dp[i][j] %= mod

            # 更新前缀和数组 prefix_sum，用于快速计算区间和
            for j in range(k + 1):
                prefix_sum[i][j] = (prefix_sum[i - 1][j] + dp[i][j]) % mod

        # 返回结果：将整个字符串分成 k 个子串的方案数
        return dp[n][k]        