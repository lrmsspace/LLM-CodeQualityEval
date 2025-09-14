#https://leetcode.com/problems/consecutive-characters/
#The power of the string is the maximum length of a non-empty substring that contains only one unique character.
#Given a string s, return the power of s.
# 
#Example 1:
#Input: s = "leetcode"
#Output: 2
#Explanation: The substring "ee" is of length 2 with the character 'e' only.
#Example 2:
#Input: s = "abbcccddddeeeeedcba"
#Output: 5
#Explanation: The substring "eeeee" is of length 5 with the character 'e' only.
# 
#Constraints:
#	1 <= s.length <= 500
#	s consists of only lowercase English letters.
class Solution(object):
    def maxPower(self, s):
        """
        :type s: str
        :rtype: int
        """
        # Initialize max_power and current_length
        max_power = 1
        current_length = 1
        
        # Iterate through the string
        for i in range(1, len(s)):
            # If the current character is the same as the previous one, increment current_length
            if s[i] == s[i-1]:
                current_length += 1
            else:
                # If the current character is different, update max_power if current_length is greater
                max_power = max(max_power, current_length)
                current_length = 1
        
        # Update max_power if current_length is greater
        return max(max_power, current_length)
        