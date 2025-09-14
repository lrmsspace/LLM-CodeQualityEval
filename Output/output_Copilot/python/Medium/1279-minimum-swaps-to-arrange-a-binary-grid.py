#https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/
#Given an n x n binary grid, in one step you can choose two adjacent rows of the grid and swap them.
#A grid is said to be valid if all the cells above the main diagonal are zeros.
#Return the minimum number of steps needed to make the grid valid, or -1 if the grid cannot be valid.
#The main diagonal of a grid is the diagonal that starts at cell (1, 1) and ends at cell (n, n).
# 
#Example 1:
#Input: grid = [[0,0,1],[1,1,0],[1,0,0]]
#Output: 3
#Example 2:
#Input: grid = [[0,1,1,0],[0,1,1,0],[0,1,1,0],[0,1,1,0]]
#Output: -1
#Explanation: All rows are similar, swaps have no effect on the grid.
#Example 3:
#Input: grid = [[1,0,0],[1,1,0],[1,1,1]]
#Output: 0
# 
#Constraints:
#	n == grid.length == grid[i].length
#	1 <= n <= 200
#	grid[i][j] is either 0 or 1
class Solution(object):
    def minSwaps(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        n = len(grid)
        # 计算每一行末尾0的个数
        zeros = [0] * n
        for i in range(n):
            for j in range(n-1, -1, -1):
                if grid[i][j] == 0:
                    zeros[i] += 1
                else:
                    break
        # 计算每一行需要交换的次数
        swaps = 0
        for i in range(n):
            # 找到第i行需要交换的行数
            count = 0
            for j in range(i, n):
                if zeros[j] >= n-i-1:
                    count += 1
                if count > 0:
                    break
            if count == 0:
                return -1
            swaps += count - 1
            # 更新后面的行的末尾0的个数
            for j in range(i, i+count):
                zeros[j] -= 1
        return swaps        