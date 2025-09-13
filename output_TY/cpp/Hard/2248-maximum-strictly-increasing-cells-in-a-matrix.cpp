/**https://leetcode.com/problems/maximum-strictly-increasing-cells-in-a-matrix/ */
//Given a 1-indexed m x n integer matrix mat, you can select any cell in the matrix as your starting cell.
//From the starting cell, you can move to any other cell in the same row or column, but only if the value of the destination cell is strictly greater than the value of the current cell. You can repeat this process as many times as possible, moving from cell to cell until you can no longer make any moves.
//Your task is to find the maximum number of cells that you can visit in the matrix by starting from some cell.
//Return an integer denoting the maximum number of cells that can be visited.
// 
//Example 1:
//Input: mat = [[3,1],[3,4]]
//Output: 2
//Explanation: The image shows how we can visit 2 cells starting from row 1, column 2. It can be shown that we cannot visit more than 2 cells no matter where we start from, so the answer is 2. 
//Example 2:
//Input: mat = [[1,1],[1,1]]
//Output: 1
//Explanation: Since the cells must be strictly increasing, we can only visit one cell in this example. 
//Example 3:
//Input: mat = [[3,1,6],[-9,5,7]]
//Output: 4
//Explanation: The image above shows how we can visit 4 cells starting from row 2, column 1. It can be shown that we cannot visit more than 4 cells no matter where we start from, so the answer is 4. 
// 
//Constraints:
//	m == mat.length 
//	n == mat[i].length 
//	1 <= m, n <= 105
//	1 <= m * n <= 105
//	-105 <= mat[i][j] <= 105
class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        vector<vector<int>> row(n, vector<int>(m, 0));
        vector<vector<int>> col(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int k = mat[i][j];
                row[i][j] = max(row[i][j], k);
                col[i][j] = max(col[i][j], k);
           }
        }
        for(int i = n - 1; i >= 0; i--){
            for(int j = m - 1; j >= 0; j--){
                int k = mat[i][j];
                int r = row[i][j], c = col[i][j];
                int max_row = 0, max_col = 0;
                for(int x = i + 1; x < n; x++){
                    if(mat[x][j] > k){
                        max_row = max(max_row, row[x][j]);
                    }
                }
                for(int y = j + 1; y < m; y++){
                    if(mat[i][y] > k){
                        max_col = max(max_col, col[i][y]);
                    }
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int k = mat[i][j];
                int r = row[i][j], c = col[i][j];
                int max_row = 0, max_col = 0;
                for(int x = i - 1; x >= 0; x--){
                    if(mat[x][j] > k){
                        max_row = max(max_row, row[x][j]);
                    }
                }
                for(int y = j - 1; y >= 0; y--){
                    if(mat[i][y] > k){
                        max_col = max(max_col, col[i][y]);
                    }
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int k = mat[i][j];
                int r = row[i][j], c = col[i][j];
                int max_row = 0, max_col = 0;
                for(int x = i + 1; x < n; x++){
                    if(mat[x][j] > k){
                        max_row = max(max_row, row[x][j]);
                    }
                }
                for(int y = j + 1; y < m; y++){
                   if(mat[i][y] > k){
                      max_col = max(max_col, col[i][y]);    
                   }
                }
            }
            
        }
        return 0;
    }
};