#https://leetcode.com/problems/optimal-partition-of-string/
#Given a string s, partition the string into one or more substrings such that the characters in each substring are unique. That is, no letter appears in a single substring more than once.
#Return the minimum number of substrings in such a partition.
#Note that each character should belong to exactly one substring in a partition.
# 
#Example 1:
#Input: s = "abacaba"
#Output: 4
#Explanation:
#Two possible partitions are ("a","ba","cab","a") and ("ab","a","ca","ba").
#It can be shown that 4 is the minimum number of substrings needed.
#Example 2:
#Input: s = "ssssss"
#Output: 6
#Explanation:
#The only valid partition is ("s","s","s","s","s","s").
# 
#Constraints:
#	1 <= s.length <= 105
#	s consists of only English lowercase letters.
class Solution(object):
    def partitionString(self, s):
        """
        :type s: str
        :rtype: int
        """
        # Create a dictionary to store the frequency of each character
        freq = {}
        for char in s:
            freq[char] = freq.get(char, 0) + 1
        
        # Initialize the minimum number of substrings and current substring length
        min_substrings = len(s)
        current_length = 0
        
        # Iterate through the characters in the string
        for char in s:
            # Update the frequency of the current character
            freq[char] -= 1
            
            # If the frequency of the current character becomes zero, it means we have found a substring
            if freq[char] == 0:
                # Update the minimum number of substrings
                min_substrings = min(min_substrings, current_length + 1)
            
            # Update the current substring length
            current_length += 1
        
        return min_substrings
        