/**https://leetcode.com/problems/number-of-ways-to-wear-different-hats-to-each-other/ */
//There are n people and 40 types of hats labeled from 1 to 40.
//Given a 2D integer array hats, where hats[i] is a list of all hats preferred by the ith person.
//Return the number of ways that the n people wear different hats to each other.
//Since the answer may be too large, return it modulo 109 + 7.
// 
//Example 1:
//Input: hats = [[3,4],[4,5],[5]]
//Output: 1
//Explanation: There is only one way to choose hats given the conditions. 
//First person choose hat 3, Second person choose hat 4 and last one hat 5.
//Example 2:
//Input: hats = [[3,5,1],[3,5]]
//Output: 4
//Explanation: There are 4 ways to choose hats:
//(3,5), (5,3), (1,3) and (1,5)
//Example 3:
//Input: hats = [[1,2,3,4],[1,2,3,4],[1,2,3,4],[1,2,3,4]]
//Output: 24
//Explanation: Each person can choose hats labeled from 1 to 4.
//Number of Permutations of (1,2,3,4) = 24.
// 
//Constraints:
//	n == hats.length
//	1 <= n <= 10
//	1 <= hats[i].length <= 40
//	1 <= hats[i][j] <= 40
//	hats[i] contains a list of unique integers.
int numberWays(int** hats, int hatsSize, int* hatsColSize) {
    int mod = 1000000007;
    int n = hatsSize;
    int m = 40;
    int dp[1 << n][m + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < (1 << n); k++) {
                if (k & (1 << j)) {
                    continue;
                }
                for (int l = 0; l < n; l++) {
                    if (hats[l][i - 1] == 0) {
                        continue;
                    }
                    if (hats[l][i - 1] == i) {
                        dp[k | (1 << j)][i] = (dp[k | (1 << j)][i] + dp[k][i - 1]) % mod;
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < (1 << n); i++) {
        ans = (ans + dp[i][m]) % mod;
    }
    return ans;    
}