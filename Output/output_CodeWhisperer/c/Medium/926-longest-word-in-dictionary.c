/**https://leetcode.com/problems/longest-word-in-dictionary/ */
//Given an array of strings words representing an English Dictionary, return the longest word in words that can be built one character at a time by other words in words.
//If there is more than one possible answer, return the longest word with the smallest lexicographical order. If there is no answer, return the empty string.
//Note that the word should be built from left to right with each additional character being added to the end of a previous word. 
// 
//Example 1:
//Input: words = ["w","wo","wor","worl","world"]
//Output: "world"
//Explanation: The word "world" can be built one character at a time by "w", "wo", "wor", and "worl".
//Example 2:
//Input: words = ["a","banana","app","appl","ap","apply","apple"]
//Output: "apple"
//Explanation: Both "apply" and "apple" can be built from other words in the dictionary. However, "apple" is lexicographically smaller than "apply".
// 
//Constraints:
//	1 <= words.length <= 1000
//	1 <= words[i].length <= 30
//	words[i] consists of lowercase English letters.
char* longestWord(char** words, int wordsSize) {
    int i, j, k;
    int* dp = (int*)malloc(sizeof(int) * wordsSize);
    for (i = 0; i < wordsSize; i++) {
        dp[i] = 1;
    }
    int max = 0;
    int maxIndex = 0;
    for (i = 0; i < wordsSize; i++) {
        for (j = i - 1; j >= 0; j--) {
            if (strlen(words[j]) + 1 == strlen(words[i])) {
                for (k = 0; k < strlen(words[j]); k++) {
                    if (words[i][k] != words[j][k]) {
                        break;
                    }
                }
                if (k == strlen(words[j])) {
                    dp[i] = dp[j] + 1;
                    break;
                }
            }
        }
        if (dp[i] > max) {
            max = dp[i];
            maxIndex = i;
        } else if (dp[i] == max) {
            if (strcmp(words[i], words[maxIndex]) < 0) {
                maxIndex = i;
            }
        }
    }
    char* result = (char*)malloc(sizeof(char) * (strlen(words[maxIndex]) + 1));
    strcpy(result, words[maxIndex]);
    return result;
}