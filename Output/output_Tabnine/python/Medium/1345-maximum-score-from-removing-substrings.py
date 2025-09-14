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
        left, right = 0, len(s) - 1
        max_score = 0
        
        while left < right:
            if s[left:left+2] == 'ba' and s[right:right+2] == 'ab':
                max_score += max(x, y)
                left += 2
                right -= 2
            elif s[left:left+2] == 'ba':
                max_score += y
                right -= 2
            elif s[right:right+2] == 'ab':
                max_score += x
                left += 2
            else:
                left += 1
        
        return max_score
        