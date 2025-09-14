# You are given a 2D character grid matrix of size m x n, represented as an array of strings, where matrix[i][j] represents the cell at the intersection of the ith row and jth column. Each cell is one of the following:
# '.' representing an empty cell.
# '#' representing an obstacle.
# An uppercase letter ('A'-'Z') representing a teleportation portal.
# You start at the top-left cell (0, 0), and your goal is to reach the bottom-right cell (m - 1, n - 1). You can move from the current cell to any adjacent cell (up, down, left, right) as long as the destination cell is within the grid bounds and is not an obstacle.
# If you step on a cell containing a portal letter and you haven't used that portal letter before, you may instantly teleport to any other cell in the grid with the same letter. This teleportation does not count as a move, but each portal letter can be used at most once during your journey.
# Return the minimum number of moves required to reach the bottom-right cell. If it is not possible to reach the destination, return -1.
# Example 1:
# Input: matrix = ["A..",".A.","..."]
# Output: 2
# Explanation:
# Before the first move, teleport from (0, 0) to (1, 1).
# In the first move, move from (1, 1) to (1, 2).
# In the second move, move from (1, 2) to (2, 2).
# Example 2:
# Input: matrix = [".#...",".#.#.",".#.#.","...#."]
# Output: 13
# Explanation:
# Constraints:
# 1 <= m == matrix.length <= 103
# 1 <= n == matrix[i].length <= 103
# matrix[i][j] is either '#', '.', or an uppercase English letter.
# matrix[0][0] is not an obstacle.

class Solution(object):
    def minMoves(self, matrix):
        """
        :type matrix: List[str]
        :rtype: int
        """
        from collections import defaultdict, deque

        m, n = len(matrix), len(matrix[0])
        portals = defaultdict(list)
        visited = set()
        queue = deque([(0, 0, 0)])    
        visited.add((0, 0))
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        while queue:
            x, y, moves = queue.popleft()
            
            # If we reached the bottom-right corner, return the moves
            if x == m - 1 and y == n - 1:
                return moves
            
            # Check if the current cell is a portal
            if matrix[x][y].isupper():
                portal_letter = matrix[x][y]
                for px, py in portals[portal_letter]:
                    if (px, py) not in visited:
                        visited.add((px, py))
                        queue.append((px, py, moves))
                portals[portal_letter].append((x, y))
            
            # Explore adjacent cells
            for dx, dy in directions:
                nx, ny = x + dx, y + dy
                
                if 0 <= nx < m and 0 <= ny < n and matrix[nx][ny] != '#':
                    if (nx, ny) not in visited:
                        visited.add((nx, ny))
                        queue.append((nx, ny, moves + 1))
        return -1
        