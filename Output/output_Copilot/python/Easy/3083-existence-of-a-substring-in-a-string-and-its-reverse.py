# Given a string s, find any substring of length 2 which is also present in the reverse of s.
# Return true if such a substring exists, and false otherwise.
# Example 1:
# Input: s = "leetcode"
# Output: true
# Explanation: Substring "ee" is of length 2 which is also present in reverse(s) == "edocteel".
# Example 2:
# Input: s = "abcba"
# Output: true
# Explanation: All of the substrings of length 2 "ab", "bc", "cb", "ba" are also present in reverse(s) == "abcba".
# Example 3:
# Input: s = "abcd"
# Output: false
# Explanation: There is no substring of length 2 in s, which is also present in the reverse of s.
# Constraints:
# 1 <= s.length <= 100
# s consists only of lowercase English letters.

class Solution(object):
    def isSubstringPresent(self, s):
        """
        :type s: str
        :rtype: bool
        """
        # Create a set to store all substrings of length 2
        substrings = set()
        
        # Iterate through the string to collect all substrings of length 2
        for i in range(len(s) - 1):
            substrings.add(s[i:i + 2])
        
        # Reverse the string
        reversed_s = s[::-1]
        
        # Check if any substring of length 2 is present in the reversed string
        for i in range(len(reversed_s) - 1):
            if reversed_s[i:i + 2] in substrings:
                return True
        
        return False
        