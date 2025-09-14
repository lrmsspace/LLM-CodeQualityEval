#https://leetcode.com/problems/cyclically-rotating-a-grid/
#You are given an m x n integer matrix grid​​​, where m and n are both even integers, and an integer k.
#The matrix is composed of several layers, which is shown in the below image, where each color is its own layer:
#A cyclic rotation of the matrix is done by cyclically rotating each layer in the matrix. To cyclically rotate a layer once, each element in the layer will take the place of the adjacent element in the counter-clockwise direction. An example rotation is shown below:
#Return the matrix after applying k cyclic rotations to it.
# 
#Example 1:
#Input: grid = [[40,10],[30,20]], k = 1
#Output: [[10,20],[40,30]]
#Explanation: The figures above represent the grid at every state.
#Example 2:
#  
#Input: grid = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]], k = 2
#Output: [[3,4,8,12],[2,11,10,16],[1,7,6,15],[5,9,13,14]]
#Explanation: The figures above represent the grid at every state.
# 
#Constraints:
#	m == grid.length
#	n == grid[i].length
#	2 <= m, n <= 50
#	Both m and n are even integers.
#	1 <= grid[i][j] <= 5000
#	1 <= k <= 109
class Solution(object):

    def rotateGrid(self, grid, k):

        """

        :type grid: List[List[int]]

        :type k: int

        :rtype: List[List[int]]

        """
        m, n = len(grid), len(grid[0])
        k %= 2 * (m + n) - 4

        # Split the grid into four quadrants
        quadrant1 = grid[:m // 2, :n // 2]
        quadrant2 = grid[:m // 2, n // 2:]
        quadrant3 = grid[m // 2:, :n // 2]
        quadrant4 = grid[m // 2:, n // 2:]
        
        # Rotate each quadrant
        for _ in range(k):
            # Rotate quadrant1
            quadrant1 = quadrant1.T[::-1]
            quadrant1 = quadrant1[1:, :-1]
            
            # Rotate quadrant2
            quadrant2 = quadrant2.T[::-1]
            quadrant2 = quadrant2[:-1, 1:]
            
            # Rotate quadrant3
            quadrant3 = quadrant3.T[::-1]
            quadrant3 = quadrant3[1:, :-1]
            
            # Rotate quadrant4
            quadrant4 = quadrant4.T[::-1]
            quadrant4 = quadrant4[:-1, 1:]
        
        # Combine the quadrants
        grid[:m // 2, :n // 2] = quadrant1
        grid[:m // 2, n // 2:] = quadrant2
        grid[m // 2:, :n // 2] = quadrant3
        grid[m // 2:, n // 2:] = quadrant4
        
        return grid