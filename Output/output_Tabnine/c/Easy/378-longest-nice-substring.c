/**https://leetcode.com/problems/longest-nice-substring/ */
//A string s is nice if, for every letter of the alphabet that s contains, it appears both in uppercase and lowercase. For example, "abABB" is nice because 'A' and 'a' appear, and 'B' and 'b' appear. However, "abA" is not because 'b' appears, but 'B' does not.
//Given a string s, return the longest substring of s that is nice. If there are multiple, return the substring of the earliest occurrence. If there are none, return an empty string.
// 
//Example 1:
//Input: s = "YazaAay"
//Output: "aAa"
//Explanation: "aAa" is a nice string because 'A/a' is the only letter of the alphabet in s, and both 'A' and 'a' appear.
//"aAa" is the longest nice substring.
//Example 2:
//Input: s = "Bb"
//Output: "Bb"
//Explanation: "Bb" is a nice string because both 'B' and 'b' appear. The whole string is a substring.
//Example 3:
//Input: s = "c"
//Output: ""
//Explanation: There are no nice substrings.
// 
//Constraints:
//	1 <= s.length <= 100
//	s consists of uppercase and lowercase English letters.
char* longestNiceSubstring(char* s) {
    int n = strlen(s);
    int dp[n][26] = {0};
    int start = 0, end = 0, maxLen = 0;
    
    for (int i = 0; i < n; i++) {
        int lower = s[i] - 'a', upper = s[i] - 'A';
        dp[i][lower] = dp[i - 1][lower] + 1;
        dp[i][upper] = dp[i - 1][upper] + 1;
        
        while (dp[end][lower] > 1 || dp[end][upper] > 1) {
            dp[start][lower]--;
            dp[start][upper]--;
            start++;
        }
        
        if (end - start + 1 > maxLen) {
            maxLen = end - start + 1;
            end = i;
        }
    }
    
    char* result = malloc((maxLen + 1) * sizeof(char));
    strncpy(result, s + start, maxLen);
    result[maxLen] = '\0';
    return result;
    
}