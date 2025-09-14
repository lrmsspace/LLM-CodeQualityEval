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
        # Define the goal state
        goal = [[1,2,3],[4,5,0]]
        
        # Define the empty cell position
        empty_row, empty_col = self.find_empty_cell(board)
        
        # Define the possible moves
        moves = [(0,1), (0,-1), (1,0), (-1,0)]
        
        # Define the visited states
        visited = set()
        
        # Define the queue for BFS
        queue = [(board, 0)]
        
        # BFS search
        while queue:
            current_board, moves_count = queue.pop(0)
            
            # If the current state is the goal state, return the number of moves
            if current_board == goal:
                return moves_count
            
            # Check if the current state has been visited before
            if tuple(map(tuple, current_board)) in visited:
                continue
            
            # Mark the current state as visited
            visited.add(tuple(map(tuple, current_board)))
            
            # Generate the next states based on the possible moves
            for dr, dc in moves:
                new_row, new_col = empty_row + dr, empty_col + dc
                
                # If the new cell is valid
                if 0 <= new_row < len(board) and 0 <= new_col < len(board[0]):
                    # Swap the empty cell with the new cell
                    current_board[empty_row][empty_col], current_board[new_row][new_col] = current_board[new_row][new_col], current_board[empty_row][empty_col]
                    
                    # Add the new state to the queue
                    queue.append((current_board, moves_count + 1))
                    
                    # Undo the swap
                    current_board[empty_row][empty_col], current_board[new_row][new_col] = current_board[new_row][new_col], current_board[empty_row][empty_col]
        
        # If no solution is found, return -1
        
        