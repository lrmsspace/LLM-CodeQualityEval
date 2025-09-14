#https://leetcode.com/problems/palindromic-substrings/
#Given a string s, return the number of palindromic substrings in it.
#A string is a palindrome when it reads the same backward as forward.
#A substring is a contiguous sequence of characters within the string.
# 
#Example 1:
#Input: s = "abc"
#Output: 3
#Explanation: Three palindromic strings: "a", "b", "c".
#Example 2:
#Input: s = "aaa"
#Output: 6
#Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
# 
#Constraints:
#	1 <= s.length <= 1000
#	s consists of lowercase English letters.
class Solution(object):
    def countSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        count = 0
        for i in range(len(s)):
            count += self.palindrome_count(s, i, i) + self.palindrome_count(s, i, i + 1)
        return count
    
    def palindrome_count(self, s, start, end):
        count = 0
        while start >= 0 and end < len(s) and s[start] == s[end]:
            count += 1
            start -= 1
            end += 1
        return count
