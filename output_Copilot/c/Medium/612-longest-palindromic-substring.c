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
char* longestPalindrome(char* s) {
    int len = strlen(s);
    if (len < 2) {
        return s;
    }
    int start = 0, maxLen = 1;
    for (int i = 0; i < len;) {
        if (len - i <= maxLen / 2) {
            break;
        }
        int left = i, right = i;
        while (right < len - 1 && s[right + 1] == s[right]) {
            right++;
        }
        i = right + 1;
        while (right < len - 1 && left > 0 && s[right + 1] == s[left - 1]) {
            right++;
            left--;
        }
        if (right - left + 1 > maxLen) {
            start = left;
            maxLen = right - left + 1;
        }
    }
    char* result = (char*)malloc(maxLen + 1);
    strncpy(result, s + start, maxLen);
    result[maxLen] = '\0';
    return result;    
}