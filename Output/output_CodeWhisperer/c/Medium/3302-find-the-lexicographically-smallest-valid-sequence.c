/*
 You are given two strings word1 and word2.
 A string x is called almost equal to y if you can change at most one character in x to make it identical to y.
 A sequence of indices seq is called valid if:
 The indices are sorted in ascending order.
 Concatenating the characters at these indices in word1 in the same order results in a string that is almost equal to word2.
 Return an array of size word2.length representing the lexicographically smallest valid sequence of indices. If no such sequence of indices exists, return an empty array.
 Note that the answer must represent the lexicographically smallest array, not the corresponding string formed by those indices.
 Example 1:
 Input: word1 = "vbcca", word2 = "abc"
 Output: [0,1,2]
 Explanation:
 The lexicographically smallest valid sequence of indices is [0, 1, 2]:
 Change word1[0] to 'a'.
 word1[1] is already 'b'.
 word1[2] is already 'c'.
 Example 2:
 Input: word1 = "bacdc", word2 = "abc"
 Output: [1,2,4]
 Explanation:
 The lexicographically smallest valid sequence of indices is [1, 2, 4]:
 word1[1] is already 'a'.
 Change word1[2] to 'b'.
 word1[4] is already 'c'.
 Example 3:
 Input: word1 = "aaaaaa", word2 = "aaabc"
 Output: []
 Explanation:
 There is no valid sequence of indices.
 Example 4:
 Input: word1 = "abc", word2 = "ab"
 Output: [0,1]
 Constraints:
 1 <= word2.length < word1.length <= 3 * 105
 word1 and word2 consist only of lowercase English letters.
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* validSequence(char* word1, char* word2, int* returnSize) {
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    *returnSize = 0;
    
    // Check constraints
    if(len2 >= len1) {
        return NULL;
    }
    
    int* result = (int*)malloc(len2 * sizeof(int));
    
    // Try all possible combinations
    int start = 0;
    int pos = 0;
    int diffCount = 0;
    
    for(int i = 0; i < len2; i++) {
        int found = 0;
        
        // Find next matching or almost matching character
        for(int j = start; j < len1; j++) {
            if(word1[j] == word2[i] || (diffCount == 0 && pos == i)) {
                result[pos] = j;
                found = 1;
                start = j + 1;
                
                if(word1[j] != word2[i]) {
                    diffCount++;
                }
                
                pos++;
                break;
            }
        }
        
        if(!found) {
            *returnSize = 0;
            free(result);
            return NULL;
        }
    }
    
    // Check if sequence is valid
    if(pos == len2) {
        *returnSize = len2;
        return result;
    }
    
    free(result);
    return NULL;
}    