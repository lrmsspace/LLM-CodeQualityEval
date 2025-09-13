# You are given a positive integer n.
# A binary string x is valid if all substrings of x of length 2 contain at least one "1".
# Return all valid strings with length n, in any order.
# Example 1:
# Input: n = 3
# Output: ["010","011","101","110","111"]
# Explanation:
# The valid strings of length 3 are: "010", "011", "101", "110", and "111".
# Example 2:
# Input: n = 1
# Output: ["0","1"]
# Explanation:
# The valid strings of length 1 are: "0" and "1".
# Constraints:
# 1 <= n <= 18

class Solution(object):
    def validStrings(self, n):
        """
        :type n: int
        :rtype: List[str]
        """

        result = []
        self.generateValidStrings(n, "", result)
        return result

    def generateValidStrings(self, n, current, result):
        if len(current) == n:
            result.append(current)
            return

        # Append '0' if the last character is not '0'
        if not current or current[-1] == '1':
            self.generateValidStrings(n, current + '0', result)

        # Append '1' if the last character is not '1'
        if not current or current[-1] == '0':
            self.generateValidStrings(n, current + '1', result)
