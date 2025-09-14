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
        freq = [0] * 26
        for char in s:
            freq[ord(char) - ord('a')] += 1
        
        odd_freq = 0
        for freq_count in freq:
            if freq_count % 2 == 1:
                odd_freq += 1
        
        if odd_freq < 2:
            return 0
        
        max_diff = 0
        for i in range(26):
            if freq[i] % 2 == 0:
                max_diff = max(max_diff, freq[i] - freq[i - 1])
        
        return max_diff
        