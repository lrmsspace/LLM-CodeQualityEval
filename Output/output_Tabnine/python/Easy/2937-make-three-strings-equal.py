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
        if s1[0] != s2[0] or s1[0] != s3[0]:
            return -1

        operations = 0
        i = 1
        while i < len(s1) and i < len(s2) and i < len(s3):
            if s1[i:] != s2[i:] or s1[i:] != s3[i:]:
                operations += 1
            else:
                break
            i += 1

        return operations