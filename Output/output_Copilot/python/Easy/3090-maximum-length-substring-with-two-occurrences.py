# Given a string s, return the maximum length of a substring such that it contains at most two occurrences of each character.
# Example 1:
# Input: s = "bcbbbcba"
# Output: 4
# Explanation:
# The following substring has a length of 4 and contains at most two occurrences of each character: "bcbbbcba".
# Example 2:
# Input: s = "aaaa"
# Output: 2
# Explanation:
# The following substring has a length of 2 and contains at most two occurrences of each character: "aaaa".
# Constraints:
# 2 <= s.length <= 100
# s consists only of lowercase English letters.

class Solution(object):
    def maximumLengthSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        max_length = 0
        n = len(s)
        
        for i in range(n):
            char_count = {}
            current_length = 0
            
            for j in range(i, n):
                char = s[j]
                if char in char_count:
                    char_count[char] += 1
                else:
                    char_count[char] = 1
                
                if char_count[char] <= 2:
                    current_length += 1
                    max_length = max(max_length, current_length)
                else:
                    break
        
        return max_length
        