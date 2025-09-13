#https://leetcode.com/problems/expression-add-operators/
#Given a string num that contains only digits and an integer target, return all possibilities to insert the binary operators '+', '-', and/or '*' between the digits of num so that the resultant expression evaluates to the target value.
#Note that operands in the returned expressions should not contain leading zeros.
# 
#Example 1:
#Input: num = "123", target = 6
#Output: ["1*2*3","1+2+3"]
#Explanation: Both "1*2*3" and "1+2+3" evaluate to 6.
#Example 2:
#Input: num = "232", target = 8
#Output: ["2*3+2","2+3*2"]
#Explanation: Both "2*3+2" and "2+3*2" evaluate to 8.
#Example 3:
#Input: num = "3456237490", target = 9191
#Output: []
#Explanation: There are no expressions that can be created from "3456237490" to evaluate to 9191.
# 
#Constraints:
#	1 <= num.length <= 10
#	num consists of only digits.
#	-231 <= target <= 231 - 1
class Solution(object):
    def addOperators(self, num, target):
        """
        :type num: str
        :type target: int
        :rtype: List[str]
        """
        def dfs(index, prev_operand, current_operand, value, expression):
            if index == len(num):
                if value == target and current_operand == 0:
                    result.append(expression)
                return

            current_num = int(num[index])
            current_operand = current_operand * 10 + current_num

            # No operator
            dfs(index + 1, prev_operand, current_operand, value, expression)

            # Addition
            dfs(index + 1, current_operand, 0, value + current_operand, expression + '+' + str(current_operand))

            # Subtraction
            dfs(index + 1, -current_operand, 0, value - current_operand, expression + '-' + str(current_operand))

            # Multiplication
            dfs(index + 1, prev_operand * current_operand, 0,
                value - prev_operand + (prev_operand * current_operand), expression + '*' + str(current_operand))

        result = []
        dfs(0, 0, 0, 0, "")
        return result        