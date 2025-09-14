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
    int target[] = {1,2,3,4,5,0};
    int steps = 0;
    int visited[10000] = {0};
    int queue[10000];
    int front = 0, rear = 0;
    int cur = 0, i, j, k, zero;
    for (i = 0; i < 2; i++)
        for (j = 0; j < 3; j++)
            cur = cur * 10 + board[i][j];
    queue[rear++] = cur;
    visited[cur] = 1;
    while (front < rear) {
        cur = queue[front++];
        if (cur == *(int*)target) return steps;
        zero = cur % 10;
        for (i = 0; i < 6; i++) {
            if (zero != target[i]) continue;
            for (j = 0; j < 4; j++) {
                k = (i + j * (j % 2 == 0 ? 3 : 1)) % 6;
                if (target[k] == 0) continue;
                int newcur = cur - target[i] * pow(10, i) + target[k] * pow(10, i);
                if (!visited[newcur]) {
                    queue[rear++] = newcur;
                    visited[newcur] = 1;
                }
            }
        }
        steps++;
    }
    return -1;
}