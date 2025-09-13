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
    int n = strlen(s);
    if (n == 0) return s;
    char* rev_s = malloc(sizeof(char) * (n + 1));
    for (int i = 0; i < n; i++) {
        rev_s[i] = s[n - 1 - i];
    }
    rev_s[n] = '\0';
    char* temp = malloc(sizeof(char) * (2 * n + 1));
    strcpy(temp, s);
    strcat(temp, "#");
    strcat(temp, rev_s);
    int* lps = malloc(sizeof(int) * (2 * n + 1));
    int len = 0;
    lps[0] = 0;
    for (int i = 1; i < 2 * n + 1; i++) {
        while (len > 0 && temp[i] != temp[len]) {
            len = lps[len - 1];
        }
        if (temp[i] == temp[len]) {
            len++;
        }
        lps[i] = len;
    }
    int add = n - lps[2 * n];
    char* result = malloc(sizeof(char) * (n + add + 1));
    for (int i = 0; i < add; i++) {
        result[i] = s[n - 1 - i];
    }
    for (int i = 0; i < n; i++) {
        result[i + add] = s[i];
    }
    result[n + add] = '\0';
    return result;
    
}