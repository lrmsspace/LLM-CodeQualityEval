#https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/
#You are given a 2D integer grid of size m x n and an integer x. In one operation, you can add x to or subtract x from any element in the grid.
#A uni-value grid is a grid where all the elements of it are equal.
#Return the minimum number of operations to make the grid uni-value. If it is not possible, return -1.
# 
#Example 1:
#Input: grid = [[2,4],[6,8]], x = 2
#Output: 4
#Explanation: We can make every element equal to 4 by doing the following: 
#- Add x to 2 once.
#- Subtract x from 6 once.
#- Subtract x from 8 twice.
#A total of 4 operations were used.
#Example 2:
#Input: grid = [[1,5],[2,3]], x = 1
#Output: 5
#Explanation: We can make every element equal to 3.
#Example 3:
#Input: grid = [[1,2],[3,4]], x = 2
#Output: -1
#Explanation: It is impossible to make every element equal.
# 
#Constraints:
#	m == grid.length
#	n == grid[i].length
#	1 <= m, n <= 105
#	1 <= m * n <= 105
#	1 <= x, grid[i][j] <= 104
class Solution(object):
    def minOperations(self, grid, x):
        """
        :type grid: List[List[int]]
        :type x: int
        :rtype: int
        """
        # 计算所有元素的平均值
        total_sum = 0
        count = 0
        for row in grid:
            for num in row:
                total_sum += num
                count += 1
        
        # 如果总和不能被元素个数整除，则返回 -1
        if total_sum % count != 0:
            return -1
        
        target = total_sum // count
        
        # 计算操作次数
        operations = 0
        for row in grid:
            for num in row:
                diff = abs(num - target)
                if diff % x != 0:
                    return -1
                operations += diff // x
        
        return operations        