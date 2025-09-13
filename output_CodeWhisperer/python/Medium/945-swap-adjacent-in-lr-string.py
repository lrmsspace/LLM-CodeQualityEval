#https://leetcode.com/problems/swap-adjacent-in-lr-string/
#In a string composed of 'L', 'R', and 'X' characters, like "RXXLRXRXL", a move consists of either replacing one occurrence of "XL" with "LX", or replacing one occurrence of "RX" with "XR". Given the starting string start and the ending string result, return True if and only if there exists a sequence of moves to transform start to result.
# 
#Example 1:
#Input: start = "RXXLRXRXL", result = "XRLXXRRLX"
#Output: true
#Explanation: We can transform start to result following these steps:
#RXXLRXRXL ->
#XRXLRXRXL ->
#XRLXRXRXL ->
#XRLXXRRXL ->
#XRLXXRRLX
#Example 2:
#Input: start = "X", result = "L"
#Output: false
# 
#Constraints:
#	1 <= start.length <= 104
#	start.length == result.length
#	Both start and result will only consist of characters in 'L', 'R', and 'X'.
class Solution(object):
    def canTransform(self, start, result):
        """
        :type start: str
        :type result: str
        :rtype: bool
        """
        if len(start) != len(result):
            return False
        
        if start.replace('X', '') != result.replace('X', ''):
            return False
        
        j = 0
        for i in range(len(start)):
            if start[i] == 'L':
                while j < len(result) and result[j] == 'L':
                    j += 1
                if i < j:
                    return False
                j += 1
            elif start[i] == 'R':
                while j < len(result) and result[j] == 'R':
                    j += 1
                if i > j:
                    return False
                j += 1
        
        return True
        