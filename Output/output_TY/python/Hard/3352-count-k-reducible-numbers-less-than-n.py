# You are given a binary string s representing a number n in its binary form.
# You are also given an integer k.
# An integer x is called k-reducible if performing the following operation at most k times reduces it to 1:
# Replace x with the count of set bits in its binary representation.
# For example, the binary representation of 6 is "110". Applying the operation once reduces it to 2 (since "110" has two set bits). Applying the operation again to 2 (binary "10") reduces it to 1 (since "10" has one set bit).
# Return an integer denoting the number of positive integers less than n that are k-reducible.
# Since the answer may be too large, return it modulo 109 + 7.
# Example 1:
# Input: s = "111", k = 1
# Output: 3
# Explanation: 
# n = 7. The 1-reducible integers less than 7 are 1, 2, and 4.
# Example 2:
# Input: s = "1000", k = 2
# Output: 6
# Explanation:
# n = 8. The 2-reducible integers less than 8 are 1, 2, 3, 4, 5, and 6.
# Example 3:
# Input: s = "1", k = 3
# Output: 0
# Explanation:
# There are no positive integers less than n = 1, so the answer is 0.
# Constraints:
# 1 <= s.length <= 800
# s has no leading zeros.
# s consists only of the characters '0' and '1'.
# 1 <= k <= 5

class Solution(object):
    def countKReducibleNumbers(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        MOD = 10**9 + 7
        
        # 预处理所有可能的数字长度的中间结果
        from collections import defaultdict
        level_counts = defaultdict(int)
        
        # 对于1到最大可能值（由s长度决定）进行预处理
        max_len = len(s)
        max_val = 1 << (max_len + 1)
        
        # 计算一个数x经过多少步操作可以变成1
        def get_steps(x):
            steps = 0
            while x > 1:
                x = bin(x).count('1')
                steps += 1
                if steps > k:
                    break
            return steps <= k
            
        # 预计算所有可能的数字的步骤
        step_map = {}
        for i in range(1, max_len + 2):
            step_map[i] = get_steps(i)
        
        # 使用动态规划计算小于n且满足条件的数的数量
        n = int(s, 2)
        count = 0
        
        # dp[i][j] 表示前i位中有j个set bits的方法数
        dp = [[0] * (len(s)+1) for _ in range(len(s)+1)]
        dp[0][0] = 1
        
        for i in range(len(s)):
            bit = int(s[i])
            for j in range(i+1):
                if dp[i][j]:
                    # 放0的情况
                    dp[i+1][j] = (dp[i+1][j] + dp[i][j]) % MOD
                    
                    # 放1的情况
                    if bit == 1:
                        dp[i+1][j+1] = (dp[i+1][j+1] + dp[i][j]) % MOD
        
        # 计算所有可能的结果
        result = 0
        for i in range(1, len(s)+1):
            for j in range(1, len(s)+1):
                if step_map[j]:
                    result = (result + dp[i][j]) % MOD
        
        return result