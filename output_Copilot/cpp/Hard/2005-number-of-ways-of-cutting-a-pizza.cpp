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
        const int MOD = 1e9 + 7;
        int m = pizza.size(), n = pizza[0].size();
        vector<vector<int>> prefix(m + 1, vector<int>(n + 1));
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                prefix[i][j] = prefix[i + 1][j] + prefix[i][j + 1] - prefix[i + 1][j + 1] + (pizza[i][j] == 'A');
            }
        }
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k)));
        function<int(int, int, int)> dfs = [&](int i, int j, int k) {
            if (dp[i][j][k] != 0) {
                return dp[i][j][k];
            }
            if (prefix[i][j] == 0) {
                return 0;
            }
            if (k == 1) {
                return 1;
            }
            int res = 0;
            for (int x = i + 1; x < m; x++) {
                if (prefix[i][j] - prefix[x][j] > 0) {
                    res = (res + dfs(x, j, k - 1)) % MOD;
                }
            }
            for (int y = j + 1; y < n; y++) {
                if (prefix[i][j] - prefix[i][y] > 0) {
                    res = (res + dfs(i, y, k - 1)) % MOD;
                }
            }
            return dp[i][j][k] = res;
        };
        return dfs(0, 0, k);
    }
};