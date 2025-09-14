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
    // Create a 2D boolean array dp to store the result of whether s[i:j] can be segmented into words in wordDict
    int n = strlen(s);
    bool** dp = (bool**)malloc(n * sizeof(bool*));
    for (int i = 0; i < n; i++) {
        dp[i] = (bool*)malloc(n * sizeof(bool));
        for (int j = 0; j < n; j++) {
            dp[i][j] = false;
        }
    }
    
    // Build the dp array
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (wordDictContains(wordDict, wordDictSize, s + i, j - i + 1)) {
                dp[i][j] = true;
            }
        }
    }
    
    // Create a 2D array to store the intermediate results
    int** memo = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        memo[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            memo[i][j] = -1;
        }
    }
    
    // Use a recursive function to find all possible sentences
    char** result = (char**)malloc(n * sizeof(char*));
    *returnSize = 0;
    findSentences(s, 0, n - 1, wordDict, wordDictSize, dp, memo, result, returnSize);
    
    // Free the memory allocated for memo and dp
    for (int i = 0; i < n; i++) {
        free(memo[i]);
    }
    free(memo);
    
    return result;
    
}