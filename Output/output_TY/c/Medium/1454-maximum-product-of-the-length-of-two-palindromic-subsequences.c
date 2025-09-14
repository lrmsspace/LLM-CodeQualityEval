/**https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/ */
//Given a string s, find two disjoint palindromic subsequences of s such that the product of their lengths is maximized. The two subsequences are disjoint if they do not both pick a character at the same index.
//Return the maximum possible product of the lengths of the two palindromic subsequences.
//A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters. A string is palindromic if it reads the same forward and backward.
// 
//Example 1:
//Input: s = "leetcodecom"
//Output: 9
//Explanation: An optimal solution is to choose "ete" for the 1st subsequence and "cdc" for the 2nd subsequence.
//The product of their lengths is: 3 * 3 = 9.
//Example 2:
//Input: s = "bb"
//Output: 1
//Explanation: An optimal solution is to choose "b" (the first character) for the 1st subsequence and "b" (the second character) for the 2nd subsequence.
//The product of their lengths is: 1 * 1 = 1.
//Example 3:
//Input: s = "accbcaxxcxx"
//Output: 25
//Explanation: An optimal solution is to choose "accca" for the 1st subsequence and "xxcxx" for the 2nd subsequence.
//The product of their lengths is: 5 * 5 = 25.
// 
//Constraints:
//	2 <= s.length <= 12
//	s consists of lowercase English letters only.
int maxProduct(char * s){
    int len = strlen(s);
    int dp[len][len];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < len; i++) {
        dp[i][i] = 1;
    }
    for (int i = 0; i < len - 1; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = 2;
        }
    }
    for (int i = len - 3; i >= 0; i--) {
        for (int j = i + 2; j < len; j++) {
            if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            }
            else {
                dp[i][j] = max(dp[i][j -1], dp[i + 1][j]);
            }
        }
    }
    int max_len = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            max_len = max(max_len, dp[i][j] * (len - dp[i][j]));
        }
    }
    return max_len;
}