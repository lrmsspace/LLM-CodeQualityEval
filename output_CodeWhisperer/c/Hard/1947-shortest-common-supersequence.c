/**https://leetcode.com/problems/shortest-common-supersequence/ */
//Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.
//A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.
// 
//Example 1:
//Input: str1 = "abac", str2 = "cab"
//Output: "cabac"
//Explanation: 
//str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
//str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
//The answer provided is the shortest such string that satisfies these properties.
//Example 2:
//Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
//Output: "aaaaaaaa"
// 
//Constraints:
//	1 <= str1.length, str2.length <= 1000
//	str1 and str2 consist of lowercase English letters.
char* shortestCommonSupersequence(char* str1, char* str2) {
    int len1 = strlen(str1), len2 = strlen(str2);
    int dp[len1 + 1][len2 + 1];
    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            if (i == 0) {
                dp[i][j] = j;
            } else if (j == 0) {
                dp[i][j] = i;
            } else if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = 1 + (dp[i - 1][j] < dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1]);
            }
        }
    }
    int i = len1, j = len2;
    char* result = (char*)malloc((len1 + len2 + 1) * sizeof(char));
    int index = len1 + len2;
    result[index--] = '\0';
    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            result[index--] = str1[i - 1];
            i--;
            j--;
        } else if (dp[i - 1][j] < dp[i][j - 1]) {
            result[index--] = str1[i - 1];
            i--;
        } else {
            result[index--] = str2[j - 1];
            j--;
        }
    }
    while (i > 0) {
        result[index--] = str1[i - 1];
        i--;
    }
    while (j > 0) {
        result[index--] = str2[j - 1];
        j--;
    }
    return result + index + 1;
    
}