#https://leetcode.com/problems/move-pieces-to-obtain-a-string/
#You are given two strings start and target, both of length n. Each string consists only of the characters 'L', 'R', and '_' where:
#	The characters 'L' and 'R' represent pieces, where a piece 'L' can move to the left only if there is a blank space directly to its left, and a piece 'R' can move to the right only if there is a blank space directly to its right.
#	The character '_' represents a blank space that can be occupied by any of the 'L' or 'R' pieces.
#Return true if it is possible to obtain the string target by moving the pieces of the string start any number of times. Otherwise, return false.
# 
#Example 1:
#Input: start = "_L__R__R_", target = "L______RR"
#Output: true
#Explanation: We can obtain the string target from start by doing the following moves:
#- Move the first piece one step to the left, start becomes equal to "L___R__R_".
#- Move the last piece one step to the right, start becomes equal to "L___R___R".
#- Move the second piece three steps to the right, start becomes equal to "L______RR".
#Since it is possible to get the string target from start, we return true.
#Example 2:
#Input: start = "R_L_", target = "__LR"
#Output: false
#Explanation: The 'R' piece in the string start can move one step to the right to obtain "_RL_".
#After that, no pieces can move anymore, so it is impossible to obtain the string target from start.
#Example 3:
#Input: start = "_R", target = "R_"
#Output: false
#Explanation: The piece in the string start can move only to the right, so it is impossible to obtain the string target from start.
# 
#Constraints:
#	n == start.length == target.length
#	1 <= n <= 105
#	start and target consist of the characters 'L', 'R', and '_'.
class Solution(object):
    def canChange(self, start, target):
        """
        :type start: str
        :type target: str
        :rtype: bool
        """
        # Initialize two pointers for start and target
        i, j = 0, 0
        
        # Iterate through both strings simultaneously
        while i < len(start) and j < len(target):
            # If the characters at current positions are not equal, move the pointer to the next character
            if start[i] != target[j]:
                i += 1
                j += 1
                continue
            
            # If the characters are equal, check if they are either 'L' or 'R'
            if start[i] == 'L' and target[j] == 'R':
                # If the current 'L' piece is directly to the right of the current 'R' piece, move the 'R' piece to the left
                if j < len(target) - 1 and target[j+1] == 'L':
                    j += 1
                else:
                    return False
            
            elif start[i] == 'R' and target[j] == 'L':
                # If the current 'R' piece is directly to the left of the current 'L' piece, move the 'L' piece to the right
                if j > 0 and target[j-1] == 'R':
                    j -= 1
                else:
                    return False
            
            # Move both pointers to the next character
            i += 1
            j += 1
        
        # If there are any remaining characters in either string, return False
        return i == len(start) and j == len(target)