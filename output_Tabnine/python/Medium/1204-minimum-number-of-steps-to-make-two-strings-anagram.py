#https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/
#You are given two strings of the same length s and t. In one step you can choose any character of t and replace it with another character.
#Return the minimum number of steps to make t an anagram of s.
#An Anagram of a string is a string that contains the same characters with a different (or the same) ordering.
# 
#Example 1:
#Input: s = "bab", t = "aba"
#Output: 1
#Explanation: Replace the first 'a' in t with b, t = "bba" which is anagram of s.
#Example 2:
#Input: s = "leetcode", t = "practice"
#Output: 5
#Explanation: Replace 'p', 'r', 'a', 'i' and 'c' from t with proper characters to make t anagram of s.
#Example 3:
#Input: s = "anagram", t = "mangaar"
#Output: 0
#Explanation: "anagram" and "mangaar" are anagrams. 
# 
#Constraints:
#	1 <= s.length <= 5 * 104
#	s.length == t.length
#	s and t consist of lowercase English letters only.
class Solution(object):
    def minSteps(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: int
        """
        # Count the frequency of each character in both strings
        freq_s = [0] * 26
        freq_t = [0] * 26
        
        for char in s:
            freq_s[ord(char) - ord('a')] += 1
        
        for char in t:
            freq_t[ord(char) - ord('a')] += 1
        
        # Calculate the difference in frequency of each character
        steps = 0
        for i in range(26):
            steps += abs(freq_s[i] - freq_t[i])
        
        return steps
        