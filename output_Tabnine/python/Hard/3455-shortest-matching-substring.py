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
        # Check if p contains exactly two '*' characters
        count_stars = p.count('*')
        if count_stars!= 2:
            return -1
        
        # Find the indices of the two '*' characters in p
        star_indices = [i for i, char in enumerate(p) if char == '*']
        
        # Initialize variables to keep track of the shortest matching substring
        min_length = float('inf')
        start = 0
        
        # Iterate through the characters in s
        for i in range(len(s)):
            # If the current character matches the first '*' character in p
            if s[i] == p[star_indices[0]]:
                # Try to match the remaining characters in s
                j = i + 1
                while j < len(s) and j - i <= min_length:
                    if s[j] == p[star_indices[1]]:
                        # Update the start index
                        start = i   
        
        # Return the shortest matching substring length or -1 if no matching substring exists   
        return min_length if min_length!= float('inf') else -1
        