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
        def backtrack(start, end, curr):
            if start > end:
                res.append(curr)
                return
            
            if curr[-1] == '0':
                backtrack(start, end, curr + '0')
            
            if start < n - 1 and curr[-1] == '1' and curr[-2] == '0':
                backtrack(start + 1, end, curr + '1')
        
        res = []
        backtrack(0, n - 1, '')
        return res
        