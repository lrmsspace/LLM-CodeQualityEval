# Given a string s and an integer k, return the total number of substrings of s where at least one character appears at least k times.
# Example 1:
# Input: s = "abacb", k = 2
# Output: 4
# Explanation:
# The valid substrings are:
# "aba" (character 'a' appears 2 times).
# "abac" (character 'a' appears 2 times).
# "abacb" (character 'a' appears 2 times).
# "bacb" (character 'b' appears 2 times).
# Example 2:
# Input: s = "abcde", k = 1
# Output: 15
# Explanation:
# All substrings are valid because every character appears at least once.
# Constraints:
# 1 <= s.length <= 3000
# 1 <= k <= s.length
# s consists only of lowercase English letters.

class Solution(object):
    def numberOfSubstrings(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        from collections import defaultdict

        count = 0
        
        # Iterate over each starting point of the substring
        for start in range(len(s)):
            freq = defaultdict(int)
            # Iterate over each ending point of the substring
            for end in range(start, len(s)):
                # Update the frequency of the current character
                freq[s[end]] += 1
                # Check if any character appears at least k times
                if any(value >= k for value in freq.values()):
                    count += 1
        
        return count

