/**https://leetcode.com/problems/license-key-formatting/ */
//You are given a license key represented as a string s that consists of only alphanumeric characters and dashes. The string is separated into n + 1 groups by n dashes. You are also given an integer k.
//We want to reformat the string s such that each group contains exactly k characters, except for the first group, which could be shorter than k but still must contain at least one character. Furthermore, there must be a dash inserted between two groups, and you should convert all lowercase letters to uppercase.
//Return the reformatted license key.
// 
//Example 1:
//Input: s = "5F3Z-2e-9-w", k = 4
//Output: "5F3Z-2E9W"
//Explanation: The string s has been split into two parts, each part has 4 characters.
//Note that the two extra dashes are not needed and can be removed.
//Example 2:
//Input: s = "2-5g-3-J", k = 2
//Output: "2-5G-3J"
//Explanation: The string s has been split into three parts, each part has 2 characters except the first part as it could be shorter as mentioned above.
// 
//Constraints:
//	1 <= s.length <= 105
//	s consists of English letters, digits, and dashes '-'.
//	1 <= k <= 104
char* licenseKeyFormatting(char* s, int k) {
    int n = strlen(s);
    int len = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != '-') {
            len++;
        }
    }
    int first = len % k;
    char* res = (char*)malloc(sizeof(char) * (len + len / k + 1));
    res[len + len / k] = '\0';
    int index = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != '-') {
            res[index++] = s[i] >= 'a' && s[i] <= 'z' ? s[i] - 32 : s[i];
        }
    }
    for (int i = 0; i < len / k; i++) {
        for (int j = 0; j < k; j++) {
            res[index++] = res[first + i * k + j];
        }
        if (i != len / k - 1) {
            res[index++] = '-';
        }
    }
    if (first > 0) {
        for (int i = 0; i < first; i++) {
            res[index++] = res[i];
        }
    }
    return res;    
}