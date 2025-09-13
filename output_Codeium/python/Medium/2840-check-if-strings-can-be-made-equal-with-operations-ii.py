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
        count1_odd, count1_even = [0] * 26, [0] * 26
        count2_odd, count2_even = [0] * 26, [0] * 26
        
        for i in range(len(s1)):
            if i % 2 == 0:
                count1_even[ord(s1[i]) - ord('a')] += 1
                count2_even[ord(s2[i]) - ord('a')] += 1
            else:
                count1_odd[ord(s1[i]) - ord('a')] += 1
                count2_odd[ord(s2[i]) - ord('a')] += 1
        
        return count1_odd == count2_odd and count1_even == count2_even

