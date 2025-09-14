/**https://leetcode.com/problems/concatenated-words/ */
//Given an array of strings words (without duplicates), return all the concatenated words in the given list of words.
//A concatenated word is defined as a string that is comprised entirely of at least two shorter words (not necessarily distinct) in the given array.
// 
//Example 1:
//Input: words = ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
//Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]
//Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats"; 
//"dogcatsdog" can be concatenated by "dog", "cats" and "dog"; 
//"ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".
//Example 2:
//Input: words = ["cat","dog","catdog"]
//Output: ["catdog"]
// 
//Constraints:
//	1 <= words.length <= 104
//	1 <= words[i].length <= 30
//	words[i] consists of only lowercase English letters.
//	All the strings of words are unique.
//	1 <= sum(words[i].length) <= 105
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findAllConcatenatedWordsInADict(char** words, int wordsSize, int* returnSize) {
    // Create a boolean array to store the existence of each word
    bool* wordExists = (bool*)calloc(wordsSize, sizeof(bool));
    
    // Create a Trie data structure to store all words
    Trie* root = createTrie();
    
    // Insert all words into the Trie
    for (int i = 0; i < wordsSize; i++) {
        insert(root, words[i]);
        wordExists[i] = true;
    }
    
    // Create an array to store the concatenated words
    char** result = (char**)calloc(wordsSize, sizeof(char*));
    *returnSize = 0;
    
    // Iterate through each word
    for (int i = 0; i < wordsSize; i++) {
        if (dfs(root, words[i], wordExists)) {
            result[*returnSize] = (char*)malloc((strlen(words[i]) + 1) * sizeof(char));
            strcpy(result[*returnSize], words[i]);
            (*returnSize)++;
        }
    }
    
    // Free the Trie and the boolean array
    freeTrie(root);
    free(wordExists);
    
    return result;
    
}