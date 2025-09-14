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
    int rows = pizzaSize, cols = strlen(pizza[0]);
    int dp[rows + 1][cols + 1][k + 1];
    memset(dp, 0, sizeof(dp));
    
    // Count the number of apples in each row and column
    int apples[rows + 1][cols + 1];
    memset(apples, 0, sizeof(apples));
    for (int i = 1; i <= rows; ++i) {
        for (int j = 1; j <= cols; ++j) {
            if (pizza[i - 1][j - 1] == 'A') {
                apples[i][j] = apples[i - 1][j] + apples[i][j - 1] - apples[i - 1][j - 1] + 1;
            }
        }
    }
    
    // Compute the number of ways to cut the pizza
    for (int i = 1; i <= rows; ++i) {
        for (int j = 1; j <= cols; ++j) {
            for (int cuts = 1; cuts <= k; ++cuts) {
                for (int cut = 1; cut <= min(i, j); ++cut) {
                    if (cuts == 1) {
                        dp[i][j][cuts] = (dp[i][j][cuts] + apples[i][j]) % 1000000007;
                    } else {
                        dp[i][j][cuts] = (dp[i][j][cuts] + dp[i - cut][j][cuts - 1] + dp[i][j - cut][cuts - 1] - dp[i - cut][j - cut][cuts - 1]) % 1000000007;
                    }
                }
            }
        }
    }
    
    return dp[rows][cols][k];
    
}