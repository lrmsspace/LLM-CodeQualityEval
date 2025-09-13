#https://leetcode.com/problems/length-of-the-longest-alphabetical-continuous-substring/
#An alphabetical continuous string is a string consisting of consecutive letters in the alphabet. In other words, it is any substring of the string "abcdefghijklmnopqrstuvwxyz".
#	For example, "abc" is an alphabetical continuous string, while "acb" and "za" are not.
#Given a string s consisting of lowercase letters only, return the length of the longest alphabetical continuous substring.
# 
#Example 1:
#Input: s = "abacaba"
#Output: 2
#Explanation: There are 4 distinct continuous substrings: "a", "b", "c" and "ab".
#"ab" is the longest continuous substring.
#Example 2:
#Input: s = "abcde"
#Output: 5
#Explanation: "abcde" is the longest continuous substring.
# 
#Constraints:
#	1 <= s.length <= 105
#	s consists of only English lowercase letters.
class Solution(object):
    def longestContinuousSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        max_length = 0
        current_length = 0
        last_letter = None
        
        for letter in s:
            if letter.isalpha() and (last_letter is None or letter.lower() == last_letter.lower() + 1):
                current_length += 1
            else:
                current_length = 1
            max_length = max(max_length, current_length)
            last_letter = letter
        
        return max_length
        