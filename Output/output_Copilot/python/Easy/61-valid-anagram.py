#https://leetcode.com/problems/valid-anagram/
#Given two strings s and t, return true if t is an anagram of s, and false otherwise.
# 
#Example 1:
#Input: s = "anagram", t = "nagaram"
#Output: true
#Example 2:
#Input: s = "rat", t = "car"
#Output: false
# 
#Constraints:
#	1 <= s.length, t.length <= 5 * 104
#	s and t consist of lowercase English letters.
# 
#Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?
class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        if len(s) != len(t):
            return False
        count = {}
        for i in range(len(s)):
            count[s[i]] = count.get(s[i], 0) + 1
            count[t[i]] = count.get(t[i], 0) - 1
        for v in count.values():
            if v != 0:
                return False
        return True        