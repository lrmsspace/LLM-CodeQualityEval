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
        pq = []
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        for i in range(m):
            for j in range(n):
                if i == 0 or j == 0 or i == m - 1 or j == n - 1:
                    pq.append((heightMap[i][j], i, j))
                    heightMap[i][j] = -1
        ans = 0
        while pq:
            h, x, y = heapq.heappop(pq)
            for dx, dy in directions:
                nx, ny = x + dx, y + dy
                if nx < 0 or ny < 0 or nx >= m or ny >= n or heightMap[nx][ny] == -1:
                    continue
                if heightMap[nx][ny] < h:
                    ans += h - heightMap[nx][ny]
                heapq.heappush(pq, (max(heightMap[nx][ny], h), nx, ny))
                heightMap[nx][ny] = -1
        return ans

