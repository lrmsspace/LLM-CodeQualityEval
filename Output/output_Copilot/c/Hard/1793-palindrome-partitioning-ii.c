/**https://leetcode.com/problems/palindrome-partitioning-ii/ */
//Given a string s, partition s such that every substring of the partition is a palindrome.
//Return the minimum cuts needed for a palindrome partitioning of s.
// 
//Example 1:
//Input: s = "aab"
//Output: 1
//Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
//Example 2:
//Input: s = "a"
//Output: 0
//Example 3:
//Input: s = "ab"
//Output: 1
// 
//Constraints:
//	1 <= s.length <= 2000
//	s consists of lowercase English letters only.
int minCut(char* s) {
    int n = strlen(s);
    int *dp = (int *)malloc(sizeof(int) * (n + 1));
    int **p = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++) {
        p[i] = (int *)malloc(sizeof(int) * n);
        memset(p[i], 0, sizeof(int) * n);
    }
    for (int i = 0; i <= n; i++) {
        dp[i] = n - i - 1;
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j < n; j++) {
            if (s[i] == s[j] && (j - i < 2 || p[i + 1][j - 1])) {
                p[i][j] = 1;
                dp[i] = fmin(dp[i], dp[j + 1] + 1);
            }
        }
    }
    return dp[0];    
}