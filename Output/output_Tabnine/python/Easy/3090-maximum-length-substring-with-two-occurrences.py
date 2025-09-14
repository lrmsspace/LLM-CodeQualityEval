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
        count = {}
        start = 0
        max_length = 0
        
        for end in range(len(s)):
            if s[end] in count:
                count[s[end]] += 1
            else:
                count[s[end]] = 1
            
            while len(count) > 2:
                if count[s[start]] > 1:
                    count[s[start]] -= 1
                else:
                    del count[s[start]]
                start += 1
            
            max_length = max(max_length, end - start + 1)
        
        return max_length
        