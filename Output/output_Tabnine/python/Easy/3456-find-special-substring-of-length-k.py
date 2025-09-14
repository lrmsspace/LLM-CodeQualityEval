# You are given a string s and an integer k.
# Determine if there exists a substring of length exactly k in s that satisfies the following conditions:
# The substring consists of only one distinct character (e.g., "aaa" or "bbb").
# If there is a character immediately before the substring, it must be different from the character in the substring.
# If there is a character immediately after the substring, it must also be different from the character in the substring.
# Return true if such a substring exists. Otherwise, return false.
# Example 1:
# Input: s = "aaabaaa", k = 3
# Output: true
# Explanation:
# The substring s[4..6] == "aaa" satisfies the conditions.
# It has a length of 3.
# All characters are the same.
# The character before "aaa" is 'b', which is different from 'a'.
# There is no character after "aaa".
# Example 2:
# Input: s = "abc", k = 2
# Output: false
# Explanation:
# There is no substring of length 2 that consists of one distinct character and satisfies the conditions.
# Constraints:
# 1 <= k <= s.length <= 100
# s consists of lowercase English letters only.

class Solution(object):
    def hasSpecialSubstring(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: bool
        """
        # Check if there are at least k distinct characters in the string
        if len(set(s)) < k:
            return False
        
        # Iterate through the string and check for substrings of length k
        for i in range(len(s) - k + 1):
            substring = s[i:i+k]
            
            # Check if the substring consists of only one distinct character
            if len(set(substring)) == 1:
                # Check if the substring has a character immediately before and after it
                if i > 0 and s[i-1] == substring[0] or i < len(s) - k and s[i+k] == substring[0]:
                    continue
                return True
        
        return False
        