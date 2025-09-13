/**https://leetcode.com/problems/palindrome-partitioning-iv/ */
//Given a string s, return true if it is possible to split the string s into three non-empty palindromic substrings. Otherwise, return false.​​​​​
//A string is said to be palindrome if it the same string when reversed.
// 
//Example 1:
//Input: s = "abcbdd"
//Output: true
//Explanation: "abcbdd" = "a" + "bcb" + "dd", and all three substrings are palindromes.
//Example 2:
//Input: s = "bcbddxy"
//Output: false
//Explanation: s cannot be split into 3 palindromes.
// 
//Constraints:
//	3 <= s.length <= 2000
//	s​​​​​​ consists only of lowercase English letters.
bool checkPartitioning(char * s){
    int n = strlen(s);
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    for (int i = n - 1; i >= 0; i--){
        for (int j = i; j < n; j++){
            if (i == j){
                dp[i][j] = 1;
            }
            else if (j - i == 1){
                dp[i][j] = (s[i] == s[j]);
            }
        }
    }
    for (int i = n - 1; i >= 0; i--){
        for (int j = i; j < n; j++){
            for (int k = i; k < j; k++){
                if (dp[i][k] && dp[k + 1][j]){
                    return true;
                }
            }
        }
    }
    return false;
}