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
        
        # Step 1: Precompute shortest distances between all pairs of pawns and knight using BFS
        dir_knight = [(-2,-1), (-1,-2), (-2,1), (-1,2), (2,-1), (1,-2), (2,1), (1,2)]
        
        def in_board(x, y):
            return 0 <= x < 50 and 0 <= y < 50
        
        # Build distance from (x1, y1) to (x2, y2)
        def bfs_dist(x1, y1, x2, y2):
            visited = [[False]*50 for _ in range(50)]
            q = deque()
            q.append((x1, y1, 0))
            visited[x1][y1] = True
            
            while q:
                x, y, d = q.popleft()
                if x == x2 and y == y2:
                    return d
                for dx, dy in dir_knight:
                    nx, ny = x + dx, y + dy
                    if in_board(nx, ny) and not visited[nx][ny]:
                        visited[nx][ny] = True
                        q.append((nx, ny, d+1))
            return float('inf')  # unreachable

        n = len(positions)
        pawn_pos = [(kx, ky)] + positions  # index 0 is the initial knight position
        m = n + 1  # total nodes including knight start

        # dist[i][j] = min steps from i-th node to j-th node
        dist = [[0]*m for _ in range(m)]
        for i in range(m):
            for j in range(i+1, m):
                d = bfs_dist(pawn_pos[i][0], pawn_pos[i][1], pawn_pos[j][0], pawn_pos[j][1])
                dist[i][j] = dist[j][i] = d

        memo = dict()

        def dfs(pos_idx, mask):
            if mask == 0:  # no pawns left
                return 0
            key = (pos_idx, mask)
            if key in memo:
                return memo[key]

            res = 0 if len(bin(mask)) - bin(mask).count("0") % 2 == 0 else float('inf')
            turn = bin(mask).count("1") % 2  # 0 -> Alice (max), 1 -> Bob (min)

            for i in range(n):
                if (mask >> i) & 1:
                    new_mask = mask ^ (1 << i)
                    cost = dist[pos_idx][i+1]
                    sub = dfs(i+1, new_mask)
                    total = cost + sub

                    if turn == 0:  # Alice's turn: maximize
                        res = max(res, total)
                    else:  # Bob's turn: minimize
                        res = min(res, total)

            memo[key] = res
            return res

        full_mask = (1 << n) - 1
        return dfs(0, full_mask)
        