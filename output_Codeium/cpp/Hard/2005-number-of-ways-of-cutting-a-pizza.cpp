/**https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza/ */
//Given a rectangular pizza represented as a rows x cols matrix containing the following characters: 'A' (an apple) and '.' (empty cell) and given the integer k. You have to cut the pizza into k pieces using k-1 cuts. 
//For each cut you choose the direction: vertical or horizontal, then you choose a cut position at the cell boundary and cut the pizza into two pieces. If you cut the pizza vertically, give the left part of the pizza to a person. If you cut the pizza horizontally, give the upper part of the pizza to a person. Give the last piece of pizza to the last person.
//Return the number of ways of cutting the pizza such that each piece contains at least one apple. Since the answer can be a huge number, return this modulo 10^9 + 7.
// 
//Example 1:
//Input: pizza = ["A..","AAA","..."], k = 3
//Output: 3 
//Explanation: The figure above shows the three ways to cut the pizza. Note that pieces must contain at least one apple.
//Example 2:
//Input: pizza = ["A..","AA.","..."], k = 3
//Output: 1
//Example 3:
//Input: pizza = ["A..","A..","..."], k = 1
//Output: 1
// 
//Constraints:
//	1 <= rows, cols <= 50
//	rows == pizza.length
//	cols == pizza[i].length
//	1 <= k <= 10
//	pizza consists of characters 'A' and '.' only.
class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        int rows = pizza.size(), cols = pizza[0].size(), MOD = 1e9 + 7;
        vector<vector<int>> apples(rows + 1, vector<int>(cols + 1, 0));
        for (int i = 1; i <= rows; ++i) {
            for (int j = 1; j <= cols; ++j) {
                apples[i][j] = (pizza[i - 1][j - 1] == 'A') + apples[i - 1][j] + apples[i][j - 1] - apples[i - 1][j - 1];
            }
        }
        vector<vector<vector<int>>> dp(rows + 1, vector<vector<int>>(cols + 1, vector<int>(k + 1, 0)));
        dp[0][0][0] = 1;
        for (int i = 0; i <= rows; ++i) {
            for (int j = 0; j <= cols; ++j) {
                for (int n = 0; n <= k; ++n) {
                    if (i > 0) {
                        if (apples[i][cols] - apples[i][j] > 0) {
                            dp[i][j][n] = (dp[i][j][n] + dp[i - 1][j][n - 1]) % MOD;
                        }
                        dp[i][j][n] = (dp[i][j][n] + dp[i - 1][j][n]) % MOD;
                    }
                    if (j > 0) {
                        if (apples[rows][j] - apples[i][j] > 0) {
                            dp[i][j][n] = (dp[i][j][n] + dp[i][j - 1][n - 1]) % MOD;
                        }
                        dp[i][j][n] = (dp[i][j][n] + dp[i][j - 1][n]) % MOD;
                    }
                }
            }
        }
        return dp[rows][cols][k];
    }
};