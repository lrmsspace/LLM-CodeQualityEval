/**https://leetcode.com/problems/restore-the-array/ */
//A program was supposed to print an array of integers. The program forgot to print whitespaces and the array is printed as a string of digits s and all we know is that all integers in the array were in the range [1, k] and there are no leading zeros in the array.
//Given the string s and the integer k, return the number of the possible arrays that can be printed as s using the mentioned program. Since the answer may be very large, return it modulo 109 + 7.
// 
//Example 1:
//Input: s = "1000", k = 10000
//Output: 1
//Explanation: The only possible array is [1000]
//Example 2:
//Input: s = "1000", k = 10
//Output: 0
//Explanation: There cannot be an array that was printed this way and has all integer >= 1 and <= 10.
//Example 3:
//Input: s = "1317", k = 2000
//Output: 8
//Explanation: Possible arrays are [1317],[131,7],[13,17],[1,317],[13,1,7],[1,31,7],[1,3,17],[1,3,1,7]
// 
//Constraints:
//	1 <= s.length <= 105
//	s consists of only digits and does not contain leading zeros.
//	1 <= k <= 109
int numberOfArrays(char* s, int k) {
    int n = strlen(s);
    long long dp[n + 1][k + 1];
    memset(dp, 0, sizeof(dp));
    
    // Initialize base cases
    dp[0][0] = 1;
    for (int i = 1; i <= k; ++i)
        dp[0][i] = 0;
    
    for (int i = 1; i <= n; ++i) {
        int digit = s[i - 1] - '0';
        for (int j = 1; j <= k; ++j) {
            if (j >= digit)
                dp[i][j] = (dp[i][j] + dp[i - 1][j - digit]) % 1000000007;
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    
    return dp[n][k];
    
}