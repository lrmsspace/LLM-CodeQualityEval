#https://leetcode.com/problems/ransom-note/
#Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.
#Each letter in magazine can only be used once in ransomNote.
# 
#Example 1:
#Input: ransomNote = "a", magazine = "b"
#Output: false
#Example 2:
#Input: ransomNote = "aa", magazine = "ab"
#Output: false
#Example 3:
#Input: ransomNote = "aa", magazine = "aab"
#Output: true
# 
#Constraints:
#	1 <= ransomNote.length, magazine.length <= 105
#	ransomNote and magazine consist of lowercase English letters.
class Solution(object):
    def canConstruct(self, ransomNote, magazine):
        """
        :type ransomNote: str
        :type magazine: str
        :rtype: bool
        """
        # Initialize a dictionary to store the frequency of each letter in magazine
        magazine_dict = {}
        for char in magazine:
            magazine_dict[char] = magazine_dict.get(char, 0) + 1
        
        # Iterate through ransomNote and decrement the frequency of each letter in magazine_dict
        for char in ransomNote:
            if char not in magazine_dict or magazine_dict[char] == 0:
                return False
            magazine_dict[char] -= 1
        
        # If all letters in ransomNote can be constructed from magazine, return True
        return True
        