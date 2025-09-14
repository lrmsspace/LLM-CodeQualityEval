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
        result = []
        self.generate(result, "", 0, 0, n)
        return result
    
    def generate(self, result, current, openCount, closeCount, n):
        if len(current) == n * 2:
            result.append(current)
            return
        
        if openCount < n:
            self.generate(result, current + "(", openCount + 1, closeCount, n)
        if closeCount < openCount:
            self.generate(result, current + ")", openCount, closeCount + 1, n)
