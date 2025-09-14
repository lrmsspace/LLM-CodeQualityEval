# You are given three strings: s1, s2, and s3. In one operation you can choose one of these strings and delete its rightmost character. Note that you cannot completely empty a string.
# Return the minimum number of operations required to make the strings equal. If it is impossible to make them equal, return -1.
# Example 1:
# Input: s1 = "abc", s2 = "abb", s3 = "ab"
# Output: 2
# Explanation: Deleting the rightmost character from both s1 and s2 will result in three equal strings.
# Example 2:
# Input: s1 = "dac", s2 = "bac", s3 = "cac"
# Output: -1
# Explanation: Since the first letters of s1 and s2 differ, they cannot be made equal.
# Constraints:
# 1 <= s1.length, s2.length, s3.length <= 100
# s1, s2 and s3 consist only of lowercase English letters.

class Solution(object):
    def findMinimumOperations(self, s1, s2, s3):
        """
        :type s1: str
        :type s2: str
        :type s3: str
        :rtype: int
        """
        # Find the length of the longest common suffix
        def longest_common_suffix(s1, s2, s3):
            i = 0
            while (i < len(s1) and i < len(s2) and i < len(s3) and 
                   s1[-1 - i] == s2[-1 - i] == s3[-1 - i]):
                i += 1
            return i
        
        lcs_length = longest_common_suffix(s1, s2, s3)
        
        # Calculate the number of operations needed
        operations = (len(s1) - lcs_length) + (len(s2) - lcs_length) + (len(s3) - lcs_length)
        
        # If all strings are empty after operations, return the number of operations
        if lcs_length == 0 and (s1 or s2 or s3):
            return -1
        
        return operations
        