/*
 You are given a string s. It may contain any number of '*' characters. Your task is to remove all '*' characters.
 While there is a '*', do the following operation:
 Delete the leftmost '*' and the smallest non-'*' character to its left. If there are several smallest characters, you can delete any of them.
 Return the lexicographically smallest resulting string after removing all '*' characters.
 Example 1:
 Input: s = "aaba*"
 Output: "aab"
 Explanation:
 We should delete one of the 'a' characters with '*'. If we choose s[3], s becomes the lexicographically smallest.
 Example 2:
 Input: s = "abc"
 Output: "abc"
 Explanation:
 There is no '*' in the string.
 Constraints:
 1 <= s.length <= 105
 s consists only of lowercase English letters and '*'.
 The input is generated such that it is possible to delete all '*' characters.
*/

char* clearStars(char* s) {
    int len = strlen(s);
    char* res = (char*)malloc(sizeof(char) * (len + 1));
    int resIndex = 0;
    int* index = (int*)malloc(sizeof(int) * 26);
    memset(index, -1, sizeof(int) * 26);
    for (int i = 0; i < len; i++) {
        if (s[i] == '*') {
            for (int j = 0; j < 26; j++) {
                if (index[j] != -1) {
                    res[index[j]] = 0;
                    index[j] = -1;
                    break;
                }
            }
        } else {
            res[resIndex++] = s[i];
            if (index[s[i] - 'a'] == -1) {
                index[s[i] - 'a'] = resIndex - 1;
            }
        }
    }
    res[resIndex] = 0;
    for (int i = 0; i < len; i++) {
        if (res[i] != 0) {
            s[i] = res[i];
        } else {
            break;
        }
    }
    s[resIndex] = 0;
    return s;    
}