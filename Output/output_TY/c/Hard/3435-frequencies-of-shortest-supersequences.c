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
int** supersequences(char** words, int wordsSize, int* returnSize, int** returnColumnSizes) {
    int i, j, k, m, n, t, x, y, z;
    int *freq, *cnt, *cnt2;
    int **res;
    int *cols;
    
    freq = (int *)malloc(sizeof(int) * 26);
    for (i = 0; i < wordsSize; i++) {
        for (j = 0; words[i][j]; j++) {
            freq[words[i][j] - 'a']++;
        }
    }
    
    cnt = (int *)malloc(sizeof(int) * 26);
    for (i = 0; i < 26; i++) {
        cnt[i] = freq[i] + 1;
    }   
    cnt2 = (int *)malloc(sizeof(int) * 26);
    for (i = 0; i < 26; i++) {
        cnt2[i] = freq[i];
    }   
    res = (int **)malloc(sizeof(int *) * 26);
    for (i = 0; i < 26; i++) {
        res[i] = (int *)malloc(sizeof(int) * cnt[i]);
    }
    for (i = 0; i < 26; i++) {
        for (j = 0; j < cnt[i]; j++) {
            res[i][j] = -1;
        }
    }   
    for (i = 0; i < 26; i++) {
        for (j = 0; j < cnt[i]; j++) {
            res[i][j] = j;
        }
    }
    for (i = 0; i < 26; i++) {
        for (j = 0; j < cnt[i]; j++) {
            for (k = 0; k < cnt2[i]; k++) {
                if (res[i][j] == -1 || res[i][j] > res[i][k]) {
                    res[i][j] = res[i][k];
                }
            }
        }
    }
    return res;
}
