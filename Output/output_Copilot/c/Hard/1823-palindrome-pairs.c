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
    *returnSize = 0;
    int** result = (int**)malloc(10000 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(10000 * sizeof(int));
    int* wordLengths = (int*)malloc(wordsSize * sizeof(int));
    for (int i = 0; i < wordsSize; i++) {
        wordLengths[i] = strlen(words[i]);
    }
    int** trie = (int**)malloc(26 * sizeof(int*));
    for (int i = 0; i < 26; i++) {
        trie[i] = NULL;
    }
    for (int i = 0; i < wordsSize; i++) {
        int len = wordLengths[i];
        int** node = trie;
        for (int j = len - 1; j >= 0; j--) {
            int index = words[i][j] - 'a';
            if (node[index] == NULL) {
                node[index] = (int*)malloc(27 * sizeof(int));
                for (int k = 0; k < 26; k++) {
                    node[index][k] = 0;
                }
                node[index][26] = 0;
            }
            node = (int**)node[index];
        }
        node[26] = i + 1;
    }
    for (int i = 0; i < wordsSize; i++) {
        int len = wordLengths[i];
        for (int j = 0; j <= len; j++) {
            if (isPalindrome(words[i], j, len - 1)) {
                int** node = trie;
                for (int k = 0; k < j; k++) {
                    int index = words[i][k] - 'a';
                    if (node[index] == NULL) {
                        break;
                    }
                    node = (int**)node[index];
                }
                if (node != NULL) {
                    int index = node[26] - 1;
                    if (index != i) {
                        result[*returnSize] = (int*)malloc(2 * sizeof(int));
                        result[*returnSize][0] = i;
                        result[*returnSize][1] = index;
                        (*returnColumnSizes)[*returnSize] = 2;
                        (*returnSize)++;
                    }
                }
            }
            if (isPalindrome(words[i], 0, j - 1)) {
                int** node = trie;
                for (int k = j; k < len; k++) {
                    int index = words[i][k] - 'a';
                    if (node[index] == NULL) {
                        break;
                    }
                    node = (int**)node[index];
                }
                if (node != NULL) {
                    int index = node[26] - 1;
                    if (index != i) {
                        result[*returnSize] = (int*)malloc(2 * sizeof(int));
                        result[*returnSize][0] = index;
                        result[*returnSize][1] = i;
                        (*returnColumnSizes)[*returnSize] = 2;
                        (*returnSize)++;
                    }
                }
            }
            }
            }
            free(wordLengths);
            for (int i = 0; i < 26; i++) {
            if (trie[i] != NULL) {
                free(trie[i]);
            }
            }
            free(trie);
            return result;
        }

        