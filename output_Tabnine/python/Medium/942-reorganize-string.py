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
        # Count the frequency of each character
        count = collections.Counter(s)
        
        # Sort the characters based on their frequency in descending order
        sorted_chars = sorted(count.items(), key=lambda x: x[1], reverse=True)
        
        # Initialize an empty result string
        result = ""
        
        # Try to form groups of three characters with the highest frequency
        for char, freq in sorted_chars:
            for _ in range(freq):
                # If the result string is not empty and the last two characters are the same, return ""
                if result and result[-2:] == char * 2:
                    return ""
                
                # Add the current character to the result string
                result += char
        
        # If the result string is not empty, return it. Otherwise, return ""
        return result if len(result) == len(s) else ""
        