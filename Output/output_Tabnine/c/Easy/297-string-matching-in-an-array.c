/**https://leetcode.com/problems/string-matching-in-an-array/ */
//Given an array of string words, return all strings in words that is a substring of another word. You can return the answer in any order.
//A substring is a contiguous sequence of characters within a string
// 
//Example 1:
//Input: words = ["mass","as","hero","superhero"]
//Output: ["as","hero"]
//Explanation: "as" is substring of "mass" and "hero" is substring of "superhero".
//["hero","as"] is also a valid answer.
//Example 2:
//Input: words = ["leetcode","et","code"]
//Output: ["et","code"]
//Explanation: "et", "code" are substring of "leetcode".
//Example 3:
//Input: words = ["blue","green","bu"]
//Output: []
//Explanation: No string of words is substring of another string.
// 
//Constraints:
//	1 <= words.length <= 100
//	1 <= words[i].length <= 30
//	words[i] contains only lowercase English letters.
//	All the strings of words are unique.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** stringMatching(char** words, int wordsSize, int* returnSize) {
    *returnSize = 0;
    if (wordsSize <= 1) return NULL;
    
    // Sort words by length in descending order
    qsort(words, wordsSize, sizeof(char*), cmp);
    
    int n = wordsSize;
    char** result = malloc(sizeof(char*) * n);
    *returnSize = 0;
    
    for (int i = 0; i < n - 1; i++) {
        int len1 = strlen(words[i]);
        for (int j = i + 1; j < n; j++) {
            int len2 = strlen(words[j]);
            if (len1 > len2) break;
            
            if (strstr(words[j], words[i])!= NULL) {
                result[*returnSize] = strdup(words[i]);
                (*returnSize)++;
                break;
            }
        }
    }
    
    return result;
    
}