# You are given two strings, s and t.
# You can create a new string by selecting a substring from s (possibly empty) and a substring from t (possibly empty), then concatenating them in order.
# Return the length of the longest palindrome that can be formed this way.
# Example 1:
# Input: s = "a", t = "a"
# Output: 2
# Explanation:
# Concatenating "a" from s and "a" from t results in "aa", which is a palindrome of length 2.
# Example 2:
# Input: s = "abc", t = "def"
# Output: 1
# Explanation:
# Since all characters are different, the longest palindrome is any single character, so the answer is 1.
# Example 3:
# Input: s = "b", t = "aaaa"
# Output: 4
# Explanation:
# Selecting "aaaa" from t is the longest palindrome, so the answer is 4.
# Example 4:
# Input: s = "abcde", t = "ecdba"
# Output: 5
# Explanation:
# Concatenating "abc" from s and "ba" from t results in "abcba", which is a palindrome of length 5.
# Constraints:
# 1 <= s.length, t.length <= 1000
# s and t consist of lowercase English letters.

class Solution(object):
    def longestPalindrome(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: int
        """
        def is_palindrome(s, l1, r1, t, l2, r2):
            # 检查两个字符串拼接后是否是回文
            i, j = len(s)-1, 0
            while i >= l1 and j <= r2:
                if s[i] != t[j]:
                    return False
                i -= 1
                j += 1
            return True
        
        m, n = len(s), len(t)
        
        # dp[i][j] 表示以 s[i..m-1] 和 t[0..j] 连接的最长回文子串长度
        dp = [[0]*(n+1) for _ in range(m+1)]
        
        # 初始化：当没有选择s的一部分时，最大回文子串长度为t的最长回文子串
        max_t_palin = 1
        for i in range(n):
            for j in range(i, n):
                if t[i:j+1] == t[i:j+1][::-1]:
                    max_t_palin = max(max_t_palin, j-i+1)
        for i in range(m+1):
            dp[i][n] = max_t_palin
        
        # 动态规划填充dp数组
        for i in range(m-1, -1, -1):
            for j in range(n-1, -1, -1):
                if s[i] == t[j]:
                    # 如果字符相等，可以尝试扩展成回文
                    k = 0
                    while i+k < m and j+k < n and s[i+k] == t[j+k]:
                        k += 1
                    dp[i][j] = 2*k
                    
                    # 尝试在中间插入s或t中的回文
                    mid_palin = 0
                    # 插入s中的回文
                    for p in range(i+k, m):
                        for q in range(p, m):
                            if s[p:q+1] == s[p:q+1][::-1]:
                                mid_palin = max(mid_palin, q-p+1)
                    # 或者插入t中的回文
                    for p in range(j+k, n):
                        for q in range(p, n):
                            if t[p:q+1] == t[p:q+1][::-1]:
                                mid_palin = max(mid_palin, q-p+1)
                    
                    dp[i][j] = max(dp[i][j], dp[i+k][j+k] + 2*k + mid_palin)
                else:
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1])
        
        return dp[0][0]