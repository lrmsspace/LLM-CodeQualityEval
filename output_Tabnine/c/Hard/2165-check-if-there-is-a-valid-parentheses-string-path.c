/**https://leetcode.com/problems/check-if-there-is-a-valid-parentheses-string-path/ */
//A parentheses string is a non-empty string consisting only of '(' and ')'. It is valid if any of the following conditions is true:
//	It is ().
//	It can be written as AB (A concatenated with B), where A and B are valid parentheses strings.
//	It can be written as (A), where A is a valid parentheses string.
//You are given an m x n matrix of parentheses grid. A valid parentheses string path in the grid is a path satisfying all of the following conditions:
//	The path starts from the upper left cell (0, 0).
//	The path ends at the bottom-right cell (m - 1, n - 1).
//	The path only ever moves down or right.
//	The resulting parentheses string formed by the path is valid.
//Return true if there exists a valid parentheses string path in the grid. Otherwise, return false.
// 
//Example 1:
//Input: grid = [["(","(","("],[")","(",")"],["(","(",")"],["(","(",")"]]
//Output: true
//Explanation: The above diagram shows two possible paths that form valid parentheses strings.
//The first path shown results in the valid parentheses string "()(())".
//The second path shown results in the valid parentheses string "((()))".
//Note that there may be other valid parentheses string paths.
//Example 2:
//Input: grid = [[")",")"],["(","("]]
//Output: false
//Explanation: The two possible paths form the parentheses strings "))(" and ")((". Since neither of them are valid parentheses strings, we return false.
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 100
//	grid[i][j] is either '(' or ')'.
bool hasValidPath(char** grid, int gridSize, int* gridColSize) {
    int m = gridSize, n = *gridColSize;
    int dp[m][n];
    memset(dp, -1, sizeof(dp));
    
    // Initialize the first row and column with 0
    for (int j = 0; j < n; ++j) {
        if (grid[0][j] == '(') dp[0][j] = 0;
        else if (grid[0][j] == ')') dp[0][j] = 1;
    }
    
    for (int i = 0; i < m; ++i) {
        if (grid[i][0] == '(') dp[i][0] = 0;
        else if (grid[i][0] == ')') dp[i][0] = 1;
    }
    
    // Fill the dp table
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if (grid[i][j] == grid[i-1][j]) {
                if (grid[i-1][j] == '(') dp[i][j] = dp[i-1][j-1] + 2;
                else dp[i][j] = dp[i-1][j-1] - 2;
            } else if (grid[i][j] == grid[i][j-1]) {
                if (grid[i][j-1] == '(') dp[i][j] = dp[i-1][j] + 1;
                else dp[i][j] = dp[i-1][j] - 1;
            }
        }
    }
    
    // Check if the last cell has a valid path
    return dp[m-1][n-1] >= 0;
    
}