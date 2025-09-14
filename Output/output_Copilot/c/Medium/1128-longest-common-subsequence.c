/**https://leetcode.com/problems/longest-common-subsequence/ */
//Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.
//A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
//	For example, "ace" is a subsequence of "abcde".
//A common subsequence of two strings is a subsequence that is common to both strings.
// 
//Example 1:
//Input: text1 = "abcde", text2 = "ace" 
//Output: 3  
//Explanation: The longest common subsequence is "ace" and its length is 3.
//Example 2:
//Input: text1 = "abc", text2 = "abc"
//Output: 3
//Explanation: The longest common subsequence is "abc" and its length is 3.
//Example 3:
//Input: text1 = "abc", text2 = "def"
//Output: 0
//Explanation: There is no such common subsequence, so the result is 0.
// 
//Constraints:
//	1 <= text1.length, text2.length <= 1000
//	text1 and text2 consist of only lowercase English characters.
int longestCommonSubsequence(char* text1, char* text2) {
      int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
        int a[1001][1001] = {0};
        int b[1001][1001] = {0};
        int c[1001][1001] = {0};
        int d[1001][1001] = {0};
        int e[1001][1001] = {0};
        int f[1001][1001] = {0};
        int g[1001][1001] = {0};
        int h[1001][1001] = {0};
        int ans = 0;
        for(i = 0; i < strlen(text1); i++) {
            for(j = 0; j < strlen(text2); j++) {
                if(text1[i] == text2[j]) {
                    a[i + 1][j + 1] = a[i][j] + 1;
                } else {
                    a[i + 1][j + 1] = max(a[i][j + 1], a[i + 1][j]);
                }
            }
        }
        return a[strlen(text1)][strlen(text2)];      
}