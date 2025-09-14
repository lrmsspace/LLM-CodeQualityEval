#https://leetcode.com/problems/count-number-of-homogenous-substrings/
#Given a string s, return the number of homogenous substrings of s. Since the answer may be too large, return it modulo 109 + 7.
#A string is homogenous if all the characters of the string are the same.
#A substring is a contiguous sequence of characters within a string.
# 
#Example 1:
#Input: s = "abbcccaa"
#Output: 13
#Explanation: The homogenous substrings are listed as below:
#"a"   appears 3 times.
#"aa"  appears 1 time.
#"b"   appears 2 times.
#"bb"  appears 1 time.
#"c"   appears 3 times.
#"cc"  appears 2 times.
#"ccc" appears 1 time.
#3 + 1 + 2 + 1 + 3 + 2 + 1 = 13.
#Example 2:
#Input: s = "xy"
#Output: 2
#Explanation: The homogenous substrings are "x" and "y".
#Example 3:
#Input: s = "zzzzz"
#Output: 15
# 
#Constraints:
#	1 <= s.length <= 105
#	s consists of lowercase letters.
class Solution(object):
    def countHomogenous(self, s):
        """
        :type s: str
        :rtype: int
        """
        MOD = 10**9 + 7
        n = len(s)
        dp = [0] * (n + 1)
        dp[0] = 1
        res = 0
        for i in range(1, n + 1):
            if s[i - 1] == s[i - 2]:
                dp[i] = dp[i - 1] * 2 % MOD
            else:
                dp[i] = dp[i - 1] + 1
            res = (res + dp[i]) % MOD
        return res
        