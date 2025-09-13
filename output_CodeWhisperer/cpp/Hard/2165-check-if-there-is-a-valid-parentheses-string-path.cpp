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
class Solution {
    public:
        bool hasValidPath(vector<vector<char>>& grid) {
            int m = grid.size();
            int n = grid[0].size();
            
            // If the first character is ')' or the last character is '(',
            // or if the total path length is even, no valid path exists
            if (grid[0][0] == ')' || grid[m-1][n-1] == '(' || (m + n - 1) % 2 == 0) {
                return false;
            }
            
            // dp[i][j][k] = whether there exists a valid path to cell (i,j) with balance k
            // Note: Balance can be at most m+n (total path length)
            vector<vector<unordered_map<int, bool>>> dp(m, vector<unordered_map<int, bool>>(n));
            
            return dfs(grid, 0, 0, 0, dp);
        }
        
    private:
        bool dfs(vector<vector<char>>& grid, int i, int j, int balance, vector<vector<unordered_map<int, bool>>>& dp) {
            int m = grid.size();
            int n = grid[0].size();
            
            // Update balance based on current cell
            if (grid[i][j] == '(') {
                balance++;
            } else {
                balance--;
            }
            
            // If balance becomes negative, the path is invalid
            if (balance < 0) {
                return false;
            }
            
            // If we've reached the bottom-right cell
            if (i == m - 1 && j == n - 1) {
                return balance == 0;
            }
            
            // If we've already computed this state
            if (dp[i][j].count(balance)) {
                return dp[i][j][balance];
            }
            
            // Try moving down
            if (i + 1 < m && dfs(grid, i + 1, j, balance, dp)) {
                return dp[i][j][balance] = true;
            }
            
            // Try moving right
            if (j + 1 < n && dfs(grid, i, j + 1, balance, dp)) {
                return dp[i][j][balance] = true;
            }
            
            return dp[i][j][balance] = false;
        }
    };
    