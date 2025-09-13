#https://leetcode.com/problems/remove-invalid-parentheses/
#Given a string s that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid.
#Return a list of unique strings that are valid with the minimum number of removals. You may return the answer in any order.
# 
#Example 1:
#Input: s = "()())()"
#Output: ["(())()","()()()"]
#Example 2:
#Input: s = "(a)())()"
#Output: ["(a())()","(a)()()"]
#Example 3:
#Input: s = ")("
#Output: [""]
# 
#Constraints:
#	1 <= s.length <= 25
#	s consists of lowercase English letters and parentheses '(' and ')'.
#	There will be at most 20 parentheses in s.
class Solution(object):
    def removeInvalidParentheses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        def isValid(string):
            count = 0
            for char in string:
                if char == '(':
                    count += 1
                elif char == ')':
                    count -= 1
                if count < 0:
                    return False
            return count == 0

        def dfs(string, start, leftCount, rightCount, parensToRemove, result):
            if leftCount == 0 and rightCount == 0:
                if isValid(string):
                    result.add(string)
                return

            for i in range(start, len(string)):
                if i > start and string[i] == string[i - 1]:
                    continue

                if string[i] == '(' and leftCount > 0:
                    dfs(string[:i] + string[i + 1:], i, leftCount - 1, rightCount, parensToRemove - 1, result)
                elif string[i] == ')' and rightCount > 0:
                    dfs(string[:i] + string[i + 1:], i, leftCount, rightCount - 1, parensToRemove - 1, result)

        leftCount = sum(1 for char in s if char == '(')
        rightCount = sum(1 for char in s if char == ')')
        parensToRemove = abs(leftCount - rightCount)

        result = set()
        dfs(s, 0, leftCount, rightCount, parensToRemove, result)

        return list(result)        