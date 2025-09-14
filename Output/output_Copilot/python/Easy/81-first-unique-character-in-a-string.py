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
        # Create a dictionary to store the frequency of each character
        char_count = {}

        # Count the frequency of each character in the string
        for char in s:
            if char in char_count:
                char_count[char] += 1
            else:
                char_count[char] = 1

        # Find the index of the first unique character
        for i, char in enumerate(s):
            if char_count[char] == 1:
                return i

        # If no unique character is found, return -1
        return -1        