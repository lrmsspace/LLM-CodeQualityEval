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
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, a, b, c, d, e, f, g, h, ans, flag, temp, count, sum, max, min, index;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int visited[1000000] = {0};
    int queue[1000000] = {0};
    int step[1000000] = {0};
    int start = 0, end = 0;
    int target = 123450;
    int cur = 0;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            cur = cur * 10 + board[i][j];
        }
    }
    if (cur == target) {
        return 0;
    }
    queue[end] = cur;
    step[end] = 0;
    visited[cur] = 1;
    end++;
    while (start < end) {   
        cur = queue[start];
        int curStep = step[start];
        start++;
        
        // Convert current state to 2D board and find position of 0
        int board2D[2][3];
        int zeroX = 0, zeroY = 0;
        int tempCur = cur;
        for (i = 1; i >= 0; i--) {
            for (j = 2; j >= 0; j--) {
                board2D[i][j] = tempCur % 10;
                if (board2D[i][j] == 0) {
                    zeroX = i;
                    zeroY = j;
                }
                tempCur /= 10;
            }
        }

        // Try all 4 possible moves
        for (i = 0; i < 4; i++) {
            int newX = zeroX + dx[i];
            int newY = zeroY + dy[i];
            if (newX >= 0 && newX < 2 && newY >= 0 && newY < 3) {
                // Swap 0 with the adjacent number
                int newBoard2D[2][3];
                memcpy(newBoard2D, board2D, sizeof(board2D));
                newBoard2D[zeroX][zeroY] = newBoard2D[newX][newY];
                newBoard2D[newX][newY] = 0;

                // Convert new board state to integer
                int newCur = 0;
                for (j = 0; j < 2; j++) {
                    for (k = 0; k < 3; k++) {
                        newCur = newCur * 10 + newBoard2D[j][k];
                    }
                }

                // Check if the new state is the target
                if (newCur == target) {
                    return curStep + 1;
                }

                // If not visited, add to queue
                if (!visited[newCur]) {
                    visited[newCur] = 1;
                    queue[end] = newCur;
                    step[end] = curStep + 1;
                    end++;
                }
            }
        }
    }

    return -1;
}