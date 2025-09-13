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
        def remove_invalid(s, i, left, right):
            if i == len(s):
                return left == right
            
            if s[i] == '(' or s[i] == ')':
                if s[i] == '(':
                    left += 1
                else:
                    left -= 1
                
                if left >= 0:
                    return remove_invalid(s, i + 1, left, right)
                else:
                    return any(remove_invalid(s[:j] + s[j + 1:], i, left + 1, right) for j in range(i))
            
            return remove_invalid(s, i + 1, left, right)
        
        stack = []
        remove_invalid(s, 0, 0, 0)
        return [s[i:j] for i, j in stack]
        