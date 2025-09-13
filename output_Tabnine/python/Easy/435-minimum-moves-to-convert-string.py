#https://leetcode.com/problems/minimum-moves-to-convert-string/
#You are given a string s consisting of n characters which are either 'X' or 'O'.
#A move is defined as selecting three consecutive characters of s and converting them to 'O'. Note that if a move is applied to the character 'O', it will stay the same.
#Return the minimum number of moves required so that all the characters of s are converted to 'O'.
# 
#Example 1:
#Input: s = "XXX"
#Output: 1
#Explanation: XXX -> OOO
#We select all the 3 characters and convert them in one move.
#Example 2:
#Input: s = "XXOX"
#Output: 2
#Explanation: XXOX -> OOOX -> OOOO
#We select the first 3 characters in the first move, and convert them to 'O'.
#Then we select the last 3 characters and convert them so that the final string contains all 'O's.
#Example 3:
#Input: s = "OOOO"
#Output: 0
#Explanation: There are no 'X's in s to convert.
# 
#Constraints:
#	3 <= s.length <= 1000
#	s[i] is either 'X' or 'O'.
class Solution(object):
    def minimumMoves(self, s):
        """
        :type s: str
        :rtype: int
        """
        # Count the number of 'X's and 'O's
        x_count, o_count = s.count('X'), s.count('O')
        
        # If there are no 'X's, return 0
        if x_count == 0:
            return 0
        
        # If the number of 'X's is odd, return -1 (impossible to convert all 'O's)
        if x_count % 2!= 0:
            return -1
        
        # Calculate the minimum number of moves required
        return (x_count // 2) * 3 + min(x_count, o_count) * 2
        