/*
 You are given a 2D character grid matrix of size m x n, represented as an array of strings, where matrix[i][j] represents the cell at the intersection of the ith row and jth column. Each cell is one of the following:
 '.' representing an empty cell.
 '#' representing an obstacle.
 An uppercase letter ('A'-'Z') representing a teleportation portal.
 You start at the top-left cell (0, 0), and your goal is to reach the bottom-right cell (m - 1, n - 1). You can move from the current cell to any adjacent cell (up, down, left, right) as long as the destination cell is within the grid bounds and is not an obstacle.
 If you step on a cell containing a portal letter and you haven't used that portal letter before, you may instantly teleport to any other cell in the grid with the same letter. This teleportation does not count as a move, but each portal letter can be used at most once during your journey.
 Return the minimum number of moves required to reach the bottom-right cell. If it is not possible to reach the destination, return -1.
 Example 1:
 Input: matrix = ["A..",".A.","..."]
 Output: 2
 Explanation:
 Before the first move, teleport from (0, 0) to (1, 1).
 In the first move, move from (1, 1) to (1, 2).
 In the second move, move from (1, 2) to (2, 2).
 Example 2:
 Input: matrix = [".#...",".#.#.",".#.#.","...#."]
 Output: 13
 Explanation:
 Constraints:
 1 <= m == matrix.length <= 103
 1 <= n == matrix[i].length <= 103
 matrix[i][j] is either '#', '.', or an uppercase English letter.
 matrix[0][0] is not an obstacle.
*/

int minMoves(char** matrix, int matrixSize) {
    int m = matrixSize;
    int n = matrix[0].length;
    int dp[m][n];
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == '#') continue;
            for (int k = 0; k < 4; ++k) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && matrix[ni][nj]!= '#') {
                    dp[ni][nj] = min(dp[ni][nj], dp[i][j] + 1);
                }
            }
        }
    }
    if (dp[m - 1][n - 1] == 0x3f3f3f3f) return -1;
    int portalCount = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (isalpha(matrix[i][j])) ++portalCount;
        }
    }
    int portalMoves[26];
    memset(portalMoves, 0x3f, sizeof(portalMoves));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (isalpha(matrix[i][j])) {
                portalMoves[matrix[i][j] - 'A'] = min(portalMoves[matrix[i][j] - 'A'], dp[i][j]);
            }
        }
    }
    int minMoves = dp[m - 1][n - 1];
    for (int i = 0; i < portalCount; ++i) {
        minMoves = min(minMoves, portalMoves[i]);
    }
    return minMoves;            
    
}