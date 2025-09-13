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
        dp = [[0] * (len(s) + 1) for _ in range(len(s) + 1)]
        for i in range(len(s) - 1, -1, -1):
            for j in range(i + 1, len(s) + 1):
                if s[i] == 'a' and s[j - 1] == 'b':
                    dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + x)
                if s[i] == 'b' and s[j - 1] == 'a':
                    dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + y)
                dp[i][j] = max(dp[i][j], dp[i + 1][j])
        return dp[0][-1]
        
