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
    // Initialize result array
    int maxResults = 10000;
    int** result = (int**)malloc(maxResults * sizeof(int*));
    *returnColumnSizes = (int*)malloc(maxResults * sizeof(int));
    *returnSize = 0;
    
    // Count unique letters
    int letters[26] = {0};
    for(int i = 0; i < wordsSize; i++) {
        for(int j = 0; j < 2; j++) {
            letters[words[i][j] - 'a'] = 1;
        }
    }
    
    // Get number of unique letters
    int uniqueLetters = 0;
    for(int i = 0; i < 26; i++) {
        if(letters[i]) uniqueLetters++;
    }
    
    // Generate all possible sequences
    int maxLen = wordsSize * 2;
    char* seq = (char*)malloc((maxLen + 1) * sizeof(char));
    int* used = (int*)malloc(maxLen * sizeof(int));
    
    // Helper function to check if string is subsequence
    int isSubsequence(char* s, char* t) {
        int i = 0, j = 0;
        while(i < strlen(s) && j < strlen(t)) {
            if(s[i] == t[j]) i++;
            j++;
        }
        return i == strlen(s);
    }
    
    // Helper function to check if array exists
    int arrayExists(int* arr) {
        for(int i = 0; i < *returnSize; i++) {
            int match = 1;
            for(int j = 0; j < 26; j++) {
                if(result[i][j] != arr[j]) {
                    match = 0;
                    break;
                }
            }
            if(match) return 1;
        }
        return 0;
    }
    
    // Recursive function to generate sequences
    void generate(int pos, int len) {
        if(pos == len) {
            seq[len] = '\0';
            
            // Check if valid supersequence
            int valid = 1;
            for(int i = 0; i < wordsSize; i++) {
                if(!isSubsequence(words[i], seq)) {
                    valid = 0;
                    break;
                }
            }
            
            if(valid) {
                // Count frequencies
                int* freq = (int*)calloc(26, sizeof(int));
                for(int i = 0; i < len; i++) {
                    freq[seq[i] - 'a']++;
                }
                
                // Add to result if not already present
                if(!arrayExists(freq)) {
                    result[*returnSize] = freq;
                    (*returnColumnSizes)[*returnSize] = 26;
                    (*returnSize)++;
                } else {
                    free(freq);
                }
            }
            return;
        }
        
        for(int i = 0; i < 26; i++) {
            if(letters[i]) {
                seq[pos] = i + 'a';
                generate(pos + 1, len);
            }
        }
    }
    
    // Try different lengths
    for(int len = wordsSize; len <= maxLen; len++) {
        generate(0, len);
        // If we found any results, no need to try longer lengths
        if(*returnSize > 0) break;
    }
    
    free(seq);
    free(used);
    
    return result;
}    