/**https://leetcode.com/problems/number-of-valid-words-for-each-puzzle/ */
//With respect to a given puzzle string, a word is valid if both the following conditions are satisfied:
//	word contains the first letter of puzzle.
//	For each letter in word, that letter is in puzzle.
//	
//		For example, if the puzzle is "abcdefg", then valid words are "faced", "cabbage", and "baggage", while
//		invalid words are "beefed" (does not include 'a') and "based" (includes 's' which is not in the puzzle).
//	
//	
//Return an array answer, where answer[i] is the number of words in the given word list words that is valid with respect to the puzzle puzzles[i].
// 
//Example 1:
//Input: words = ["aaaa","asas","able","ability","actt","actor","access"], puzzles = ["aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"]
//Output: [1,1,3,2,4,0]
//Explanation: 
//1 valid word for "aboveyz" : "aaaa" 
//1 valid word for "abrodyz" : "aaaa"
//3 valid words for "abslute" : "aaaa", "asas", "able"
//2 valid words for "absoryz" : "aaaa", "asas"
//4 valid words for "actresz" : "aaaa", "asas", "actt", "access"
//There are no valid words for "gaswxyz" cause none of the words in the list contains letter 'g'.
//Example 2:
//Input: words = ["apple","pleas","please"], puzzles = ["aelwxyz","aelpxyz","aelpsxy","saelpxy","xaelpsy"]
//Output: [0,1,3,2,0]
// 
//Constraints:
//	1 <= words.length <= 105
//	4 <= words[i].length <= 50
//	1 <= puzzles.length <= 104
//	puzzles[i].length == 7
//	words[i] and puzzles[i] consist of lowercase English letters.
//	Each puzzles[i] does not contain repeated characters.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findNumOfValidWords(char** words, int wordsSize, char** puzzles, int puzzlesSize, int* returnSize) {
    // Create a hashmap to store the frequency of each character in the puzzle
    int* puzzleCharCount = (int*)calloc(26, sizeof(int));
    for (int i = 0; i < 7; ++i) {
        puzzleCharCount[puzzles[0][i] - 'a']++;
    }
    
    // Create a boolean array to mark if each word contains the first letter of the puzzle
    int* containsFirstLetter = (int*)calloc(wordsSize, sizeof(int));
    for (int i = 0; i < wordsSize; ++i) {
        containsFirstLetter[i] = puzzleCharCount[words[i][0] - 'a'] > 0;
    }
    
    // Create a boolean array to mark if each word contains all characters in the puzzle
    int* containsAllCharacters = (int*)calloc(wordsSize, sizeof(int));
    for (int i = 0; i < wordsSize; ++i) {
        int count = 0;
        for (int j = 0; j < 7; ++j) {
            count += puzzleCharCount[words[i][j] - 'a'];
        }
        containsAllCharacters[i] = count == 7;
    }
    
    // Create a boolean array to mark if each word contains at least one character from the puzzle
    int* containsAtLeastOneCharacter = (int*)calloc(wordsSize, sizeof(int));
    for (int i = 0; i < wordsSize; ++i) {
        containsAtLeastOneCharacter[i] = puzzleCharCount[words[i][0] - 'a'] > 0 || puzzleCharCount[words[i][1] - 'a'] > 0 || puzzleCharCount[words[i][2] - 'a'] > 0 || puzzleCharCount[words[i][3] - 'a'] > 0 || puzzleCharCount[words[i][4] - 'a'] > 0 || puzzleCharCount[words[i][5] - 'a'] > 0 || puzzleCharCount[words[i][6] - 'a'] > 0;
    }
    
    // Create a result array
    int* result = (int*)calloc(puzzlesSize, sizeof(int));
    *returnSize = puzzlesSize;
    
    // Iterate through each puzzle and count the valid words
    for (int i = 0; i < puzzlesSize; ++i) {
        int count = 0;
        for (int j = 0; j < wordsSize; ++j) {
            if (containsFirstLetter[j] && containsAllCharacters[j] && containsAtLeastOneCharacter[j]) {
                count++;
            }
        }
        result[i] = count;
    }
    
    // Free the allocated memory
    free(puzzleCharCount);
    free(containsFirstLetter);
    free(containsAllCharacters);
    free(containsAtLeastOneCharacter);
    
    return result;
    
}