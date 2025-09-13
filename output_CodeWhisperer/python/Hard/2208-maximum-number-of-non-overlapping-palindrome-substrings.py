#https://leetcode.com/problems/maximum-number-of-non-overlapping-palindrome-substrings/
#You are given a string s and a positive integer k.
#Select a set of non-overlapping substrings from the string s that satisfy the following conditions:
#	The length of each substring is at least k.
#	Each substring is a palindrome.
#Return the maximum number of substrings in an optimal selection.
#A substring is a contiguous sequence of characters within a string.
# 
#Example 1:
#Input: s = "abaccdbbd", k = 3
#Output: 2
#Explanation: We can select the substrings underlined in s = "abaccdbbd". Both "aba" and "dbbd" are palindromes and have a length of at least k = 3.
#It can be shown that we cannot find a selection with more than two valid substrings.
#Example 2:
#Input: s = "adbcda", k = 2
#Output: 0
#Explanation: There is no palindrome substring of length at least 2 in the string.
# 
#Constraints:
#	1 <= k <= s.length <= 2000
#	s consists of lowercase English letters.
class Solution(object):
    def maxPalindromes(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        n = len(s)
        dp = [0] * n
        for mid in range(2 * n - 1):
            l = mid / 2
            r = l + mid % 2
            dp[r] = 0
            while l >= 0 and r < n and s[l] == s[r]:
                if r - l + 1 >= k:
                    dp[r] = max(dp[r], dp[l - 1] + 1)
                l -= 1
                r += 1
        return dp[-1]
        