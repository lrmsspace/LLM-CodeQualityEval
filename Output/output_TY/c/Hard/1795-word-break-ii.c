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
char ** wordBreak(char * s, char ** wordDict, int wordDictSize, int* returnSize){
    int i, j, k, n, m, len, flag, *dp, *pos;
    char **res;
    n = strlen(s);
    dp = malloc(sizeof(int) * (n + 1));
    pos = malloc(sizeof(int) * (n + 1));
    dp[0] = 1;
    for (i = 1; i <= n; i++) {
        dp[i]= 0;
    }
    for (i = 0; i < wordDictSize; i++) {
        len = strlen(wordDict[i]);
        for (j = 0; j <= n - len; j++) {
            if (dp[j] == 0) {
                continue;
            }
            if (strncmp(s + j, wordDict[i], len) == 0) {
                dp[j + len]= 1;
            }
        }
    }
    return dp[n];
}