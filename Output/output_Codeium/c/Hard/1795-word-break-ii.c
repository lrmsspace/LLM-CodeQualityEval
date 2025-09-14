/**https://leetcode.com/problems/word-break-ii/ */
//Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.
//Note that the same word in the dictionary may be reused multiple times in the segmentation.
// 
//Example 1:
//Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
//Output: ["cats and dog","cat sand dog"]
//Example 2:
//Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
//Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
//Explanation: Note that you are allowed to reuse a dictionary word.
//Example 3:
//Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
//Output: []
// 
//Constraints:
//	1 <= s.length <= 20
//	1 <= wordDict.length <= 1000
//	1 <= wordDict[i].length <= 10
//	s and wordDict[i] consist of only lowercase English letters.
//	All the strings of wordDict are unique.
//	Input is generated in a way that the length of the answer doesn't exceed 105.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** wordBreak(char* s, char** wordDict, int wordDictSize, int* returnSize) {
    int len = strlen(s);
    char** dp[len + 1];
    dp[0] = (char*[]){""};
    for (int i = 0; i < len; ++i) {
        int dp_i_size = 0;
        dp[i + 1] = NULL;
        for (int j = 0; j <= i; ++j) {
            if (dp[j] != NULL) {
                for (int k = 0; k < wordDictSize; ++k) {
                    int len_word = strlen(wordDict[k]);
                    if (i - j + 1 == len_word && memcmp(s + j, wordDict[k], len_word) == 0) {
                        int dp_j_size = dp[j] ? (sizeof(dp[j]) / sizeof(dp[j][0])) : 0;
                        dp[i + 1] = realloc(dp[i + 1], (dp_i_size + dp_j_size + 1) * sizeof(char*));
                        for (int l = 0; l < dp_j_size; ++l) {
                            int len_dp_j_l = strlen(dp[j][l]);
                            dp[i + 1][dp_i_size + l] = malloc(len_dp_j_l + len_word + 1);
                            sprintf(dp[i + 1][dp_i_size + l], "%s%s", dp[j][l], wordDict[k]);
                        }
                        dp_i_size += dp_j_size;
                    }
                }
            }
        }
        if (dp[i + 1] != NULL) {
            dp[i + 1][dp_i_size] = NULL;
        }
    }
    *returnSize = dp[len] ? (sizeof(dp[len]) / sizeof(dp[len][0])) : 0;
    return dp[len];
}