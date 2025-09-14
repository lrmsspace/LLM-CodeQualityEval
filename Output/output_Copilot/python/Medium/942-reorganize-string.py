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
        # Count the frequency of each character in the string
        count = Counter(s)
        
        # Find the maximum frequency character
        max_freq = max(count.values())
        
        # If the maximum frequency is more than half the length of the string, return ""
        if max_freq > (len(s) + 1) // 2:
            return ""
        
        # Create a list to hold the rearranged characters
        result = [""] * len(s)
        
        # Fill in the even indices first with the most frequent character
        index = 0
        for char, freq in count.items():
            while freq > 0 and index < len(s):
                result[index] = char
                index += 2
                freq -= 1
        
        # Fill in the odd indices with the remaining characters
        index = 1
        for char, freq in count.items():
            while freq > 0 and index < len(s):
                result[index] = char
                index += 2
                freq -= 1
        
        return "".join(result) if "" not in result else ""