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
        from collections import Counter

        # Count the frequency of each character in magazine
        magazine_count = Counter(magazine)

        # Check if ransomNote can be constructed from magazine
        for char in ransomNote:
            if magazine_count[char] == 0:
                return False
            magazine_count[char] -= 1

        return True        