#https://leetcode.com/problems/trapping-rain-water-ii/
#Given an m x n integer matrix heightMap representing the height of each unit cell in a 2D elevation map, return the volume of water it can trap after raining.
# 
#Example 1:
#Input: heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
#Output: 4
#Explanation: After the rain, water is trapped between the blocks.
#We have two small ponds 1 and 3 units trapped.
#The total volume of water trapped is 4.
#Example 2:
#Input: heightMap = [[3,3,3,3,3],[3,2,2,2,3],[3,2,1,2,3],[3,2,2,2,3],[3,3,3,3,3]]
#Output: 10
# 
#Constraints:
#	m == heightMap.length
#	n == heightMap[i].length
#	1 <= m, n <= 200
#	0 <= heightMap[i][j] <= 2 * 104
class Solution(object):
    def trapRainWater(self, heightMap):
        """
        :type heightMap: List[List[int]]
        :rtype: int
        """
        if not heightMap:
            return 0
        m, n = len(heightMap), len(heightMap[0])
        heap = []
        visited = [[False for _ in range(n)] for _ in range(m)]
        for i in range(m):
            for j in range(n):
                if i == 0 or i == m - 1 or j == 0 or j == n - 1:
                    heapq.heappush(heap, (heightMap[i][j], i, j))
                    visited[i][j] = True
        res = 0
        while heap:
            height, i, j = heapq.heappop(heap)
            for x, y in ((i + 1, j), (i - 1, j), (i, j + 1), (i, j - 1)):
                if 0 <= x < m and 0 <= y < n and not visited[x][y]:
                    res += max(0, height - heightMap[x][y])
                    heapq.heappush(heap, (max(height, heightMap[x][y]), x, y))
                    visited[x][y] = True
        return res
        
        