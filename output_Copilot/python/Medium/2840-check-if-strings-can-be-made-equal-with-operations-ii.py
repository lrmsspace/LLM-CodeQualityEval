# You are given two strings s1 and s2, both of length n, consisting of lowercase English letters.
# You can apply the following operation on any of the two strings any number of times:
# Choose any two indices i and j such that i < j and the difference j - i is even, then swap the two characters at those indices in the string.
# Return true if you can make the strings s1 and s2 equal, and false otherwise.
# Example 1:
# Input: s1 = "abcdba", s2 = "cabdab"
# Output: true
# Explanation: We can apply the following operations on s1:
# - Choose the indices i = 0, j = 2. The resulting string is s1 = "cbadba".
# - Choose the indices i = 2, j = 4. The resulting string is s1 = "cbbdaa".
# - Choose the indices i = 1, j = 5. The resulting string is s1 = "cabdab" = s2.
# Example 2:
# Input: s1 = "abe", s2 = "bea"
# Output: false
# Explanation: It is not possible to make the two strings equal.
# Constraints:
# n == s1.length == s2.length
# 1 <= n <= 105
# s1 and s2 consist only of lowercase English letters.

class Solution(object):
    def checkStrings(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """

        # Check if the lengths of the strings are equal
        if len(s1) != len(s2):
            return False

        # Create two lists to store the characters at even and odd indices
        s1_even = []
        s1_odd = []
        s2_even = []
        s2_odd = []

        for i in range(len(s1)):
            if i % 2 == 0:
                s1_even.append(s1[i])
                s2_even.append(s2[i])
            else:
                s1_odd.append(s1[i])
                s2_odd.append(s2[i])

        # Sort the lists
        s1_even.sort()
        s1_odd.sort()
        s2_even.sort()
        s2_odd.sort()

        # Check if the sorted lists are equal
        return s1_even == s2_even and s1_odd == s2_odd