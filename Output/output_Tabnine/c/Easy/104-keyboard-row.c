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
    // Define keyboard rows
    char* row1 = "qwertyuiop";
    char* row2 = "asdfghjkl";
    char* row3 = "zxcvbnm";
    
    // Initialize the result array
    char** result = (char**)malloc(wordsSize * sizeof(char*));
    *returnSize = 0;
    
    // Iterate over each word
    for (int i = 0; i < wordsSize; i++) {
        // Convert the word to lowercase for case insensitivity
        char* word = words[i];
        for (int j = 0; word[j]; j++)
            word[j] = tolower(word[j]);
        
        // Check if the word is in any row
        int isInRow1 = strchr(row1, word[0])!= NULL;
        int isInRow2 = strchr(row2, word[0])!= NULL;
        int isInRow3 = strchr(row3, word[0])!= NULL;
        
        // Add the word to the result if it is in one row
        if (isInRow1 || isInRow2 || isInRow3) {
            result[*returnSize] = strdup(words[i]);
            (*returnSize)++;
        }
    }
    
    // Return the result array
    return result;
    
}