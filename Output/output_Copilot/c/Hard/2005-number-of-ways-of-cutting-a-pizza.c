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


            #define MOD 1000000007

            int ways(char** pizza, int pizzaSize, int k) {
                int rows = pizzaSize;
                int cols = strlen(pizza[0]);
                int prefix[rows + 1][cols + 1];
                memset(prefix, 0, sizeof(prefix));

                // Compute prefix sum of apples
                for (int i = rows - 1; i >= 0; i--) {
                    for (int j = cols - 1; j >= 0; j--) {
                        prefix[i][j] = (pizza[i][j] == 'A') + prefix[i + 1][j] + prefix[i][j + 1] - prefix[i + 1][j + 1];
                    }
                }

                // DP array
                int dp[k][rows][cols];
                memset(dp, 0, sizeof(dp));

                // Base case: k = 1
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        dp[0][i][j] = (prefix[i][j] > 0);
                    }
                }

                // Fill DP table for k > 1
                for (int cuts = 1; cuts < k; cuts++) {
                    for (int i = 0; i < rows; i++) {
                        for (int j = 0; j < cols; j++) {
                            // Horizontal cuts
                            for (int x = i + 1; x < rows; x++) {
                                if (prefix[i][j] - prefix[x][j] > 0) {
                                    dp[cuts][i][j] = (dp[cuts][i][j] + dp[cuts - 1][x][j]) % MOD;
                                }
                            }
                            // Vertical cuts
                            for (int y = j + 1; y < cols; y++) {
                                if (prefix[i][j] - prefix[i][y] > 0) {
                                    dp[cuts][i][j] = (dp[cuts][i][j] + dp[cuts - 1][i][y]) % MOD;
                                }
                            }
                        }
                    }
                }

                return dp[k - 1][0][0];
            }

                