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
        m, n = len(isInfected), len(isInfected[0])
        directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        walls = 0
        
        while True:
            fresh_region = []
            for i in range(m):
                for j in range(n):
                    if isInfected[i][j] == 1:
                        fresh_region.append((i, j))
            if not fresh_region:
                break
            fresh_region.sort(key=lambda x: (x[0] + x[1], x[0], x[1]))
            x, y = fresh_region[0]
            boundary = []
            for dx, dy in directions:
                nx, ny = x + dx, y + dy
                if 0 <= nx < m and 0 <= ny < n and isInfected[nx][ny] == 0:
                    boundary.append((nx, ny))
            if boundary:
                walls += len(boundary)
                for nx, ny in boundary:
                    isInfected[nx][ny] = 2
            for x, y in fresh_region:
                for dx, dy in directions:
                    nx, ny = x + dx, y + dy
                    if 0 <= nx < m and 0 <= ny < n and isInfected[nx][ny] == 0:
                        isInfected[nx][ny] = 1
            for x in range(m):
                for y in range(n):
                    if isInfected[x][y] == 2:
                        isInfected[x][y] = 0
        return walls
