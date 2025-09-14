#https://leetcode.com/problems/longest-palindrome/
#Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.
#Letters are case sensitive, for example, "Aa" is not considered a palindrome.
# 
#Example 1:
#Input: s = "abccccdd"
#Output: 7
#Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.
#Example 2:
#Input: s = "a"
#Output: 1
#Explanation: The longest palindrome that can be built is "a", whose length is 1.
# 
#Constraints:
#	1 <= s.length <= 2000
#	s consists of lowercase and/or uppercase English letters only.
class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        d = {}
        for i in s:
            if i in d:
                d[i] += 1
            else:
                d[i] = 1
        res = 0
        for i in d:
            res += d[i]//2*2
            if res%2==0 and d[i]%2==1:
                res += 1
        return res