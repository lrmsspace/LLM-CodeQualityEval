#https://leetcode.com/problems/maximum-score-from-removing-substrings/
#You are given a string s and two integers x and y. You can perform two types of operations any number of times.
#	Remove substring "ab" and gain x points.
#	
#		For example, when removing "ab" from "cabxbae" it becomes "cxbae".
#	
#	
#	Remove substring "ba" and gain y points.
#	
#		For example, when removing "ba" from "cabxbae" it becomes "cabxe".
#	
#	
#Return the maximum points you can gain after applying the above operations on s.
# 
#Example 1:
#Input: s = "cdbcbbaaabab", x = 4, y = 5
#Output: 19
#Explanation:
#- Remove the "ba" underlined in "cdbcbbaaabab". Now, s = "cdbcbbaaab" and 5 points are added to the score.
#- Remove the "ab" underlined in "cdbcbbaaab". Now, s = "cdbcbbaa" and 4 points are added to the score.
#- Remove the "ba" underlined in "cdbcbbaa". Now, s = "cdbcba" and 5 points are added to the score.
#- Remove the "ba" underlined in "cdbcba". Now, s = "cdbc" and 5 points are added to the score.
#Total score = 5 + 4 + 5 + 5 = 19.
#Example 2:
#Input: s = "aabbaaxybbaabb", x = 5, y = 4
#Output: 20
# 
#Constraints:
#	1 <= s.length <= 105
#	1 <= x, y <= 104
#	s consists of lowercase English letters.
class Solution(object):
    def maximumGain(self, s, x, y):
        """
        :type s: str
        :type x: int
        :type y: int
        :rtype: int
        """
        # 计算 "ab" 和 "ba" 的得分
        ab_score = x if x >= y else 0
        ba_score = y if y > x else 0

        # 初始化分数和栈
        score = 0
        stack = []

        for char in s:
            # 如果栈不为空且当前字符与栈顶字符形成 "ab" 或 "ba"
            if stack and ((stack[-1] == 'a' and char == 'b') or (stack[-1] == 'b' and char == 'a')):
                # 如果是 "ab"，则加上 ab_score；如果是 "ba"，则加上 ba_score
                if stack[-1] == 'a':
                    score += ab_score
                else:
                    score += ba_score
                stack.pop()        
            else:
                stack.append(char)

                # 处理剩余的栈，可能还有未处理的 "ab" 或 "ba"
                remaining_s = ''.join(stack)
                stack = []
                for char in remaining_s:
                    if stack and ((stack[-1] == 'a' and char == 'b') or (stack[-1] == 'b' and char == 'a')):
                    # 如果是 "ab"，则加上 ab_score；如果是 "ba"，则加上 ba_score
                        if stack[-1] == 'a':
                            score += ab_score
                        else:
                            score += ba_score
                        stack.pop()
                    else:
                        stack.append(char)

                return score    