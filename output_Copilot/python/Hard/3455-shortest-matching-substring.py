# You are given a string s and a pattern string p, where p contains exactly two '*' characters.
# The '*' in p matches any sequence of zero or more characters.
# Return the length of the shortest substring in s that matches p. If there is no such substring, return -1.
# Note: The empty substring is considered valid.
# Example 1:
# Input: s = "abaacbaecebce", p = "ba*c*ce"
# Output: 8
# Explanation:
# The shortest matching substring of p in s is "baecebce".
# Example 2:
# Input: s = "baccbaadbc", p = "cc*baa*adb"
# Output: -1
# Explanation:
# There is no matching substring in s.
# Example 3:
# Input: s = "a", p = "**"
# Output: 0
# Explanation:
# The empty substring is the shortest matching substring.
# Example 4:
# Input: s = "madlogic", p = "*adlogi*"
# Output: 6
# Explanation:
# The shortest matching substring of p in s is "adlogi".
# Constraints:
# 1 <= s.length <= 105
# 2 <= p.length <= 105
# s contains only lowercase English letters.
# p contains only lowercase English letters and exactly two '*'.

class Solution(object):
    def shortestMatchingSubstring(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: int
        """
        # Find the positions of the '*' characters in p
        star1 = p.index('*')
        star2 = p.rindex('*')

        # Extract the prefix and suffix from p
        prefix = p[:star1]
        suffix = p[star2 + 1:]

        # Check if the prefix and suffix can be found in s
        start_index = s.find(prefix)
        if start_index == -1:
            return -1

        end_index = s.rfind(suffix, start_index + len(prefix))
        if end_index == -1:
            return -1

        # Calculate the length of the matching substring
        return end_index + len(suffix) - start_index

        