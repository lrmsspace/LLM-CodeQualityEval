# You are given two strings s and t, both of which are anagrams of each other, and an integer k.
# Your task is to determine whether it is possible to split the string s into k equal-sized substrings, rearrange the substrings, and concatenate them in any order to create a new string that matches the given string t.
# Return true if this is possible, otherwise, return false.
# An anagram is a word or phrase formed by rearranging the letters of a different word or phrase, using all the original letters exactly once.
# A substring is a contiguous non-empty sequence of characters within a string.
# Example 1:
# Input: s = "abcd", t = "cdab", k = 2
# Output: true
# Explanation:
# Split s into 2 substrings of length 2: ["ab", "cd"].
# Rearranging these substrings as ["cd", "ab"], and then concatenating them results in "cdab", which matches t.
# Example 2:
# Input: s = "aabbcc", t = "bbaacc", k = 3
# Output: true
# Explanation:
# Split s into 3 substrings of length 2: ["aa", "bb", "cc"].
# Rearranging these substrings as ["bb", "aa", "cc"], and then concatenating them results in "bbaacc", which matches t.
# Example 3:
# Input: s = "aabbcc", t = "bbaacc", k = 2
# Output: false
# Explanation:
# Split s into 2 substrings of length 3: ["aab", "bcc"].
# These substrings cannot be rearranged to form t = "bbaacc", so the output is false.
# Constraints:
# 1 <= s.length == t.length <= 2 * 105
# 1 <= k <= s.length
# s.length is divisible by k.
# s and t consist only of lowercase English letters.
# The input is generated such that s and t are anagrams of each other.

class Solution(object):
    def isPossibleToRearrange(self, s, t, k):
        """
        :type s: str
        :type t: str
        :type k: int
        :rtype: bool
        """
        # Count the frequency of characters in s
        count = [0] * 26
        
        for char in s:
            count[ord(char) - ord('a')] += 1
        
        # Count the frequency of characters in t
        t_count = [0] * 26
        
        for char in t:
            t_count[ord(char) - ord('a')] += 1
        
        # Check if the frequency of characters in t is equal to the frequency of characters in s
        if t_count!= count:
            return False
        
        # Sort the characters in s based on their frequency
        sorted_s = sorted(s, key=lambda x: count[ord(x) - ord('a')])
        
        # Initialize the result and index variables
        result = []
        index = 0
        
        # Iterate over the sorted characters in s
        for i in range(k):
            # Find the substring of length k starting from index
            substring = sorted_s[index:index + k]
            
            # Check if the substring can be rearranged to form t
            if self.is_rearrangeable(substring, t):
                result.append(substring)
                index += k
            else:
                return False
        # Check if the remaining characters in s can form a substring of length k
        if index < len(s):
            substring = sorted_s[index:]
            
            # Check if the substring can be rearranged to form t
            if self.is_rearrangeable(substring, t):
                result.append(substring)
            else:
                return False
        
        # Check if the result is equal to t
        return ''.join(result) == t
        