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
        m, n = len(heightMap), len(heightMap[0])
        if m == 0 or n == 0:
            return 0
        visited = [[False] * n for _ in range(m)]
        heap = []
        for i in range(m):
            heapq.heappush(heap, (heightMap[i][0], i, 0))
            heapq.heappush(heap, (heightMap[i][n-1], i, n-1))
            visited[i][0] = visited[i][n-1] = True
        for j in range(1, n-1):
            heapq.heappush(heap, (heightMap[0][j], 0, j))
            heapq.heappush(heap, (heightMap[m-1][j], m-1, j))
            visited[0][j] = visited[m-1][j] = True
        water = 0
        while heap:
            height, i, j = heapq.heappop(heap)
            for di, dj in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                ni, nj = i + di, j + dj
                if 0 <= ni < m and 0 <= nj < n and not visited[ni][nj]:
                    visited[ni][nj] = True
                    heapq.heappush(heap, (max(height, heightMap[ni][nj]), ni, nj))
                    water += max(0, height - heightMap[ni][nj])
        return water