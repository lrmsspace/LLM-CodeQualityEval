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
        for i in range(1 << n):
            s = bin(i)[2:].zfill(n)
            if all(s[j] == '1' or s[j+1] == '1' for j in range(n-1)):
                result.append(s)
        return result
