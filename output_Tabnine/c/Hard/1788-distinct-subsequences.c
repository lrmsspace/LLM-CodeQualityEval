/**https://leetcode.com/problems/distinct-subsequences/ */
//Given two strings s and t, return the number of distinct subsequences of s which equals t.
//The test cases are generated so that the answer fits on a 32-bit signed integer.
// 
//Example 1:
//Input: s = "rabbbit", t = "rabbit"
//Output: 3
//Explanation:
//As shown below, there are 3 ways you can generate "rabbit" from s.
//rabbbit
//rabbbit
//rabbbit
//Example 2:
//Input: s = "babgbag", t = "bag"
//Output: 5
//Explanation:
//As shown below, there are 5 ways you can generate "bag" from s.
//babgbag
//babgbag
//babgbag
//babgbag
//babgbag
// 
//Constraints:
//	1 <= s.length, t.length <= 1000
//	s and t consist of English letters.
int numDistinct(char* s, char* t) {
    int m = strlen(s);
    int n = strlen(t);
    int dp[n + 1];
    
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    
    for (int i = 1; i <= m; i++) {
        int prev = dp[0];
        dp[0] = dp[0] * (i == 1) + dp[1];
        
        for (int j = 1; j <= n; j++) {
            int temp = dp[j];
            dp[j] = prev + dp[j];
            prev = temp;
        }
    }
    
    return dp[n];
    
}