#https://leetcode.com/problems/repeated-substring-pattern/
#Given a string s, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.
# 
#Example 1:
#Input: s = "abab"
#Output: true
#Explanation: It is the substring "ab" twice.
#Example 2:
#Input: s = "aba"
#Output: false
#Example 3:
#Input: s = "abcabcabcabc"
#Output: true
#Explanation: It is the substring "abc" four times or the substring "abcabc" twice.
# 
#Constraints:
#	1 <= s.length <= 104
#	s consists of lowercase English letters.
class Solution(object):
    def repeatedSubstringPattern(self, s):
        """
        :type s: str
        :rtype: bool
        """
        for i in range(1, len(s)//2+1):
            if len(s)%i==0 and s[:i]*len(s)//i==s:
                return True
        return False