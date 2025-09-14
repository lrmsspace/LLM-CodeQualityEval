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
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        int start = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                start = start * 10 + board[i][j];
            }
        }
        unordered_set<int> visited;
        visited.insert(start);
        queue<int> q;
        q.push(start);
        int step = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int cur = q.front();
                q.pop();
                if (cur == 123450) {
                    return step;
                }
                int zero = cur % 10;
                int x = zero / 3;
                int y = zero % 3;
                int dx[4] = { -1, 1, 0, 0 };
                int dy[4] = { 0, 0, -1, 1 };
                for (int j = 0; j < 4; j++) {
                    int nx = x + dx[j];
                   int ny = y + dy[j];
                }
            }
        }
        return -1;
    }
};