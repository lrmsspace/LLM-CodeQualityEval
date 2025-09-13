/**https://leetcode.com/problems/palindrome-pairs/ */
//You are given a 0-indexed array of unique strings words.
//A palindrome pair is a pair of integers (i, j) such that:
//	0 <= i, j < words.length,
//	i != j, and
//	words[i] + words[j] (the concatenation of the two strings) is a palindrome.
//Return an array of all the palindrome pairs of words.
//You must write an algorithm with O(sum of words[i].length) runtime complexity.
// 
//Example 1:
//Input: words = ["abcd","dcba","lls","s","sssll"]
//Output: [[0,1],[1,0],[3,2],[2,4]]
//Explanation: The palindromes are ["abcddcba","dcbaabcd","slls","llssssll"]
//Example 2:
//Input: words = ["bat","tab","cat"]
//Output: [[0,1],[1,0]]
//Explanation: The palindromes are ["battab","tabbat"]
//Example 3:
//Input: words = ["a",""]
//Output: [[0,1],[1,0]]
//Explanation: The palindromes are ["a","a"]
// 
//Constraints:
//	1 <= words.length <= 5000
//	0 <= words[i].length <= 300
//	words[i] consists of lowercase English letters.
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** palindromePairs(char** words, int wordsSize, int* returnSize, int** returnColumnSizes) {
    // Step 1: Initialize the return size and column sizes
    *returnSize = 0;
    *returnColumnSizes = malloc(wordsSize * sizeof(int));
    for (int i = 0; i < wordsSize; i++) {
        (*returnColumnSizes)[i] = 2;
    }
    
    // Step 2: Create a dictionary to store the reverse of each word
    char** reverseWords = malloc(wordsSize * sizeof(char*));
    for (int i = 0; i < wordsSize; i++) {
        reverseWords[i] = malloc((strlen(words[i]) + 1) * sizeof(char));
        strcpy(reverseWords[i], words[i]);
        strrev(reverseWords[i]);
    }
    
    // Step 3: Create a 2D array to store the result
    int** result = malloc(wordsSize * sizeof(int*));
    for (int i = 0; i < wordsSize; i++) {
        result[i] = malloc(2 * sizeof(int));
    }
    
    // Step 4: Iterate through each word and check for palindrome pairs
    for (int i = 0; i < wordsSize; i++) {
        for (int j = 0; j < wordsSize; j++) {
            if (i == j) continue;
            
            // Check if the concatenation of words[i] and reverseWords[j] is a palindrome
            if (isPalindrome(words[i], reverseWords[j])) {
                result[*returnSize][0] = i;
                result[*returnSize][1] = j;
                (*returnSize)++;
            }
            
            // Check if the concatenation of reverseWords[i] and words[j] is a palindrome
            if (isPalindrome(reverseWords[i], words[j])) {
                result[*returnSize][0] = j;
                result[*returnSize][1] = i;
                (*returnSize)++;
            }
        }
    }
    
    // Step 5: Free the allocated memory
    for (int i = 0; i < wordsSize; i++) {
        free(reverseWords[i]);
    }
    free(reverseWords);
    
    return result;
    
}