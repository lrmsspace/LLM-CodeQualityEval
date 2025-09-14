/**https://leetcode.com/problems/unique-binary-search-trees/ */
//Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.
// 
//Example 1:
//Input: n = 3
//Output: 5
//Example 2:
//Input: n = 1
//Output: 1
// 
//Constraints:
//	1 <= n <= 19
int numTrees(int n) {
    if (n == 0) return 1;
    int* dp = (int*)malloc(sizeof(int) * (n + 1));
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i] = 0;
        for (int j = 0; j < i; j++) {
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }
    int result = dp[n];
    free(dp);
    return result;
}