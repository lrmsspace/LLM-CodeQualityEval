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
        int m = pizza.length, n = pizza[0].length();
        int[][] prefix = new int[m + 1][n + 1];
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                prefix[i][j] = prefix[i + 1][j] + prefix[i][j + 1] - prefix[i + 1][j + 1] + (pizza[i].charAt(j) == 'A' ? 1 : 0);
            }
        }
        int[][][] dp = new int[k][m][n];
        for (int i = 0; i < k; i++) {
            for (int r = m - 1; r >= 0; r--) {
                for (int c = n - 1; c >= 0; c--) {
                    if (i == 0) {
                        dp[i][r][c] = (prefix[r][c] > 0) ? 1 : 0;
                    } else {
                        dp[i][r][c] = 0;
                        for (int r2 = r + 1; r2 < m; r2++) {
                            if (prefix[r][c] - prefix[r2][c] > 0) {
                                dp[i][r][c] += dp[i - 1][r2][c];
                            }
                        }
                    }
                }
            }
        } 
        return dp[k][0][0];
    }
}