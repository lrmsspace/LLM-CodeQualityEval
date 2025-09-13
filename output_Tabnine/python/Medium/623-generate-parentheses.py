#https://leetcode.com/problems/generate-parentheses/
#Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
# 
#Example 1:
#Input: n = 3
#Output: ["((()))","(()())","(())()","()(())","()()()"]
#Example 2:
#Input: n = 1
#Output: ["()"]
# 
#Constraints:
#	1 <= n <= 8
class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        def backtrack(left, right, str):
            if left == n and right == n:
                res.append(str)
                return
            if left < n:
                backtrack(left + 1, right, str + '(')
            if right < left:
                backtrack(left, right + 1, str + ')')
        
        res = []
        backtrack(0, 0, '')
        return res
        