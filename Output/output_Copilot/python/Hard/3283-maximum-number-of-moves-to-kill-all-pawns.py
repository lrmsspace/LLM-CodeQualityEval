# There is a 50 x 50 chessboard with one knight and some pawns on it. You are given two integers kx and ky where (kx, ky) denotes the position of the knight, and a 2D array positions where positions[i] = [xi, yi] denotes the position of the pawns on the chessboard.
# Alice and Bob play a turn-based game, where Alice goes first. In each player's turn:
# The player selects a pawn that still exists on the board and captures it with the knight in the fewest possible moves. Note that the player can select any pawn, it might not be one that can be captured in the least number of moves.
# In the process of capturing the selected pawn, the knight may pass other pawns without capturing them. Only the selected pawn can be captured in this turn.
# Alice is trying to maximize the sum of the number of moves made by both players until there are no more pawns on the board, whereas Bob tries to minimize them.
# Return the maximum total number of moves made during the game that Alice can achieve, assuming both players play optimally.
# Note that in one move, a chess knight has eight possible positions it can move to, as illustrated below. Each move is two cells in a cardinal direction, then one cell in an orthogonal direction.
# Example 1:
# Input: kx = 1, ky = 1, positions = [[0,0]]
# Output: 4
# Explanation:
# The knight takes 4 moves to reach the pawn at (0, 0).
# Example 2:
# Input: kx = 0, ky = 2, positions = [[1,1],[2,2],[3,3]]
# Output: 8
# Explanation:
# Alice picks the pawn at (2, 2) and captures it in two moves: (0, 2) -> (1, 4) -> (2, 2).
# Bob picks the pawn at (3, 3) and captures it in two moves: (2, 2) -> (4, 1) -> (3, 3).
# Alice picks the pawn at (1, 1) and captures it in four moves: (3, 3) -> (4, 1) -> (2, 2) -> (0, 3) -> (1, 1).
# Example 3:
# Input: kx = 0, ky = 0, positions = [[1,2],[2,4]]
# Output: 3
# Explanation:
# Alice picks the pawn at (2, 4) and captures it in two moves: (0, 0) -> (1, 2) -> (2, 4). Note that the pawn at (1, 2) is not captured.
# Bob picks the pawn at (1, 2) and captures it in one move: (2, 4) -> (1, 2).
# Constraints:
# 0 <= kx, ky <= 49
# 1 <= positions.length <= 15
# positions[i].length == 2
# 0 <= positions[i][0], positions[i][1] <= 49
# All positions[i] are unique.
# The input is generated such that positions[i] != [kx, ky] for all 0 <= i < positions.length.

class Solution(object):
    def maxMoves(self, kx, ky, positions):
        """
        :type kx: int
        :type ky: int
        :type positions: List[List[int]]
        :rtype: int
        """
        from collections import deque
        
        def bfs(start, target):
            directions = [(-2, -1), (-2, 1), (-1, -2), (-1, 2), (1, -2), (1, 2), (2, -1), (2, 1)]
            queue = deque([start])
            visited = set([start])
            moves = 0
            
            while queue:
                for _ in range(len(queue)):
                    x, y = queue.popleft()
                    if (x, y) == target:
                        return moves
                    for dx, dy in directions:
                        nx, ny = x + dx, y + dy
                        if 0 <= nx < 50 and 0 <= ny < 50 and (nx, ny) not in visited:
                            visited.add((nx, ny))
                            queue.append((nx, ny))
                moves += 1
            
            return float('inf')
        
        n = len(positions)
        dp = [[-1] * (1 << n) for _ in range(n + 1)]
        
        def dfs(mask):
            if mask == (1 << n) - 1:
                return 0
            
            if dp[mask][0] != -1:
                return dp[mask][0]
            
            max_moves = float('-inf')
            
            for i in range(n):
                if not (mask & (1 << i)):
                    next_mask = mask | (1 << i)
                    moves_to_capture = bfs((kx, ky), tuple(positions[i]))
                    total_moves = moves_to_capture + dfs(next_mask)
                    max_moves = max(max_moves, total_moves)
            
            dp[mask][0] = max_moves
            return max_moves
        
        return dfs(0)
        