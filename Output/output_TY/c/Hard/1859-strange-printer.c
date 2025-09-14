/**https://leetcode.com/problems/strange-printer/ */
//There is a strange printer with the following two special properties:
//	The printer can only print a sequence of the same character each time.
//	At each turn, the printer can print new characters starting from and ending at any place and will cover the original existing characters.
//Given a string s, return the minimum number of turns the printer needed to print it.
// 
//Example 1:
//Input: s = "aaabbb"
//Output: 2
//Explanation: Print "aaa" first and then print "bbb".
//Example 2:
//Input: s = "aba"
//Output: 2
//Explanation: Print "aaa" first and then print "b" from the second place of the string, which will cover the existing character 'a'.
// 
//Constraints:
//	1 <= s.length <= 100
//	s consists of lowercase English letters.
int strangePrinter(char * s){
    int len = strlen(s);
    if (len == 0) return 0;
    int *dp = (int *)calloc(len, sizeof(int));
    int *last = (int *)calloc(26, sizeof(int));
    for (int i = 0; i < len; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (s[j] == s[i]) {
                dp[i] = dp[j];
            }
        }
    }
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < i; j++) {
            if (s[j] == s[i]) {
                dp[i] = dp[j];
            }
        }
    }
    return dp[len - 1];
}