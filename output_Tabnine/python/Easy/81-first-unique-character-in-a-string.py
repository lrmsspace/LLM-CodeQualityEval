#https://leetcode.com/problems/first-unique-character-in-a-string/
#Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.
# 
#Example 1:
#Input: s = "leetcode"
#Output: 0
#Explanation:
#The character 'l' at index 0 is the first character that does not occur at any other index.
#Example 2:
#Input: s = "loveleetcode"
#Output: 2
#Example 3:
#Input: s = "aabb"
#Output: -1
# 
#Constraints:
#	1 <= s.length <= 105
#	s consists of only lowercase English letters.
class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        # Create a dictionary to store the count of each character
        char_count = {}
        
        # Iterate through the string
        for i, char in enumerate(s):
            # If the character is already in the dictionary, increment its count
            if char in char_count:
                char_count[char] += 1
            # If the character is not in the dictionary, add it with count 1
            else:
                char_count[char] = 1
        
        # Iterate through the string again to find the first non-repeating character
        for i, char in enumerate(s):
            if char_count[char] == 1:
                return i
        
        # If no non-repeating character is found, return -1
        return -1
        