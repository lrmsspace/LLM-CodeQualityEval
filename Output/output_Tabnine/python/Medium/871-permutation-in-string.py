#https://leetcode.com/problems/permutation-in-string/
#Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
#In other words, return true if one of s1's permutations is the substring of s2.
# 
#Example 1:
#Input: s1 = "ab", s2 = "eidbaooo"
#Output: true
#Explanation: s2 contains one permutation of s1 ("ba").
#Example 2:
#Input: s1 = "ab", s2 = "eidboaoo"
#Output: false
# 
#Constraints:
#	1 <= s1.length, s2.length <= 104
#	s1 and s2 consist of lowercase English letters.
class Solution(object):
    def checkInclusion(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        if len(s1) > len(s2):
            return False
        
        map1 = [0] * 26
        map2 = [0] * 26
        
        for char in s1:
            map1[ord(char) - ord('a')] += 1
        
        for i in range(len(s1)):
            map2[ord(s2[i]) - ord('a')] += 1
        
        if map1 == map2:
            return True
        
        for i in range(len(s1), len(s2)):
            map2[ord(s2[i]) - ord('a')] += 1
            map2[ord(s2[i - len(s1)]) - ord('a')] -= 1
            
            if map1 == map2:
                return True
        
        return False
        