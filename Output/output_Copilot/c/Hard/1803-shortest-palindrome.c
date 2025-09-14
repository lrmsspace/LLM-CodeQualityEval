/**https://leetcode.com/problems/shortest-palindrome/ */
//You are given a string s. You can convert s to a palindrome by adding characters in front of it.
//Return the shortest palindrome you can find by performing this transformation.
// 
//Example 1:
//Input: s = "aacecaaa"
//Output: "aaacecaaa"
//Example 2:
//Input: s = "abcd"
//Output: "dcbabcd"
// 
//Constraints:
//	0 <= s.length <= 5 * 104
//	s consists of lowercase English letters only.
char* shortestPalindrome(char* s) {
    int len = strlen(s);
    int i = 0;
    for (i = len - 1; i >= 0; i--) {
        if (s[i] == s[0]) {
            int j = 0;
            for (j = 0; j <= i / 2; j++) {
                if (s[j] != s[i - j]) {
                    break;
                }
            }
            if (j > i / 2) {
                break;
            }
        }
    }
    char* result = (char*)malloc(sizeof(char) * (2 * len - i - 1));
    for (int j = 0; j < len - i - 1; j++) {
        result[j] = s[len - j - 1];
    }
    for (int j = 0; j < len; j++) {
        result[j + len - i - 1] = s[j];
    }
    result[2 * len - i - 1] = '\0';
    return result;    
}