/**https://leetcode.com/problems/minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix/ */
//Given a m x n binary matrix mat. In one step, you can choose one cell and flip it and all the four neighbors of it if they exist (Flip is changing 1 to 0 and 0 to 1). A pair of cells are called neighbors if they share one edge.
//Return the minimum number of steps required to convert mat to a zero matrix or -1 if you cannot.
//A binary matrix is a matrix with all cells equal to 0 or 1 only.
//A zero matrix is a matrix with all cells equal to 0.
// 
//Example 1:
//Input: mat = [[0,0],[0,1]]
//Output: 3
//Explanation: One possible solution is to flip (1, 0) then (0, 1) and finally (1, 1) as shown.
//Example 2:
//Input: mat = [[0]]
//Output: 0
//Explanation: Given matrix is a zero matrix. We do not need to change it.
//Example 3:
//Input: mat = [[1,0,0],[1,0,0]]
//Output: -1
//Explanation: Given matrix cannot be a zero matrix.
// 
//Constraints:
//	m == mat.length
//	n == mat[i].length
//	1 <= m, n <= 3
//	mat[i][j] is either 0 or 1.
class Solution {
public:
    int minFlips(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int start = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                start |= mat[i][j] << (i * n + j);
            }
        }
        queue<int> q;
        unordered_set<int> visited;
        q.push(start);
        visited.insert(start);
        int step = 0;
        vector<vector<int>> dirs = {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int cur = q.front();
                q.pop();
                if (cur == 0) {
                    return step;
                }
                for (int x = 0; x < m; x++) {
                    for (int y = 0; y < n; y++) {
                        int next = cur;
                        for (auto dir : dirs) {
                            int nx = x + dir[0], ny = y + dir[1];
                            if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                                next ^= 1 << (nx * n + ny);
                            }
                        }
                        if (!visited.count(next)) {
                            visited.insert(next);
                            q.push(next);
                        }
                    }
                }
            }
            step++;
        }
        return -1;       
    }
};