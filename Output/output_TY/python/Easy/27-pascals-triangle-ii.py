#https://leetcode.com/problems/pascals-triangle-ii/
#Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.
#In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
# 
#Example 1:
#Input: rowIndex = 3
#Output: [1,3,3,1]
#Example 2:
#Input: rowIndex = 0
#Output: [1]
#Example 3:
#Input: rowIndex = 1
#Output: [1,1]
# 
#Constraints:
#	0 <= rowIndex <= 33
# 
#Follow up: Could you optimize your algorithm to use only O(rowIndex) extra space?
class Solution(object):
    def getRow(self, rowIndex):
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        if rowIndex == 0: return [1]
        if rowIndex == 1: return [1,1]
        res = [1,1]
        for i in range(2,rowIndex+1):
            temp = [1]
            for j in range(1,i):
                temp.append(res[j]+res[j-1])
            temp.append(1)
            res = temp
        return res