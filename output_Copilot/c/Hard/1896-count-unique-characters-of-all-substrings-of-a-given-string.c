/**https://leetcode.com/problems/count-unique-characters-of-all-substrings-of-a-given-string/ */
//Let's define a function countUniqueChars(s) that returns the number of unique characters in s.
//	For example, calling countUniqueChars(s) if s = "LEETCODE" then "L", "T", "C", "O", "D" are the unique characters since they appear only once in s, therefore countUniqueChars(s) = 5.
//Given a string s, return the sum of countUniqueChars(t) where t is a substring of s. The test cases are generated such that the answer fits in a 32-bit integer.
//Notice that some substrings can be repeated so in this case you have to count the repeated ones too.
// 
//Example 1:
//Input: s = "ABC"
//Output: 10
//Explanation: All possible substrings are: "A","B","C","AB","BC" and "ABC".
//Every substring is composed with only unique letters.
//Sum of lengths of all substring is 1 + 1 + 1 + 2 + 2 + 3 = 10
//Example 2:
//Input: s = "ABA"
//Output: 8
//Explanation: The same as example 1, except countUniqueChars("ABA") = 1.
//Example 3:
//Input: s = "LEETCODE"
//Output: 92
// 
//Constraints:
//	1 <= s.length <= 105
//	s consists of uppercase English letters only.
int uniqueLetterString(char* s) {
    int i = 0, j = 0, k = 0, sum = 0, len = strlen(s), mod = 1000000007;
    int *last = (int *)malloc(sizeof(int) * 26);
    int *prev = (int *)malloc(sizeof(int) * 26);
    int *dp = (int *)malloc(sizeof(int) * len);
    memset(last, -1, sizeof(int) * 26);
    memset(prev, -1, sizeof(int) * 26);
    memset(dp, 0, sizeof(int) * len);
    for (i = 0; i < len; i++) {
        k = s[i] - 'A';
        if (last[k] == -1) {
            dp[i] = (i + 1) * (i + 2) / 2;
        } else {
            dp[i] = (i - last[k]) * (i - prev[k]) % mod;
        }
        dp[i] = (dp[i] + dp[i - 1]) % mod;
        sum = (sum + dp[i]) % mod;
        prev[k] = last[k];
        last[k] = i;
    }
    free(last);
    free(prev);
    free(dp);
    return sum;    
}