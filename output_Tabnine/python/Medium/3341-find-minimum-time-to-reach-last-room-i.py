# There is a dungeon with n x m rooms arranged as a grid.
# You are given a 2D array moveTime of size n x m, where moveTime[i][j] represents the minimum time in seconds after which the room opens and can be moved to. You start from the room (0, 0) at time t = 0 and can move to an adjacent room. Moving between adjacent rooms takes exactly one second.
# Return the minimum time to reach the room (n - 1, m - 1).
# Two rooms are adjacent if they share a common wall, either horizontally or vertically.
# Example 1:
# Input: moveTime = [[0,4],[4,4]]
# Output: 6
# Explanation:
# The minimum time required is 6 seconds.
# At time t == 4, move from room (0, 0) to room (1, 0) in one second.
# At time t == 5, move from room (1, 0) to room (1, 1) in one second.
# Example 2:
# Input: moveTime = [[0,0,0],[0,0,0]]
# Output: 3
# Explanation:
# The minimum time required is 3 seconds.
# At time t == 0, move from room (0, 0) to room (1, 0) in one second.
# At time t == 1, move from room (1, 0) to room (1, 1) in one second.
# At time t == 2, move from room (1, 1) to room (1, 2) in one second.
# Example 3:
# Input: moveTime = [[0,1],[1,2]]
# Output: 3
# Constraints:
# 2 <= n == moveTime.length <= 50
# 2 <= m == moveTime[i].length <= 50
# 0 <= moveTime[i][j] <= 109

class Solution(object):
    def minTimeToReach(self, moveTime):
        """
        :type moveTime: List[List[int]]
        :rtype: int
        """
        n = len(moveTime)
        m = len(moveTime[0])
        
        # Initialize a priority queue with the starting room
        queue = [(0, 0, 0)]  # (time, row, col)
        
        # Create a set to keep track of visited rooms
        visited = set([(0, 0)])
        
        while queue:
            time, row, col = heapq.heappop(queue)
            
            # If we reached the target room, return the time
            if row == n - 1 and col == m - 1:
                return time
            
            # Explore adjacent rooms
            for dr, dc in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                new_row, new_col = row + dr, col + dc
                
                # Check if the new room is within the grid and not visited
                if 0 <= new_row < n and 0 <= new_col < m and (new_row, new_col) not in visited:
                    visited.add((new_row, new_col))
                    heapq.heappush(queue, (time + moveTime[new_row][new_col], new_row, new_col))
        return -1  # If no path is found
        