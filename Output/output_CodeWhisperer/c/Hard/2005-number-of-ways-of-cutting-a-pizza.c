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
int ways(char** pizza, int pizzaSize, int k) {
    int mod = 1000000007;
    int rows = pizzaSize;
    int cols = strlen(pizza[0]);
    int dp[50][50][11] = {0};
    int hasApple[50][50] = {0};
    for (int i = rows - 1; i >= 0; i--) {
        for (int j = cols - 1; j >= 0; j--) {
            hasApple[i][j] = (pizza[i][j] == 'A' ? 1 : 0);
            if (i < rows - 1) {
                hasApple[i][j] += hasApple[i + 1][j];
            }
            if (j < cols - 1) {
                hasApple[i][j] += hasApple[i][j + 1];
            }
            if (hasApple[i][j] > 0) {
                hasApple[i][j] = 1;
            }
        }
    }
    dp[0][0][1] = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            for (int l = 1; l < k; l++) {
                for (int m = i + 1; m < rows; m++) {
                    if (hasApple[i][j] - hasApple[m][j] > 0) {
                        dp[m][j][l + 1] = (dp[m][j][l + 1] + dp[i][j][l]) % mod;
                    }
                }
                for (int m = j + 1; m < cols; m++) {
                    if (hasApple[i][j] - hasApple[i][m] > 0) {
                        dp[i][m][l + 1] = (dp[i][m][l + 1] + dp[i][j][l]) % mod;
                    }
                }
            }
        }
    }
    int result = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result = (result + dp[i][j][k]) % mod;
        }
    }
    return result;
}