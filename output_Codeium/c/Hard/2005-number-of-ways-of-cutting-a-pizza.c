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
    int rows = pizzaSize;
    int cols = strlen(pizza[0]);
    int dp[rows][cols][k + 1];
    memset(dp, 0, sizeof(dp));
    int apples[rows][cols];
    int cnt = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (pizza[i][j] == 'A') cnt++;
            apples[i][j] = cnt;
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (apples[i][j] > 0) {
                dp[i][j][1] = 1;
            }
        }
    }
    for (int x = 2; x <= k; x++) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (apples[i][j] >= x) {
                    for (int m = 0; m < i; m++) {
                        dp[i][j][x] += dp[m][j][x - 1];
                    }
                    for (int n = 0; n < j; n++) {
                        dp[i][j][x] += dp[i][n][x - 1];
                    }
                }
            }
        }
    }
    return dp[rows - 1][cols - 1][k];
}