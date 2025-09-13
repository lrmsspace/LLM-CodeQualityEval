/**https://leetcode.com/problems/special-positions-in-a-binary-matrix/ */
//Given an m x n binary matrix mat, return the number of special positions in mat.
//A position (i, j) is called special if mat[i][j] == 1 and all other elements in row i and column j are 0 (rows and columns are 0-indexed).
// 
//Example 1:
//Input: mat = [[1,0,0],[0,0,1],[1,0,0]]
//Output: 1
//Explanation: (1, 2) is a special position because mat[1][2] == 1 and all other elements in row 1 and column 2 are 0.
//Example 2:
//Input: mat = [[1,0,0],[0,1,0],[0,0,1]]
//Output: 3
//Explanation: (0, 0), (1, 1) and (2, 2) are special positions.
// 
//Constraints:
//	m == mat.length
//	n == mat[i].length
//	1 <= m, n <= 100
//	mat[i][j] is either 0 or 1.
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> row(m, 0), col(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                row[i] += mat[i][j];
                col[j] += mat[i][j];
            }
        }
        int res = 0;
        for (int i = 0; i < m; i++) {
            if (row[i] != 1) continue;
            for (int j = 0; j < n; j++) {
                if (col[j] != 1) continue;
                if (mat[i][j] == 1) res++;
            }
        }
        return res;        
    }
};