/**https://leetcode.com/problems/keyboard-row/ */
//Given an array of strings words, return the words that can be typed using letters of the alphabet on only one row of American keyboard like the image below.
//Note that the strings are case-insensitive, both lowercased and uppercased of the same letter are treated as if they are at the same row.
//In the American keyboard:
//	the first row consists of the characters "qwertyuiop",
//	the second row consists of the characters "asdfghjkl", and
//	the third row consists of the characters "zxcvbnm".
// 
//Example 1:
//Input: words = ["Hello","Alaska","Dad","Peace"]
//Output: ["Alaska","Dad"]
//Explanation:
//Both "a" and "A" are in the 2nd row of the American keyboard due to case insensitivity.
//Example 2:
//Input: words = ["omk"]
//Output: []
//Example 3:
//Input: words = ["adsdf","sfd"]
//Output: ["adsdf","sfd"]
// 
//Constraints:
//	1 <= words.length <= 20
//	1 <= words[i].length <= 100
//	words[i] consists of English letters (both lowercase and uppercase). 
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 
int isOneRowWord(const char* word, const char* row) {
    while (*word) {
        if (!strchr(row, tolower(*word))) {
            return 0;
        }
        word++;
    }
    return 1;
}

char** findWords(char** words, int wordsSize, int* returnSize) {
    const char* rows[] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
    char** result = (char**)malloc(wordsSize * sizeof(char*));
    *returnSize = 0;
    
    for (int i = 0; i < wordsSize; i++) {
        for (int j = 0; j < 3; j++) {
            if (isOneRowWord(words[i], rows[j])) {
                result[*returnSize] = strdup(words[i]);
                (*returnSize)++;
                break;
            }
        }
    }
    
    return result;
}


    