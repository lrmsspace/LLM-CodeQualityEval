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
    public int ways(String[] pizza, int k) {
        int rows = pizza.length;
        int cols = pizza[0].length();
        int MOD = (int)1e9 + 7;
        int[][] apples = new int[rows + 1][cols + 1];
        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= cols; j++) {
                apples[i][j] = apples[i - 1][j] + apples[i][j - 1] - apples[i - 1][j - 1] + (pizza[i - 1].charAt(j - 1) == 'A' ? 1 : 0);
            }
        }
        int[][] dp = new int[k][rows * cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (apples[rows][cols] - apples[i][j] > 0) dp[0][i * cols + j] = 1;
            }
        }
        for (int i = 1; i < k; i++) {
            for (int j = 0; j < rows * cols; j++) {
                int r = j / cols, c = j % cols;
                if (dp[i - 1][j] > 0) {
                    if (c + 1 < cols) dp[i][j + 1] = (dp[i][j + 1] + dp[i - 1][j]) % MOD;
                    if (r + 1 < rows) dp[i][j + cols] = (dp[i][j + cols] + dp[i - 1][j]) % MOD;
                }
            }
        }
        return dp[k - 1][rows * cols - 1];
    }
}