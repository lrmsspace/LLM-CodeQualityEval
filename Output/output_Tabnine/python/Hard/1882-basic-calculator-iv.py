#https://leetcode.com/problems/basic-calculator-iv/
#Given an expression such as expression = "e + 8 - a + 5" and an evaluation map such as {"e": 1} (given in terms of evalvars = ["e"] and evalints = [1]), return a list of tokens representing the simplified expression, such as ["-1*a","14"]
#	An expression alternates chunks and symbols, with a space separating each chunk and symbol.
#	A chunk is either an expression in parentheses, a variable, or a non-negative integer.
#	A variable is a string of lowercase letters (not including digits.) Note that variables can be multiple letters, and note that variables never have a leading coefficient or unary operator like "2x" or "-x".
#Expressions are evaluated in the usual order: brackets first, then multiplication, then addition and subtraction.
#	For example, expression = "1 + 2 * 3" has an answer of ["7"].
#The format of the output is as follows:
#	For each term of free variables with a non-zero coefficient, we write the free variables within a term in sorted order lexicographically.
#	
#		For example, we would never write a term like "b*a*c", only "a*b*c".
#	
#	
#	Terms have degrees equal to the number of free variables being multiplied, counting multiplicity. We write the largest degree terms of our answer first, breaking ties by lexicographic order ignoring the leading coefficient of the term.
#	
#		For example, "a*a*b*c" has degree 4.
#	
#	
#	The leading coefficient of the term is placed directly to the left with an asterisk separating it from the variables (if they exist.) A leading coefficient of 1 is still printed.
#	An example of a well-formatted answer is ["-2*a*a*a", "3*a*a*b", "3*b*b", "4*a", "5*c", "-6"].
#	Terms (including constant terms) with coefficient 0 are not included.
#	
#		For example, an expression of "0" has an output of [].
#	
#	
#Note: You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].
# 
#Example 1:
#Input: expression = "e + 8 - a + 5", evalvars = ["e"], evalints = [1]
#Output: ["-1*a","14"]
#Example 2:
#Input: expression = "e - 8 + temperature - pressure", evalvars = ["e", "temperature"], evalints = [1, 12]
#Output: ["-1*pressure","5"]
#Example 3:
#Input: expression = "(e + 8) * (e - 8)", evalvars = [], evalints = []
#Output: ["1*e*e","-64"]
# 
#Constraints:
#	1 <= expression.length <= 250
#	expression consists of lowercase English letters, digits, '+', '-', '*', '(', ')', ' '.
#	expression does not contain any leading or trailing spaces.
#	All the tokens in expression are separated by a single space.
#	0 <= evalvars.length <= 100
#	1 <= evalvars[i].length <= 20
#	evalvars[i] consists of lowercase English letters.
#	evalints.length == evalvars.length
#	-100 <= evalints[i] <= 100
class Solution(object):
    def basicCalculatorIV(self, expression, evalvars, evalints):
        """
        :type expression: str
        :type evalvars: List[str]
        :type evalints: List[int]
        :rtype: List[str]
        """
        # Build a dictionary of variable names to their values
        var_dict = dict(zip(evalvars, evalints))
        
        # Helper function to parse the expression and convert it to a list of tokens
        def parse_expression(expr):
            tokens = []
            i = 0
            while i < len(expr):
                if expr[i] == ' ':
                    i += 1
                    continue
        
                if expr[i] == '(':
                    j = i + 1
                    while j < len(expr) and expr[j] != ')':
                        j += 1
                    tokens.append(expr[i+1:j])
                    i = j + 1
            
                elif expr[i].isdigit():
                    j = i + 1
                    while j < len(expr) and expr[j].isdigit():
                        j += 1
                    tokens.append(expr[i:j])
                    i = j
            
                elif expr[i] in var_dict:
                    tokens.append(expr[i])
                    i += 1

        # Helper function to evaluate a token
        def eval_token(token):
            if token.isdigit():
                return int(token)
            elif token in var_dict:
                return var_dict[token]
            else:
                raise ValueError(f"Invalid variable: {token}")
        
        # Helper function to evaluate an expression
        def eval_expression(expr):
            stack = []
            i = 0
            while i < len(expr):
                if expr[i] == ' ':
                    i += 1
                    continue
            
                if expr[i] == '(':
                    j = i + 1
                    while j < len(expr) and expr[j] != ')':
                        j += 1
                    stack.append(eval_expression(expr[i+1:j]))
                    i = j + 1
            
                elif expr[i] in '+-*/':
                    right = stack.pop()
                    left = stack.pop()
                    if expr[i] == '+':
                        stack.append(left + right)
                    elif expr[i] == '-':
                        stack.append(left - right)
                    elif expr[i] == '*':
                        stack.append(left * right)
                    elif expr[i] == '/':
                        if right == 0:
                            raise ZeroDivisionError("Division by zero")
        
                        stack.append(left // right)
        
        # Parse the expression and evaluate it
        parse_expression(expression)
        eval_expression(tokens)
        
        # Convert the result to a list of tokens
        result = []
        while stack:
            token = stack.pop()
            if isinstance(token, int):
                result.append(str(token))
            else:
                result.append(token)
        
        # Sort the result in lexicographical order
        result.sort(key=lambda x: (x.count('*'), x))
        
        # Remove terms with coefficient 0
        result = [token for token in result if token != '0' or token == '0' and '*' not in token]
        
        return result