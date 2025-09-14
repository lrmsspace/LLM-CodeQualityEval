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
        int rows = pizza.length, cols = pizza[0].length, MOD = 1000000007;
        int[][] dp = new int[rows + 1][cols + 1];
        int[][] prefixSum = new int[rows + 1][cols + 1];
        
        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= cols; j++) {
                prefixSum[i][j] = prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1] + (pizza[i - 1].charAt(j - 1) == 'A'? 1 : 0);
            }
        }
        
        for (int len = 1; len <= Math.min(rows, cols); len++) {
            for (int left = 1; left <= cols - len + 1; left++) {
                int right = left + len - 1;
                for (int top = 1; top <= rows - len + 1; top++) {
                    int bottom = top + len - 1;
                    if (pizza[top - 1].charAt(left - 1) == 'A' && pizza[bottom - 1].charAt(right - 1) == 'A') {
                        dp[top][right] = (dp[top][right] + dp[top - 1][left - 1] * (prefixSum[bottom][right] - prefixSum[top - 1][right] - prefixSum[bottom][left - 1] + prefixSum[top - 1][left - 1])) % MOD;
                    }
                }
            }
        }
        
        return dp[rows][cols];
        
    }
}