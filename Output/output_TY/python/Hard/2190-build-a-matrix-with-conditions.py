#https://leetcode.com/problems/build-a-matrix-with-conditions/
#You are given a positive integer k. You are also given:
#	a 2D integer array rowConditions of size n where rowConditions[i] = [abovei, belowi], and
#	a 2D integer array colConditions of size m where colConditions[i] = [lefti, righti].
#The two arrays contain integers from 1 to k.
#You have to build a k x k matrix that contains each of the numbers from 1 to k exactly once. The remaining cells should have the value 0.
#The matrix should also satisfy the following conditions:
#	The number abovei should appear in a row that is strictly above the row at which the number belowi appears for all i from 0 to n - 1.
#	The number lefti should appear in a column that is strictly left of the column at which the number righti appears for all i from 0 to m - 1.
#Return any matrix that satisfies the conditions. If no answer exists, return an empty matrix.
# 
#Example 1:
#Input: k = 3, rowConditions = [[1,2],[3,2]], colConditions = [[2,1],[3,2]]
#Output: [[3,0,0],[0,0,1],[0,2,0]]
#Explanation: The diagram above shows a valid example of a matrix that satisfies all the conditions.
#The row conditions are the following:
#- Number 1 is in row 1, and number 2 is in row 2, so 1 is above 2 in the matrix.
#- Number 3 is in row 0, and number 2 is in row 2, so 3 is above 2 in the matrix.
#The column conditions are the following:
#- Number 2 is in column 1, and number 1 is in column 2, so 2 is left of 1 in the matrix.
#- Number 3 is in column 0, and number 2 is in column 1, so 3 is left of 2 in the matrix.
#Note that there may be multiple correct answers.
#Example 2:
#Input: k = 3, rowConditions = [[1,2],[2,3],[3,1],[2,3]], colConditions = [[2,1]]
#Output: []
#Explanation: From the first two conditions, 3 has to be below 1 but the third conditions needs 3 to be above 1 to be satisfied.
#No matrix can satisfy all the conditions, so we return the empty matrix.
# 
#Constraints:
#	2 <= k <= 400
#	1 <= rowConditions.length, colConditions.length <= 104
#	rowConditions[i].length == colConditions[i].length == 2
#	1 <= abovei, belowi, lefti, righti <= k
#	abovei != belowi
#	lefti != righti
class Solution(object):
    def buildMatrix(self, k, rowConditions, colConditions):
        """
        :type k: int
        :type rowConditions: List[List[int]]
        :type colConditions: List[List[int]]
        :rtype: List[List[int]]
        """
        row_graph = [[] for _ in range(k)]
        col_graph = [[] for _ in range(k)]
        for row, col in rowConditions:
            row_graph[row - 1].append(col - 1)
        for row, col in colConditions:
            col_graph[row - 1].append(col - 1)
        row_order = self.topological_sort(row_graph)
        col_order = self.topological_sort(col_graph)
        if row_order is None or col_order is None:
            return []
        row_map = {}
        for i, row in enumerate(row_order):
            row_map[row] = i
        col_map = {}
        for i, col in enumerate(col_order):
           col_map[col] = i
        result = [[0] * k for _ in range(k)]
        for row in range(k):
            for col in row_graph[row]:
                result[row][col] = result[row_map[col]][col]
            result[row][row_map[row]] = row + 1
        for col in range(k):
            for row in col_graph[col]:
                result[row][col] = result[row][col_map[row]]
            result[col_map[col]][col] = col + 1
        return result