# Alice is attempting to type a specific string on her computer. However, she tends to be clumsy and may press a key for too long, resulting in a character being typed multiple times.
# You are given a string word, which represents the final output displayed on Alice's screen. You are also given a positive integer k.
# Return the total number of possible original strings that Alice might have intended to type, if she was trying to type a string of size at least k.
# Since the answer may be very large, return it modulo 109 + 7.
# Example 1:
# Input: word = "aabbccdd", k = 7
# Output: 5
# Explanation:
# The possible strings are: "aabbccdd", "aabbccd", "aabbcdd", "aabccdd", and "abbccdd".
# Example 2:
# Input: word = "aabbccdd", k = 8
# Output: 1
# Explanation:
# The only possible string is "aabbccdd".
# Example 3:
# Input: word = "aaabbb", k = 3
# Output: 8
# Constraints:
# 1 <= word.length <= 5 * 105
# word consists only of lowercase English letters.
# 1 <= k <= 2000

class Solution(object):
    def possibleStringCount(self, word, k):
        """
        :type word: str
        :type k: int
        :rtype: int
        """
        MOD = 10**9 + 7
        
        # Step 1: Split word into groups of consecutive same characters
        from collections import defaultdict
        groups = []
        prev = word[0]
        count = 1
        for c in word[1:]:
            if c == prev:
                count += 1
            else:
                groups.append(count)
                prev = c
                count = 1
        groups.append(count)  # add the last group
        
        m = len(groups)
        
        # Step 2: DP
        # dp[i][j]: number of ways to build first i groups with total length j
        dp = [defaultdict(int) for _ in range(m+1)]
        dp[0][0] = 1  # base case: zero groups and zero length
        
        for i in range(m):
            cnt = groups[i]
            for length in dp[i]:
                for choose in range(1, cnt + 1):
                    new_len = length + choose
                    if new_len > k:
                        continue
                    dp[i+1][new_len] = (dp[i+1][new_len] + dp[i][length]) % MOD
        
        # Step 3: Sum all dp[m][j] where j >= k
        result = 0
        for l in dp[m]:
            if l >= k:
                result = (result + dp[m][l]) % MOD
        
        return result