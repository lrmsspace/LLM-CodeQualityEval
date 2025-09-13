/**https://leetcode.com/problems/longest-palindromic-substring/ */
//Given a string s, return the longest palindromic substring in s.
// 
//Example 1:
//Input: s = "babad"
//Output: "bab"
//Explanation: "aba" is also a valid answer.
//Example 2:
//Input: s = "cbbd"
//Output: "bb"
// 
//Constraints:
//	1 <= s.length <= 1000
//	s consist of only digits and English letters.
char * longestPalindrome(char * s){
    int i, j, k, max = 0, start = 0;
    for (i = 0; s[i]; i++) {
        for (j = i, k = i; s[j] && s[k]; j++, k++) {
            if (s[j] != s[k]) break;
        }
        if (j - k > max) {
            max = j - k;
            start = k;
       }
    }
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        if (s[i] != s[j]) continue;
        for (k = i; s[k] && s[j]; k++, j--) {
            if (s[k] != s[j]) break;
        }
        if (k - j > max) {
            max =k - j;
        }
    }
    return strndup(s + start, max + 1);
}