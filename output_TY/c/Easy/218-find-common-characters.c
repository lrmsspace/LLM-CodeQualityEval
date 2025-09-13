/**https://leetcode.com/problems/find-common-characters/ */
//Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). You may return the answer in any order.
// 
//Example 1:
//Input: words = ["bella","label","roller"]
//Output: ["e","l","l"]
//Example 2:
//Input: words = ["cool","lock","cook"]
//Output: ["c","o"]
// 
//Constraints:
//	1 <= words.length <= 100
//	1 <= words[i].length <= 100
//	words[i] consists of lowercase English letters.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** commonChars(char ** words, int wordsSize, int* returnSize){
    int i, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z;
    int a[26] = {0};
    int b[26] = {0};
    int c[26] = {0};
    int d[26] = {0};
    int e[26] = {0};
    int f[26] = {0};
    int g[26] = {0};
    int h[26] = {0};
    int count = 0;
    for (i = 0; i < wordsSize; i++) {
        for (j = 0; j < 26; j++) {
            a[j] = 0;
        }
        for (j = 0; j < strlen(words[i]); j++) {
            a[words[i][j] - 'a']++;
        }
        for (j = 0; j < 26; j++) {
            if (a[j] > 0) {
                if (count == 0) {
                    for (k = 0; k < a[j]; k++) {
                        b[j]++;
                    }
                } else {
                    for (k = 0; k < a[j] && k < b[j]; k++) {
                        c[j]++;
                    }
                }
            }
        }
    }
    for (i = 0; i < 26; i++) {
        if (c[i] > 0) {
            d[i] = c[i];
            count++;
        }
    }
    *returnSize = count;
    char ** result = (char **)malloc(sizeof(char *) * count);
    for (i = 0; i < count; i++) {
        result[i] = (char *)malloc(sizeof(char) * 2);
        result[i][0] = 'a' + i;
        result[i][1] = '\0';
    }
    return result;
}