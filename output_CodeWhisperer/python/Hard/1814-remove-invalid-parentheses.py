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
        def is_valid(string):
            count = 0
            for char in string:
                if char == '(':
                    count += 1
                elif char == ')':
                    count -= 1
                if count < 0:
                    return False
            return count == 0
        
        result = []
        visited = set()
        queue = [s]
        found = False
        while queue:
            current = queue.pop(0)
            if is_valid(current):
                result.append(current)
                found = True
            if found:
                continue
            for i in range(len(current)):
                if current[i] in ('(', ')'):
                    new_string = current[:i] + current[i+1:]
                    if new_string not in visited:
                        visited.add(new_string)
                        queue.append(new_string)
        return result if result else [""]
        