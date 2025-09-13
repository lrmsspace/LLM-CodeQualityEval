#https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences/
#Given a string s, return true if s is a good string, or false otherwise.
#A string s is good if all the characters that appear in s have the same number of occurrences (i.e., the same frequency).
# 
#Example 1:
#Input: s = "abacbc"
#Output: true
#Explanation: The characters that appear in s are 'a', 'b', and 'c'. All characters occur 2 times in s.
#Example 2:
#Input: s = "aaabb"
#Output: false
#Explanation: The characters that appear in s are 'a' and 'b'.
#'a' occurs 3 times while 'b' occurs 2 times, which is not the same number of times.
# 
#Constraints:
#	1 <= s.length <= 1000
#	s consists of lowercase English letters.
class Solution(object):
    def areOccurrencesEqual(self, s):
        """
        :type s: str
        :rtype: bool
        """
        # Count the occurrences of each character in the string
        char_count = {}
        for char in s:
            char_count[char] = char_count.get(char, 0) + 1
        
        # Check if all characters have the same number of occurrences
        return all(count == char_count[char] for char, count in char_count.items())
        