/**https://leetcode.com/problems/longest-uncommon-subsequence-ii/ */
//Given an array of strings strs, return the length of the longest uncommon subsequence between them. If the longest uncommon subsequence does not exist, return -1.
//An uncommon subsequence between an array of strings is a string that is a subsequence of one string but not the others.
//A subsequence of a string s is a string that can be obtained after deleting any number of characters from s.
//	For example, "abc" is a subsequence of "aebdc" because you can delete the underlined characters in "aebdc" to get "abc". Other subsequences of "aebdc" include "aebdc", "aeb", and "" (empty string).
// 
//Example 1:
//Input: strs = ["aba","cdc","eae"]
//Output: 3
//Example 2:
//Input: strs = ["aaa","aaa","aa"]
//Output: -1
// 
//Constraints:
//	2 <= strs.length <= 50
//	1 <= strs[i].length <= 10
//	strs[i] consists of lowercase English letters.
int findLUSlength(char** strs, int strsSize) {
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int *dp = (int*)malloc(sizeof(int) * strsSize);
    for (i = 0; i < strsSize; i++) {
        dp[i] = 1;
        for (j = 0; j < strsSize; j++) {
            if (i != j) {
                if (strlen(strs[i]) > strlen(strs[j])) {
                    for (k = 0, l = 0; k < strlen(strs[j]); k++) {
                        while (l < strlen(strs[i]) && strs[i][l] != strs[j][k]) {
                            l++;
                        }
                        if (l == strlen(strs[i])) {
                            break;
                        }
                        l++;
                    }
                    if (k == strlen(strs[j])) {
                        dp[i] = 0;
                        break;
                    }
                }
            }
        }
    }
    int max = 0;
    for (i = 0; i < strsSize; i++) {
        if (dp[i] == 1) {
            if (strlen(strs[i]) > max) {
                max = strlen(strs[i]);
            }
        }
    }
    return max == 0 ? -1 : max;
}