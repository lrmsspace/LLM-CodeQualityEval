/**https://leetcode.com/problems/spiral-matrix-ii/ */
//Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.
// 
//Example 1:
//Input: n = 3
//Output: [[1,2,3],[8,9,4],[7,6,5]]
//Example 2:
//Input: n = 1
//Output: [[1]]
// 
//Constraints:
//	1 <= n <= 20
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        int dir = 0, r = 0, c = 0;
        for (int i = 1; i <= n * n; ++i) {
            matrix[r][c] = i;
            int nr = r + dx[dir], nc = c + dy[dir];
            if (nr < 0 || nc < 0 || nr >= n || nc >= n || matrix[nr][nc] != 0) {
                dir = (dir + 1) % 4;
                nr = r + dx[dir];
                nc = c + dy[dir];
            }
            r = nr;
            c = nc;
        }
        return matrix;

    }
};