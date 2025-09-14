/**https://leetcode.com/problems/surrounded-regions/ */
//You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:
//	Connect: A cell is connected to adjacent cells horizontally or vertically.
//	Region: To form a region connect every 'O' cell.
//	Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.
//A surrounded region is captured by replacing all 'O's with 'X's in the input matrix board.
// 
//Example 1:
//Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
//Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
//Explanation:
//In the above diagram, the bottom region is not captured because it is on the edge of the board and cannot be surrounded.
//Example 2:
//Input: board = [["X"]]
//Output: [["X"]]
// 
//Constraints:
//	m == board.length
//	n == board[i].length
//	1 <= m, n <= 200
//	board[i][j] is 'X' or 'O'.
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O' && !visited[i][j]) {
                    bool isSurrounded = true;
                    vector<pair<int, int>> region;
                    vector<pair<int, int>> stack;
                    stack.push_back(make_pair(i, j));
                    while (!stack.empty()) {
                        pair<int, int> cell = stack.back();
                        stack.pop_back();
                        int x = cell.first;
                        int y = cell.second;
                        if (x == 0 || x == m - 1 || y == 0 || y == n - 1) {
                            isSurrounded = false;
                        }
                        region.push_back(cell);
                        visited[x][y] = true;
                        if (x > 0 && board[x - 1][y] == 'O' && !visited[x - 1][y]) {
                            stack.push_back(make_pair(x - 1, y));
                        }
                        if (x < m - 1 && board[x + 1][y] == 'O' && !visited[x + 1][y]) {
                            stack.push_back(make_pair(x + 1, y));
                        }
                        if (y > 0 && board[x][y - 1] == 'O' && !visited[x][y - 1]) {
                            stack.push_back(make_pair(x, y - 1));
                        }
                        if (y < n - 1 && board[x][y + 1] == 'O' && !visited[x][y + 1]) {
                            stack.push_back(make_pair(x, y + 1));
                        }
                    }
                    if (isSurrounded) {
                        for (pair<int, int> cell : region) {
                            board[cell.first][cell.second] = 'X';
                        }
                    }
                }
            }   
            }   

    }
};