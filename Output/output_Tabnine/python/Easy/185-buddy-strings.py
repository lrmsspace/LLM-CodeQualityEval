#https://leetcode.com/problems/buddy-strings/
#Given two strings s and goal, return true if you can swap two letters in s so the result is equal to goal, otherwise, return false.
#Swapping letters is defined as taking two indices i and j (0-indexed) such that i != j and swapping the characters at s[i] and s[j].
#	For example, swapping at indices 0 and 2 in "abcd" results in "cbad".
# 
#Example 1:
#Input: s = "ab", goal = "ba"
#Output: true
#Explanation: You can swap s[0] = 'a' and s[1] = 'b' to get "ba", which is equal to goal.
#Example 2:
#Input: s = "ab", goal = "ab"
#Output: false
#Explanation: The only letters you can swap are s[0] = 'a' and s[1] = 'b', which results in "ba" != goal.
#Example 3:
#Input: s = "aa", goal = "aa"
#Output: true
#Explanation: You can swap s[0] = 'a' and s[1] = 'a' to get "aa", which is equal to goal.
# 
#Constraints:
#	1 <= s.length, goal.length <= 2 * 104
#	s and goal consist of lowercase letters.
class Solution(object):
    def buddyStrings(self, s, goal):
        """
        :type s: str
        :type goal: str
        :rtype: bool
        """
        # If the strings are not equal, they cannot be buddy swaps
        if s!= goal:
            return False
        
        # Count the frequency of each character in the strings
        freq = [0] * 26
        for c in s:
            freq[ord(c) - ord('a')] += 1
        
        # If the strings have different lengths or if there are more than two distinct characters, they cannot be buddy swaps
        if len(s)!= len(goal) or freq.count(1) > 2:
            return False
        
        # Find two characters that differ in the strings
        i, j = -1, -1
        for k in range(len(s)):
            if s[k]!= goal[k]:
                if i == -1:
                    i = k
                else:
                    j = k
                    break
        
        # If no two characters differ, they cannot be buddy swaps
        if i == -1:
            return False
        
        # If the characters at indices i and j differ, they are a possible buddy swap
        return s[i] == goal[j] and s[j] == goal[i]
        