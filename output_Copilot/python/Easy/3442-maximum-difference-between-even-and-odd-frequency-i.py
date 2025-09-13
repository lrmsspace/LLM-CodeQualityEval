# You are given a string s consisting of lowercase English letters.
# Your task is to find the maximum difference diff = freq(a1) - freq(a2) between the frequency of characters a1 and a2 in the string such that:
# a1 has an odd frequency in the string.
# a2 has an even frequency in the string.
# Return this maximum difference.
# Example 1:
# Input: s = "aaaaabbc"
# Output: 3
# Explanation:
# The character 'a' has an odd frequency of 5, and 'b' has an even frequency of 2.
# The maximum difference is 5 - 2 = 3.
# Example 2:
# Input: s = "abcabcab"
# Output: 1
# Explanation:
# The character 'a' has an odd frequency of 3, and 'c' has an even frequency of 2.
# The maximum difference is 3 - 2 = 1.
# Constraints:
# 3 <= s.length <= 100
# s consists only of lowercase English letters.
# s contains at least one character with an odd frequency and one with an even frequency.

class Solution(object):
    def maxDifference(self, s):
        """
        :type s: str
        :rtype: int
        """
        from collections import Counter
        
        # Count the frequency of each character in the string
        freq = Counter(s)
        
        # Initialize variables to track the maximum odd and even frequencies
        max_odd_freq = float('-inf')
        max_even_freq = float('-inf')
        
        # Iterate through the frequency dictionary
        for char, count in freq.items():
            if count % 2 == 1:
                max_odd_freq = max(max_odd_freq, count)
            else:
                max_even_freq = max(max_even_freq, count)

        # If we have valid odd and even frequencies, return the difference
        if max_odd_freq != float('-inf') and max_even_freq != float('-inf'):
            return max_odd_freq - max_even_freq
        # If no valid odd or even frequency found, return 0
        return 0
