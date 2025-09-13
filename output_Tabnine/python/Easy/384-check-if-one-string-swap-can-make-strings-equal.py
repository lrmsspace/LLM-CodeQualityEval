#https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/
#You are given two strings s1 and s2 of equal length. A string swap is an operation where you choose two indices in a string (not necessarily different) and swap the characters at these indices.
#Return true if it is possible to make both strings equal by performing at most one string swap on exactly one of the strings. Otherwise, return false.
# 
#Example 1:
#Input: s1 = "bank", s2 = "kanb"
#Output: true
#Explanation: For example, swap the first character with the last character of s2 to make "bank".
#Example 2:
#Input: s1 = "attack", s2 = "defend"
#Output: false
#Explanation: It is impossible to make them equal with one string swap.
#Example 3:
#Input: s1 = "kelb", s2 = "kelb"
#Output: true
#Explanation: The two strings are already equal, so no string swap operation is required.
# 
#Constraints:
#	1 <= s1.length, s2.length <= 100
#	s1.length == s2.length
#	s1 and s2 consist of only lowercase English letters.
class Solution(object):
    def areAlmostEqual(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        # Count the number of mismatches
        count = sum(s1[i]!= s2[i] for i in range(len(s1)))
        
        # If there are more than one mismatch, return False
        if count > 1:
            return False
        
        # If there is exactly one mismatch, find the two indices with mismatches
        i, j = None, None
        for k in range(len(s1)):
            if s1[k]!= s2[k]:
                if i is None:
                    i = k
                else:
                    j = k
        
        # Swap the characters at indices i and j
        s1, s2 = s1[:i] + s2[j] + s1[i+1:j], s2[:j] + s1[i] + s2[j+1:]
        
        # Return True if the strings are equal after the swap
        return s1 == s2
        