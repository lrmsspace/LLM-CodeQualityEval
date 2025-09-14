#https://leetcode.com/problems/contain-virus/
#A virus is spreading rapidly, and your task is to quarantine the infected area by installing walls.
#The world is modeled as an m x n binary grid isInfected, where isInfected[i][j] == 0 represents uninfected cells, and isInfected[i][j] == 1 represents cells contaminated with the virus. A wall (and only one wall) can be installed between any two 4-directionally adjacent cells, on the shared boundary.
#Every night, the virus spreads to all neighboring cells in all four directions unless blocked by a wall. Resources are limited. Each day, you can install walls around only one region (i.e., the affected area (continuous block of infected cells) that threatens the most uninfected cells the following night). There will never be a tie.
#Return the number of walls used to quarantine all the infected regions. If the world will become fully infected, return the number of walls used.
# 
#Example 1:
#Input: isInfected = [[0,1,0,0,0,0,0,1],[0,1,0,0,0,0,0,1],[0,0,0,0,0,0,0,1],[0,0,0,0,0,0,0,0]]
#Output: 10
#Explanation: There are 2 contaminated regions.
#On the first day, add 5 walls to quarantine the viral region on the left. The board after the virus spreads is:
#On the second day, add 5 walls to quarantine the viral region on the right. The virus is fully contained.
#Example 2:
#Input: isInfected = [[1,1,1],[1,0,1],[1,1,1]]
#Output: 4
#Explanation: Even though there is only one cell saved, there are 4 walls built.
#Notice that walls are only built on the shared boundary of two different cells.
#Example 3:
#Input: isInfected = [[1,1,1,0,0,0,0,0,0],[1,0,1,0,1,1,1,1,1],[1,1,1,0,0,0,0,0,0]]
#Output: 13
#Explanation: The region on the left only builds two new walls.
# 
#Constraints:
#	m == isInfected.length
#	n == isInfected[i].length
#	1 <= m, n <= 50
#	isInfected[i][j] is either 0 or 1.
#	There is always a contiguous viral region throughout the described process that will infect strictly more uncontaminated squares in the next round.
class Solution(object):
    def containVirus(self, isInfected):
        """
        :type isInfected: List[List[int]]
        :rtype: int
        """
        # 方向数组，表示上下左右四个方向
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        m, n = len(isInfected), len(isInfected[0])
        walls = 0     
        while True:
            # 记录每个区域的感染区域和墙壁数量
            regions = []
            walls_needed = []
            visited = [[False] * n for _ in range(m)]

            # BFS 遍历每个感染区域
            for i in range(m):
                for j in range(n):
                    if isInfected[i][j] == 1 and not visited[i][j]:
                        region = set()
                        queue = [(i, j)]
                        walls_count = 0
                        while queue:
                            x, y = queue.pop(0)
                            if (x, y) in region:
                                continue
                            region.add((x, y))
                            visited[x][y] = True
                            for dx, dy in directions:
                                nx, ny = x + dx, y + dy
                                if 0 <= nx < m and 0 <= ny < n:
                                    if isInfected[nx][ny] == 1 and not visited[nx][ny]:
                                        queue.append((nx, ny))
                                    elif isInfected[nx][ny] == 0:
                                        walls_count += 1
                        regions.append(region)
                        walls_needed.append(walls_count)

            # 如果没有感染区域，退出循环
            if not regions:
                break

            # 找到需要最多墙壁的区域
            max_walls_index = walls_needed.index(max(walls_needed))
            walls += walls_needed[max_walls_index]

            # 更新感染区域和墙壁数量
            for i in range(len(regions)):
                if i != max_walls_index:
                    for x, y in regions[i]:
                        isInfected[x][y] = 0
                else:
                    for x, y in regions[i]:
                        isInfected[x][y] = 1
                    for dx, dy in directions:
                        nx, ny = regions[i].pop()
                        if 0 <= nx < m and 0 <= ny < n:
                            isInfected[nx][ny] = 1
                            for j in range(len(regions)):
                                if j != max_walls_index and (nx, ny) in regions[j]:
                                    regions[j].remove((nx, ny))
                                    walls_needed[j] -= 1
            # 更新感染区域
            regions = [region for i, region in enumerate(regions) if i != max_walls_index]
            walls_needed = [walls_needed[i] for i in range(len(walls_needed)) if i != max_walls_index]
        return walls