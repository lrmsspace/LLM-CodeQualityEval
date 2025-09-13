#https://leetcode.com/problems/longest-nice-substring/
#A string s is nice if, for every letter of the alphabet that s contains, it appears both in uppercase and lowercase. For example, "abABB" is nice because 'A' and 'a' appear, and 'B' and 'b' appear. However, "abA" is not because 'b' appears, but 'B' does not.
#Given a string s, return the longest substring of s that is nice. If there are multiple, return the substring of the earliest occurrence. If there are none, return an empty string.
# 
#Example 1:
#Input: s = "YazaAay"
#Output: "aAa"
#Explanation: "aAa" is a nice string because 'A/a' is the only letter of the alphabet in s, and both 'A' and 'a' appear.
#"aAa" is the longest nice substring.
#Example 2:
#Input: s = "Bb"
#Output: "Bb"
#Explanation: "Bb" is a nice string because both 'B' and 'b' appear. The whole string is a substring.
#Example 3:
#Input: s = "c"
#Output: ""
#Explanation: There are no nice substrings.
# 
#Constraints:
#	1 <= s.length <= 100
#	s consists of uppercase and lowercase English letters.
class Solution(object):
    def longestNiceSubstring(self, s):
        """
        :type s: str
        :rtype: str
        """
        # Create two sets for uppercase and lowercase letters
        upper = set(chr(i) for i in range(ord('A'), ord('Z')+1))
        lower = set(chr(i) for i in range(ord('a'), ord('z')+1))
        
        # Initialize result variables
        start, end = 0, 0
        max_len = 0
        
        # Iterate through the string
        while end < len(s):
            # If the current character is in both upper and lower sets, update the result variables
            if s[end] in upper and s[end] in lower:
                start = max(start, end - max_len + 1)
                max_len = end - start + 1
            end += 1
        
        # Return the longest nice substring
        return s[start:start+max_len]
        