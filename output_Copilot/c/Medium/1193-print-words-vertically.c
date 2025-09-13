/**https://leetcode.com/problems/print-words-vertically/ */
//Given a string s. Return all the words vertically in the same order in which they appear in s.
//Words are returned as a list of strings, complete with spaces when is necessary. (Trailing spaces are not allowed).
//Each word would be put on only one column and that in one column there will be only one word.
// 
//Example 1:
//Input: s = "HOW ARE YOU"
//Output: ["HAY","ORO","WEU"]
//Explanation: Each word is printed vertically. 
// "HAY"
// "ORO"
// "WEU"
//Example 2:
//Input: s = "TO BE OR NOT TO BE"
//Output: ["TBONTB","OEROOE","   T"]
//Explanation: Trailing spaces is not allowed. 
//"TBONTB"
//"OEROOE"
//"   T"
//Example 3:
//Input: s = "CONTEST IS COMING"
//Output: ["CIC","OSO","N M","T I","E N","S G","T"]
// 
//Constraints:
//	1 <= s.length <= 200
//	s contains only upper case English letters.
//	It's guaranteed that there is only one space between 2 words.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** printVertically(char * s, int* returnSize){
    int len = strlen(s);
    int maxWordLen = 0, wordCount = 0;

    // Count words and find the maximum word length
    for (int i = 0, wordLen = 0; i <= len; i++) {
        if (s[i] == ' ' || s[i] == '\0') {
            if (wordLen > 0) {
                wordCount++;
                if (wordLen > maxWordLen) {
                    maxWordLen = wordLen;
                }
                wordLen = 0;
            }
        } else {
            wordLen++;
        }
    }

    // Allocate memory for the result
    char **result = (char **)malloc(maxWordLen * sizeof(char *));
    for (int i = 0; i < maxWordLen; i++) {
        result[i] = (char *)malloc((wordCount + 1) * sizeof(char));
        memset(result[i], ' ', wordCount);
        result[i][wordCount] = '\0';
    }

    // Fill the result array
    int col = 0, row = 0;
    for (int i = 0; i <= len; i++) {
        if (s[i] == ' ' || s[i] == '\0') {
            if (row > 0) {
                col++;
                row = 0;
            }
        } else {
            result[row++][col] = s[i];
        }
    }

    // Trim trailing spaces
    for (int i = 0; i < maxWordLen; i++) {
        int j = wordCount - 1;
        while (j >= 0 && result[i][j] == ' ') {
            result[i][j--] = '\0';
        }
    }

    *returnSize = maxWordLen;
    return result;
}