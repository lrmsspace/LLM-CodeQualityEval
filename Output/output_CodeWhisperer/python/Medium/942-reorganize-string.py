#https://leetcode.com/problems/reorganize-string/
#Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.
#Return any possible rearrangement of s or return "" if not possible.
# 
#Example 1:
#Input: s = "aab"
#Output: "aba"
#Example 2:
#Input: s = "aaab"
#Output: ""
# 
#Constraints:
#	1 <= s.length <= 500
#	s consists of lowercase English letters.
class Solution(object):
    def reorganizeString(self, s):
        """
        :type s: str
        :rtype: str
        """
        char_count = {}
        for char in s:
            char_count[char] = char_count.get(char, 0) + 1
        
        max_count = max(char_count.values())
        if max_count > (len(s) + 1) // 2:
            return ""
        
        char_list = sorted(char_count, key=lambda x: char_count[x], reverse=True)
        result = [''] * len(s)
        index = 0
        
        for i in range(len(char_list)):
            char = char_list[i]
            count = char_count[char]
            for _ in range(count):
                if index >= len(s):
                    index = 1
                result[index] = char
                index += 2
        
        return ''.join(result)
        