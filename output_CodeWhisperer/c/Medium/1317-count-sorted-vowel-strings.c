/**https://leetcode.com/problems/count-sorted-vowel-strings/ */
//Given an integer n, return the number of strings of length n that consist only of vowels (a, e, i, o, u) and are lexicographically sorted.
//A string s is lexicographically sorted if for all valid i, s[i] is the same as or comes before s[i+1] in the alphabet.
// 
//Example 1:
//Input: n = 1
//Output: 5
//Explanation: The 5 sorted strings that consist of vowels only are ["a","e","i","o","u"].
//Example 2:
//Input: n = 2
//Output: 15
//Explanation: The 15 sorted strings that consist of vowels only are
//["aa","ae","ai","ao","au","ee","ei","eo","eu","ii","io","iu","oo","ou","uu"].
//Note that "ea" is not a valid string since 'e' comes after 'a' in the alphabet.
//Example 3:
//Input: n = 33
//Output: 66045
// 
//Constraints:
//	1 <= n <= 50 
int countVowelStrings(int n) {
    
    int dp[51][5] = {0};
    for (int i = 0; i < 5; i++) {
        dp[1][i] = 1;
    }
    for (int i = 2; i <= n; i++) {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3] + dp[i - 1][4];
        dp[i][1] = dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3] + dp[i - 1][4];
        dp[i][2] = dp[i - 1][2] + dp[i - 1][3] + dp[i - 1][4];
        dp[i][3] = dp[i - 1][3] + dp[i - 1][4];
        dp[i][4] = dp[i - 1][4];
    }
    return dp[n][0] + dp[n][1] + dp[n][2] + dp[n][3] + dp[n][4];
}