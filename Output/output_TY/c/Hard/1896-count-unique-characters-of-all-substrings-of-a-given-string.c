/**https://leetcode.com/problems/count-unique-characters-of-all-substrings-of-a-given-string/ */
//Let's define a function countUniqueChars(s) that returns the number of unique characters on s.
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
int uniqueLetterString(char * s){
    int n = strlen(s);
    int pre[n][26], post[n][26];
    memset(pre, 0, sizeof(pre));
    memset(post, 0, sizeof(post));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            pre[i][j] = pre[i - 1][j];
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < 26; j++) {
            post[i][j] = post[i + 1][j];
        }
    }
    for (int i = 0; i < n; i++) {
        pre[i][s[i] - ' a ']++;
    }
    for (int i = 0; i < n; i++) {
        int ans = 0;
        for (int j = 0; j < 26; j++) {
            ans += pre[i][j] * post[i][j];
        }
        printf("%d ", ans);
    }
    return 0;
}