#https://leetcode.com/problems/find-all-anagrams-in-a-string/
#Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.
# 
#Example 1:
#Input: s = "cbaebabacd", p = "abc"
#Output: [0,6]
#Explanation:
#The substring with start index = 0 is "cba", which is an anagram of "abc".
#The substring with start index = 6 is "bac", which is an anagram of "abc".
#Example 2:
#Input: s = "abab", p = "ab"
#Output: [0,1,2]
#Explanation:
#The substring with start index = 0 is "ab", which is an anagram of "ab".
#The substring with start index = 1 is "ba", which is an anagram of "ab".
#The substring with start index = 2 is "ab", which is an anagram of "ab".
# 
#Constraints:
#	1 <= s.length, p.length <= 3 * 104
#	s and p consist of lowercase English letters.
class Solution(object):
    def findAnagrams(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: List[int]
        """
        # Create a dictionary for the pattern
        p_dict = {}
        for char in p:
            p_dict[char] = p_dict.get(char, 0) + 1
        
        # Create a dictionary for the current substring
        s_dict = {}
        result = []
        left = 0
        
        for right, char in enumerate(s):
            s_dict[char] = s_dict.get(char, 0) + 1
            
            # If the current substring has the same length as the pattern
            if right - left + 1 == len(p):
                # If the current substring is an anagram of the pattern
                if s_dict == p_dict:
                    result.append(left)
                
                # Remove the first character from the left substring and increment its count
                s_dict[s[left]] -= 1
                if s_dict[s[left]] == 0:
                    del s_dict[s[left]]
                    left += 1
        
        return result
        