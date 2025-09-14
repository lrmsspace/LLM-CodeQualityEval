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
        m = len(grid)

        n = len(grid[0])

        for i in range(min(m, n) // 2):

            # Get the elements in the current layer

            elements = []

            for j in range(i, n - i):

                elements.append(grid[i][j])

            for j in range(i + 1, m - i):

                elements.append(grid[j][n - i - 1])

            for j in range(n - i - 2, i - 1, -1):

                elements.append(grid[m - i - 1][j])

            for j in range(m - i - 2, i, -1):

                elements.append(grid[j][i])

            # Rotate the elements

            k = k % len(elements)

            elements = elements[-k:] + elements[:-k]

            # Update the elements in the current layer

            for j in range(i, n - i):

                grid[i][j] = elements.pop(0)

            for j in range(i + 1, m - i):

                grid[j][n - i - 1] = elements.pop(0)

            for j in range(n - i - 2, i - 1, -1):

                grid[m - i - 1][j] = elements.pop(0)

            for j in range(m - i - 2, i, -1):

                grid[j][i] = elements.pop(0)

        return grid 


