#https://leetcode.com/problems/fraction-addition-and-subtraction/
#Given a string expression representing an expression of fraction addition and subtraction, return the calculation result in string format.
#The final result should be an irreducible fraction. If your final result is an integer, change it to the format of a fraction that has a denominator 1. So in this case, 2 should be converted to 2/1.
# 
#Example 1:
#Input: expression = "-1/2+1/2"
#Output: "0/1"
#Example 2:
#Input: expression = "-1/2+1/2+1/3"
#Output: "1/3"
#Example 3:
#Input: expression = "1/3-1/2"
#Output: "-1/6"
# 
#Constraints:
#	The input string only contains '0' to '9', '/', '+' and '-'. So does the output.
#	Each fraction (input and output) has the format ±numerator/denominator. If the first input fraction or the output is positive, then '+' will be omitted.
#	The input only contains valid irreducible fractions, where the numerator and denominator of each fraction will always be in the range [1, 10]. If the denominator is 1, it means this fraction is actually an integer in a fraction format defined above.
#	The number of given fractions will be in the range [1, 10].
#	The numerator and denominator of the final result are guaranteed to be valid and in the range of 32-bit int.
class Solution(object):
    def fractionAddition(self, expression):
        """
        :type expression: str
        :rtype: str
        """
        def parse_fraction(s):
            i, n, d = 0, 0, 1
            if s[i] == '-':
                i += 1
            while i < len(s) and s[i]!= '/':
                n = n * 10 + int(s[i])
                i += 1
            if i < len(s) and s[i] == '/':
                i += 1
                while i < len(s):
                    d = d * 10 + int(s[i])
                    i += 1
            return n, d
        
        def add_fractions(a, b):
            gcd = math.gcd(a[1], b[1])
            return (a[0] * b[1] + b[0] * a[1]) // gcd, a[1] * b[1] // gcd
        
        stack = []

        for i in range(len(expression)):
            if expression[i] == ' ':
                continue
            elif expression[i] == '+':
                if stack:
                    b = stack.pop()
                    a = stack.pop()
                    stack.append(add_fractions(a, b))
            elif expression[i] == '-':
                if stack:
                    b = stack.pop()
                    a = stack.pop()
                    stack.append((a[0] - b[0], a[1]))
            else:
                n, d = parse_fraction(expression[i:])
                stack.append((n, d))
        
        return str(stack[0][0] // stack[0][1]) if stack[0][1]!= 1 else str(stack[0][0])
        