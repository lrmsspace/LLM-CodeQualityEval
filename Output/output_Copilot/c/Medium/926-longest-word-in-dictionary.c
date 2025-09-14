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
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int hash[1001] = {0};
    int max = 0;
    char* ans = (char*)malloc(31 * sizeof(char));
    for(i = 0; i < wordsSize; i++) {
        hash[strlen(words[i])] = 1;
    }
    for(i = 0; i < wordsSize; i++) {
        if(strlen(words[i]) == 1) {
            if(max < 1) {
                max = 1;
                strcpy(ans, words[i]);
            }
        } else {
            int flag = 1;
            for(j = 1; j < strlen(words[i]); j++) {
                if(!hash[j]) {
                    flag = 0;
                    break;
                }
            }
            if(flag) {
                if(max < strlen(words[i])) {
                    max = strlen(words[i]);
                    strcpy(ans, words[i]);
                } else if(max == strlen(words[i])) {
                    if(strcmp(ans, words[i]) > 0) {
                        strcpy(ans, words[i]);
                    }
                }
            }
        }
    }
    return ans; 
}