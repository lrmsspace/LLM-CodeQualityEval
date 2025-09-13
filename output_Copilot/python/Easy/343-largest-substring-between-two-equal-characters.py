#https://leetcode.com/problems/largest-substring-between-two-equal-characters/
#Given a string s, return the length of the longest substring between two equal characters, excluding the two characters. If there is no such substring return -1.
#A substring is a contiguous sequence of characters within a string.
# 
#Example 1:
#Input: s = "aa"
#Output: 0
#Explanation: The optimal substring here is an empty substring between the two 'a's.
#Example 2:
#Input: s = "abca"
#Output: 2
#Explanation: The optimal substring here is "bc".
#Example 3:
#Input: s = "cbzxy"
#Output: -1
#Explanation: There are no characters that appear twice in s.
# 
#Constraints:
#	1 <= s.length <= 300
#	s contains only lowercase English letters.
class Solution(object):
    def maxLengthBetweenEqualCharacters(self, s):
        """
        :type s: str
        :rtype: int
        """
        # Initialize a dictionary to store the first occurrence of each character
        char_indices = {}
        max_length = -1   
        # Iterate through the string
        for i, char in enumerate(s):
            # If the character is already in the dictionary, calculate the length of the substring
            if char in char_indices:
                length = i - char_indices[char] - 1
                max_length = max(max_length, length)  
            else:
                # Store the index of the first occurrence of the character
                char_indices[char] = i
        return max_length     