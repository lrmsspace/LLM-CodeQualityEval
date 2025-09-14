/**https://leetcode.com/problems/keyboard-row/ */
//Given an array of strings words, return the words that can be typed using letters of the alphabet on only one row of American keyboard like the image below.
//In the American keyboard:
//	the first row consists of the characters "qwertyuiop",
//	the second row consists of the characters "asdfghjkl", and
//	the third row consists of the characters "zxcvbnm".
// 
//Example 1:
//Input: words = ["Hello","Alaska","Dad","Peace"]
//Output: ["Alaska","Dad"]
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
char ** findWords(char ** words, int wordsSize, int* returnSize){
    *returnSize = 0;
    char *row[3] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
    for (int i = 0; i < wordsSize; i++) {
        int r = 0;
        for (int j = 0; j < 3; j++) {
            int k = 0;
            while (row[j][k] != '\0') {
                if (tolower(words[i][0]) == row[j][k]) {
                    r = j;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < wordsSize; i++) {
        int j = 0;
        while (words[i][j] != '\0') {
            if (tolower(words[i][j]) != words[i][j]) {
                break;
            }
            j++;
        }
        if (j == strlen(words[i])) {
            words[*returnSize] = words[i];
        }
    }
    return words;
}