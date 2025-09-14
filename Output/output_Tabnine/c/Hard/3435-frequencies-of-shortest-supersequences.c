/*
 You are given an array of strings words. Find all shortest common supersequences (SCS) of words that are not permutations of each other.
 A shortest common supersequence is a string of minimum length that contains each string in words as a subsequence.
 Return a 2D array of integers freqs that represent all the SCSs. Each freqs[i] is an array of size 26, representing the frequency of each letter in the lowercase English alphabet for a single SCS. You may return the frequency arrays in any order.
 Example 1:
 Input: words = ["ab","ba"]
 Output: [[1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],[2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]]
 Explanation:
 The two SCSs are "aba" and "bab". The output is the letter frequencies for each one.
 Example 2:
 Input: words = ["aa","ac"]
 Output: [[2,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]]
 Explanation:
 The two SCSs are "aac" and "aca". Since they are permutations of each other, keep only "aac".
 Example 3:
 Input: words = ["aa","bb","cc"]
 Output: [[2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]]
 Explanation:
 "aabbcc" and all its permutations are SCSs.
 Constraints:
 1 <= words.length <= 256
 words[i].length == 2
 All strings in words will altogether be composed of no more than 16 unique lowercase letters.
 All strings in words are unique.
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MAX_N 256
#define MAX_WORD_LENGTH 2
#define ALPHABET_SIZE 26

bool isPermutation(char* word1, char* word2) {
    // Implement the logic to check if two strings are permutations of each other
    // Return true if they are permutations, false otherwise
    // ...
}

char* getSCS(char* word1, char* word2) {
    // Implement the logic to find the shortest common supersequence of two strings
    // Return the SCS as a new string
    // ...
}

int* calculateFrequency(char* scs) {
    // Implement the logic to calculate the frequency of each letter in the SCS
    // Return the frequency array
    // ...
}

int** supersequences(char** words, int wordsSize, int* returnSize, int** returnColumnSizes) {
    int count = 0;
    int** freqs = (int**)malloc(MAX_N * sizeof(int*));
    *returnColumnSizes = (int*)malloc(MAX_N * sizeof(int));

    for (int i = 0; i < wordsSize; i++) {
        for (int j = i + 1; j < wordsSize; j++) {
            char* scs = getSCS(words[i], words[j]);
            bool isValid = true;

            for (int k = 0; k < wordsSize; k++) {
                if (k != i && k != j && isPermutation(scs, words[k])) {
                    isValid = false;
                    break;
                }
            }

            if (isValid) {
                freqs[count] = calculateFrequency(scs);
                (*returnColumnSizes)[count] = ALPHABET_SIZE;
                count++;
            }

            free(scs);
        }
    }

    *returnSize = count;
    return freqs;
}