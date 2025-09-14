# Given a string s of length n and an integer k, determine whether it is possible to select k disjoint special substrings.
# A special substring is a substring where:
# Any character present inside the substring should not appear outside it in the string.
# The substring is not the entire string s.
# Note that all k substrings must be disjoint, meaning they cannot overlap.
# Return true if it is possible to select k such disjoint special substrings; otherwise, return false.
# Example 1:
# Input: s = "abcdbaefab", k = 2
# Output: true
# Explanation:
# We can select two disjoint special substrings: "cd" and "ef".
# "cd" contains the characters 'c' and 'd', which do not appear elsewhere in s.
# "ef" contains the characters 'e' and 'f', which do not appear elsewhere in s.
# Example 2:
# Input: s = "cdefdc", k = 3
# Output: false
# Explanation:
# There can be at most 2 disjoint special substrings: "e" and "f". Since k = 3, the output is false.
# Example 3:
# Input: s = "abeabe", k = 0
# Output: true
# Constraints:
# 2 <= n == s.length <= 5 * 104
# 0 <= k <= 26
# s consists only of lowercase English letters.

class Solution(object):
    def maxSubstringLength(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: bool
        """
        # Initialize a set to store the characters that appear in the current substring
        chars = set()
        
        # Initialize a set to store the substrings that have been selected
        selected = set()
        
        # Initialize variables to track the maximum length of the current substring
        max_length = 0
        
        # Iterate through the string
        for i in range(len(s)):
            # Add the current character to the set of characters
            chars.add(s[i])
            
            # If the number of unique characters in the set is equal to k, add the current substring to the selected set
            if len(chars) == k:
                selected.add(s[i - max_length + 1:i + 1])
            
            # Update the maximum length of the current substring
            max_length = max(max_length, i - i + 1)
        
        # Check if there are at least k disjoint special substrings
        return len(selected) >= k
        