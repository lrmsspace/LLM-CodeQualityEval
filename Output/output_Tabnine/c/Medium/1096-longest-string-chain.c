/**https://leetcode.com/problems/longest-string-chain/ */
//You are given an array of words where each word consists of lowercase English letters.
//wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.
//	For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
//A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.
//Return the length of the longest possible word chain with words chosen from the given list of words.
// 
//Example 1:
//Input: words = ["a","b","ba","bca","bda","bdca"]
//Output: 4
//Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
//Example 2:
//Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
//Output: 5
//Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].
//Example 3:
//Input: words = ["abcd","dbqca"]
//Output: 1
//Explanation: The trivial word chain ["abcd"] is one of the longest word chains.
//["abcd","dbqca"] is not a valid word chain because the ordering of the letters is changed.
// 
//Constraints:
//	1 <= words.length <= 1000
//	1 <= words[i].length <= 16
//	words[i] only consists of lowercase English letters.
int longestStrChain(char** words, int wordsSize) {
    // Sort the words by length in descending order
    qsort(words, wordsSize, sizeof(char*), compare);
    
    // Initialize a 2D array dp to store the maximum length of word chains ending at each index
    int** dp = (int**)malloc(wordsSize * sizeof(int*));
    for (int i = 0; i < wordsSize; i++) {
        dp[i] = (int*)malloc(wordsSize * sizeof(int));
        memset(dp[i], 0, wordsSize * sizeof(int));
    }
    
    // Iterate through the words and fill in the dp array
    int maxLen = 1;
    for (int i = 0; i < wordsSize; i++) {
        for (int j = 0; j < i; j++) {
            // Check if the current word can be formed by removing one letter from the previous word
            int diff = 0;
            for (int k = 0; k < words[i][k] && k < words[j][k]; k++) {
                if (words[i][k]!= words[j][k]) {
                    diff++;
                }
            }
            if (diff == 1 && words[i][diff] == words[j][diff]) {
                dp[i][j] = dp[j][i] + 1;
                maxLen = fmax(maxLen, dp[i][j]);
            }
        }
    }
    
    // Return the maximum length of word chains
    int result = 0;
    for (int i = 0; i < wordsSize; i++) {
        result = fmax(result, dp[i][wordsSize - 1]);
    }
    // Free the memory allocated for dp
    for (int i = 0; i < wordsSize; i++) {
        free(dp[i]);
    }
    free(dp);
    return result;
    
}