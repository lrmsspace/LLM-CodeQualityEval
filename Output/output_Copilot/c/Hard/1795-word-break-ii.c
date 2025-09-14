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
    *returnSize = 0;
    int n = strlen(s);
    int* dp = (int*)malloc((n + 1) * sizeof(int));
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j] && isWord(s + j, i - j, wordDict, wordDictSize)) {
                dp[i] = 1;
                break;
            }
        }
    }
    if (!dp[n]) {
        return NULL;
    }
    char** result = (char**)malloc(10000 * sizeof(char*));
    char* sentence = (char*)malloc((n + 1) * sizeof(char));
    sentence[0] = '\0';
    dfs(s, wordDict, wordDictSize, 0, n, dp, result, returnSize, sentence);
    free(dp);
    free(sentence);
    return result;   
}