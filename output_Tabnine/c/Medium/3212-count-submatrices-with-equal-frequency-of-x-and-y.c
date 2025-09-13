/*
 Given a 2D character matrix grid, where grid[i][j] is either 'X', 'Y', or '.', return the number of submatrices that contain:
 grid[0][0]
 an equal frequency of 'X' and 'Y'.
 at least one 'X'.
 Example 1:
 Input: grid = [["X","Y","."],["Y",".","."]]
 Output: 3
 Explanation:
 Example 2:
 Input: grid = [["X","X"],["X","Y"]]
 Output: 0
 Explanation:
 No submatrix has an equal frequency of 'X' and 'Y'.
 Example 3:
 Input: grid = [[".","."],[".","."]]
 Output: 0
 Explanation:
 No submatrix has at least one 'X'.
 Constraints:
 1 <= grid.length, grid[i].length <= 1000
 grid[i][j] is either 'X', 'Y', or '.'.
*/

int numberOfSubmatrices(char** grid, int gridSize, int* gridColSize) {

    int m = gridSize;
    int n = *gridColSize;
    int result = 0;
    
    // 2D prefix sum array  
    int prefixSum[m+1][n+1];
    memset(prefixSum, 0, sizeof(prefixSum));
    // Count the frequency of 'X' and 'Y' in the first row
    int freq[2] = {0, 0};
    for (int j = 1; j <= n; j++) {
        freq[grid[0][j-1] - 'X']++;
    }
    // Update prefix sum array
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            prefixSum[i][j] = prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1] + (grid[i-1][j-1] - 'X');
        }
    }
    // Calculate the number of submatrices  
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = i; k <= m; k++) {
                for (int l = j; l <= n; l++) {
                    int count = prefixSum[k][l] - prefixSum[i-1][l] - prefixSum[k][j-1] + prefixSum[i-1][j-1];
                    if (count == freq[0] + freq[1]) {
                        result += (k - i + 1) * (l - j + 1);
                    }
                }
            }
        }
    }
    
    return result;
    
}