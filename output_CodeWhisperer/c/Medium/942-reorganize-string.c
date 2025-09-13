/**https://leetcode.com/problems/reorganize-string/ */
//Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.
//Return any possible rearrangement of s or return "" if not possible.
// 
//Example 1:
//Input: s = "aab"
//Output: "aba"
//Example 2:
//Input: s = "aaab"
//Output: ""
// 
//Constraints:
//	1 <= s.length <= 500
//	s consists of lowercase English letters.
char* reorganizeString(char* s) {
    int n = strlen(s);
    int count[26] = {0};
    int max = 0, letter = 0;
    for (int i = 0; i < n; i++) {
        count[s[i] - 'a']++;
        if (count[s[i] - 'a'] > max) {
            max = count[s[i] - 'a'];
            letter = s[i] - 'a';
        }
    }
    if (max > (n + 1) / 2) {
        return "";
    }
    char* res = (char*)malloc(sizeof(char) * (n + 1));
    int index = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] - 'a' == letter) {
            res[index++] = s[i];
        }
    }
    for (int i = 0; i < 26; i++) {
        if (i != letter) {
            for (int j = 0; j < count[i]; j++) {
                if (index >= n) {
                    index = 1;
                }
                res[index++] = i + 'a';
            }
        }
    }
    res[n] = '\0';
    return res;
}