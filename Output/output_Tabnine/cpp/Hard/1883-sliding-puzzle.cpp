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
        int target = 0;
        int moves = 0;
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<int> zero_pos;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == 0) {
                    zero_pos = {i, j};
                }
                target = target * 10 + board[i][j];
            }
        }
        
        queue<pair<int, int>> q;
        q.push({target, 0});
        
        unordered_set<int> visited;
        
        while (!q.empty()) {
            int state = q.front().first;
            int count = q.front().second;
            q.pop();
            
            if (state == target) {
                return count;
            }
            
            if (visited.count(state)) {
                continue;
            }
            visited.insert(state);
            
            vector<int> current_state(board);
            int x = zero_pos[0], y = zero_pos[1];
            for (const auto& dir : directions) {
                int nx = x + dir[0], ny = y + dir[1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    swap(current_state[x * m + y], current_state[nx * m + ny]);
                    int newState = 0;
                    for (int i = 0; i < n; ++i) {
                        for (int j = 0; j < m; ++j) {
                            newState = newState * 10 + current_state[i * m + j];
                        }
                    }
                    q.push({newState, count + 1});
                    swap(current_state[x * m + y], current_state[nx * m + ny]);
                }
            }

        }
        
        return -1;
        
    }
};