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
        from collections import deque
        
        # Convert the board to a string for easier manipulation
        start = ''.join(str(num) for row in board for num in row)
        target = '123450'
        
        # Define the possible moves (index changes)
        moves = [(1, 3), (-1, -3), (1, -1), (-1, 1)]
        
        # Initialize the queue and visited set
        queue = deque([(start, start.index('0'), 0)])
        visited = set([start])
        while queue:
            state, zero_pos, steps = queue.popleft()
            
            # Check if the current state is the target
            if state == target:
                return steps
            
            # Generate possible next states
            for move in moves:
                new_zero_pos = zero_pos + move[0] * 3 + move[1]
            
            # Check if the move is valid
            if 0 <= new_zero_pos < 6 and not (zero_pos % 3 == 2 and new_zero_pos % 3 == 0) and not (zero_pos % 3 == 0 and new_zero_pos % 3 == 2):
                new_state = list(state)
                new_state[zero_pos], new_state[new_zero_pos] = new_state[new_zero_pos], new_state[zero_pos]
                new_state = ''.join(new_state)
                
                if new_state not in visited:
                    visited.add(new_state)
                    queue.append((new_state, new_zero_pos, steps + 1))
        
        return -1   