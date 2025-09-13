/**https://leetcode.com/problems/sliding-puzzle/ */
//On an 2 x 3 board, there are five tiles labeled from 1 to 5, and an empty square represented by 0. A move consists of choosing 0 and a 4-directionally adjacent number and swapping it.
//The state of the board is solved if and only if the board is [[1,2,3],[4,5,0]].
//Given the puzzle board board, return the least number of moves required so that the state of the board is solved. If it is impossible for the state of the board to be solved, return -1.
// 
//Example 1:
//Input: board = [[1,2,3],[4,0,5]]
//Output: 1
//Explanation: Swap the 0 and the 5 in one move.
//Example 2:
//Input: board = [[1,2,3],[5,4,0]]
//Output: -1
//Explanation: No number of moves will make the board solved.
//Example 3:
//Input: board = [[4,1,2],[5,0,3]]
//Output: 5
//Explanation: 5 is the smallest number of moves that solves the board.
//An example path:
//After move 0: [[4,1,2],[5,0,3]]
//After move 1: [[4,1,2],[0,5,3]]
//After move 2: [[0,1,2],[4,5,3]]
//After move 3: [[1,0,2],[4,5,3]]
//After move 4: [[1,2,0],[4,5,3]]
//After move 5: [[1,2,3],[4,5,0]]
// 
//Constraints:
//	board.length == 2
//	board[i].length == 3
//	0 <= board[i][j] <= 5
//	Each value board[i][j] is unique.
int slidingPuzzle(int** board, int boardSize, int* boardColSize) {
     // Define the target state
     const char* target = "123450";
    
     // Convert initial board to string
     char initial[7];
     boardToString(board, initial);
     
     // Initialize BFS
     Queue* queue = createQueue(1000);
     State startState;
     strcpy(startState.board, initial);
     startState.zeroPos = findZeroPos(startState.board);
     startState.moves = 0;
     enqueue(queue, startState);
     
     // Use a hash set to keep track of visited states
     char visited[1000000][7];  // Assuming a reasonable upper bound
     int visitedCount = 0;
     strcpy(visited[visitedCount++], initial);
     
     // Define possible moves (up, down, left, right)
     // For a 2x3 board, the adjacency is:
     // 0 1 2
     // 3 4 5
     int moves[6][4] = {
         {1, 3, -1, -1},  // Possible moves from position 0
         {0, 2, 4, -1},   // Possible moves from position 1
         {1, 5, -1, -1},  // Possible moves from position 2
         {0, 4, -1, -1},  // Possible moves from position 3
         {1, 3, 5, -1},   // Possible moves from position 4
         {2, 4, -1, -1}   // Possible moves from position 5
     };
     
     // BFS
     while (!isEmpty(queue)) {
         State current = dequeue(queue);
         
         // Check if we've reached the target
         if (strcmp(current.board, target) == 0) {
             free(queue->states);
             free(queue);
             return current.moves;
         }
         
         // Try all possible moves
         for (int i = 0; i < 4 && moves[current.zeroPos][i] != -1; i++) {
             int newZeroPos = moves[current.zeroPos][i];
             
             // Create a new state by swapping
             State newState = current;
             newState.board[current.zeroPos] = current.board[newZeroPos];
             newState.board[newZeroPos] = '0';
             newState.zeroPos = newZeroPos;
             newState.moves++;
             
             // Check if this state has been visited
             bool isVisited = false;
             for (int j = 0; j < visitedCount; j++) {
                 if (strcmp(visited[j], newState.board) == 0) {
                     isVisited = true;
                     break;
                 }
             }
             
             if (!isVisited) {
                 strcpy(visited[visitedCount++], newState.board);
                 enqueue(queue, newState);
             }
         }
     }
     
     // If we've exhausted all possibilities and haven't found the target
     free(queue->states);
     free(queue);
     return -1; 
}