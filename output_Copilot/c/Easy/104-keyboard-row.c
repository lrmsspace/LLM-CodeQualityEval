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
char** findWords(char** words, int wordsSize, int* returnSize) {
    char *row1 = "qwertyuiop";
    char *row2 = "asdfghjkl";
    char *row3 = "zxcvbnm";
    char **res = (char **)malloc(sizeof(char *) * wordsSize);
    *returnSize = 0;
    for (int i = 0; i < wordsSize; i++) {
        int j = 0;
        int row = 0;
        int flag = 1;
        if (strchr(row1, tolower(words[i][j])) != NULL) {
            row = 1;
        } else if (strchr(row2, tolower(words[i][j])) != NULL) {
            row = 2;
        } else if (strchr(row3, tolower(words[i][j])) != NULL) {
            row = 3;
        }
        while (words[i][++j] != '\0') {
            if (row == 1 && strchr(row1, tolower(words[i][j])) == NULL) {
                flag = 0;
                break;
            } else if (row == 2 && strchr(row2, tolower(words[i][j])) == NULL) {
                flag = 0;
                break;
            } else if (row == 3 && strchr(row3, tolower(words[i][j])) == NULL) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            res[(*returnSize)++] = words[i];
        }
    }
    return res;    
}