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
        # Initialize a dictionary to store the last index of each character
        last_index = {}
        
        # Initialize variables to store the maximum length and the current index
        max_length = -1
        current_index = 0
        
        # Iterate through the string
        for i, char in enumerate(s):
            # If the character is already in the dictionary
            if char in last_index:
                # Update the current index if it is greater than the last index
                current_index = max(current_index, last_index[char] + 1)
            
            # Update the last index of the character
            last_index[char] = i
            
            # Update the maximum length if it is greater than the current length
            max_length = max(max_length, i - current_index)
        
        # Return the maximum length between two equal characters
        return max_length
        