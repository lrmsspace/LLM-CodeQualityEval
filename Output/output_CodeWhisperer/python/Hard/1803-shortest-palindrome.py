#https://leetcode.com/problems/shortest-palindrome/
#You are given a string s. You can convert s to a palindrome by adding characters in front of it.
#Return the shortest palindrome you can find by performing this transformation.
# 
#Example 1:
#Input: s = "aacecaaa"
#Output: "aaacecaaa"
#Example 2:
#Input: s = "abcd"
#Output: "dcbabcd"
# 
#Constraints:
#	0 <= s.length <= 5 * 104
#	s consists of lowercase English letters only.
class Solution(object):
    def shortestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        if len(s) <= 1:
            return s
        rev_s = s[::-1]
        for i in range(len(s)):
            if s.startswith(rev_s[i:]):
                return rev_s[:i] + s
        return rev_s[:-1] + s
        