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
        # Build the reverse of s
        rev_s = s[::-1]
        
        # Find the longest common prefix between s and its reverse
        prefix = ""
        for i in range(len(s)):
            if s[:i+1] == rev_s[i:]:
                prefix = s[:i+1]
                break
        
        # Add the remaining characters of s in reverse order to form the shortest palindrome
        return rev_s + s[len(prefix):][::-1]
        