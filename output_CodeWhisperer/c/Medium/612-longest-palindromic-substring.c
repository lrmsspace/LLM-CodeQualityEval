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
    int i = 0;
    while (i < len) {
        int left = i, right = i;
        while (right < len - 1 && s[right + 1] == s[right]) {
            right++;
        }
        i = right + 1;
        while (right < len - 1 && left > 0 && s[right + 1] == s[left - 1]) {
            right++;
            left--;
        }
        int newLen = right - left + 1;
        if (newLen > maxLen) {
            start = left;
            maxLen = newLen;
        }
    }
    char* ret = (char*)malloc(sizeof(char) * (maxLen + 1));
    for (int i = 0; i < maxLen; i++) {
        ret[i] = s[start + i];
    }
    ret[maxLen] = '\0';
    return ret;
    
}