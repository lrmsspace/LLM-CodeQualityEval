#https://leetcode.com/problems/different-ways-to-add-parentheses/
#Given a string expression of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. You may return the answer in any order.
#The test cases are generated such that the output values fit in a 32-bit integer and the number of different results does not exceed 104.
# 
#Example 1:
#Input: expression = "2-1-1"
#Output: [0,2]
#Explanation:
#((2-1)-1) = 0 
#(2-(1-1)) = 2
#Example 2:
#Input: expression = "2*3-4*5"
#Output: [-34,-14,-10,-10,10]
#Explanation:
#(2*(3-(4*5))) = -34 
#((2*3)-(4*5)) = -14 
#((2*(3-4))*5) = -10 
#(2*((3-4)*5)) = -10 
#(((2*3)-4)*5) = 10
# 
#Constraints:
#	1 <= expression.length <= 20
#	expression consists of digits and the operator '+', '-', and '*'.
#	All the integer values in the input expression are in the range [0, 99].
#	The integer values in the input expression do not have a leading '-' or '+' denoting the sign.
class Solution(object):
    def diffWaysToCompute(self, expression):
        """
        :type expression: str
        :rtype: List[int]
        """
        """
        1. 递归拆分表达式
        2. 计算每个子表达式的结果
        3. 合并结果
        """
        if expression.isdigit():
            return [int(expression)]

        res = []
        for i, c in enumerate(expression):
            if c in "+-*":
                left = self.diffWaysToCompute(expression[:i])
                right = self.diffWaysToCompute(expression[i + 1:])
                for l in left:
                    for r in right:
                        if c == '+':
                            res.append(l + r)
                        elif c == '-':
                            res.append(l - r)
                        else:
                            res.append(l * r)
        return res        