#https://leetcode.com/problems/sliding-puzzle/
#On an 2 x 3 board, there are five tiles labeled from 1 to 5, and an empty square represented by 0. A move consists of choosing 0 and a 4-directionally adjacent number and swapping it.
#The state of the board is solved if and only if the board is [[1,2,3],[4,5,0]].
#Given the puzzle board board, return the least number of moves required so that the state of the board is solved. If it is impossible for the state of the board to be solved, return -1.
# 
#Example 1:
#Input: board = [[1,2,3],[4,0,5]]
#Output: 1
#Explanation: Swap the 0 and the 5 in one move.
#Example 2:
#Input: board = [[1,2,3],[5,4,0]]
#Output: -1
#Explanation: No number of moves will make the board solved.
#Example 3:
#Input: board = [[4,1,2],[5,0,3]]
#Output: 5
#Explanation: 5 is the smallest number of moves that solves the board.
#An example path:
#After move 0: [[4,1,2],[5,0,3]]
#After move 1: [[4,1,2],[0,5,3]]
#After move 2: [[0,1,2],[4,5,3]]
#After move 3: [[1,0,2],[4,5,3]]
#After move 4: [[1,2,0],[4,5,3]]
#After move 5: [[1,2,3],[4,5,0]]
# 
#Constraints:
#	board.length == 2
#	board[i].length == 3
#	0 <= board[i][j] <= 5
#	Each value board[i][j] is unique.
class Solution(object):
    def slidingPuzzle(self, board):
        """
        :type board: List[List[int]]
        :rtype: int
        """
        def get_neighbors(state):
            """
            Get the neighbors of the current state.
            """
            neighbors = []
            zero_index = state.index(0)
            row, col = zero_index // 3, zero_index % 3
            for dr, dc in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                new_row, new_col = row + dr, col + dc
                if 0 <= new_row < 2 and 0 <= new_col < 3:
                    new_index = new_row * 3 + new_col
                    new_state = list(state)
                    new_state[zero_index], new_state[new_index] = new_state[new_index], new_state[zero_index]
                    neighbors.append(tuple(new_state))
            return neighbors

        def get_state(board):
            """
            Convert the board to a tuple.
            """
            return tuple(sum(board, []))

        def bfs(start_state):
            """
            Perform BFS to find the minimum number of moves required to solve the puzzle.
            """
            queue = collections.deque([(start_state, 0)])
            visited = set([start_state])
            while queue:
                state, moves = queue.popleft()
                if state == target_state:
                    return moves
                for neighbor in get_neighbors(state):
                    if neighbor not in visited:
                        visited.add(neighbor)
                        queue.append((neighbor, moves + 1))
            return -1

        start_state = get_state(board)
        target_state = (1, 2, 3, 4, 5, 0)
        return bfs(start_state)
        