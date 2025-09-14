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
int expandAroundCenter(char *s, int left, int right) {
    int l = 0;
    while (left >= 0 && right < strlen(s) && s[left] == s[right]) {
        l = right - left + 1;
        left--;
        right++;
    }
    return l;
}
char* longestPalindrome(char* s) {
    int start = 0, end = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        int l1 = expandAroundCenter(s, i, i);
        int l2 = expandAroundCenter(s, i, i + 1);
        int l = (l1 > l2) ? l1 : l2;
        if (l > (end - start)) {
            start = i - (l - 1) / 2;
            end = i + l / 2;
        }
    }
    char *res = (char *) malloc((end - start + 2) * sizeof(char));
    strncpy(res, s + start, end - start + 1);
    res[end - start + 1] = '\0';
    return res;
}

