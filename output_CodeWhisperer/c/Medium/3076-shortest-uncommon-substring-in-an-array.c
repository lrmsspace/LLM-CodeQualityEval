/*
 You are given an array arr of size n consisting of non-empty strings.
 Find a string array answer of size n such that:
 answer[i] is the shortest substring of arr[i] that does not occur as a substring in any other string in arr. If multiple such substrings exist, answer[i] should be the lexicographically smallest. And if no such substring exists, answer[i] should be an empty string.
 Return the array answer.
 Example 1:
 Input: arr = ["cab","ad","bad","c"]
 Output: ["ab","","ba",""]
 Explanation: We have the following:
 - For the string "cab", the shortest substring that does not occur in any other string is either "ca" or "ab", we choose the lexicographically smaller substring, which is "ab".
 - For the string "ad", there is no substring that does not occur in any other string.
 - For the string "bad", the shortest substring that does not occur in any other string is "ba".
 - For the string "c", there is no substring that does not occur in any other string.
 Example 2:
 Input: arr = ["abc","bcd","abcd"]
 Output: ["","","abcd"]
 Explanation: We have the following:
 - For the string "abc", there is no substring that does not occur in any other string.
 - For the string "bcd", there is no substring that does not occur in any other string.
 - For the string "abcd", the shortest substring that does not occur in any other string is "abcd".
 Constraints:
 n == arr.length
 2 <= n <= 100
 1 <= arr[i].length <= 20
 arr[i] consists only of lowercase English letters.
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** shortestSubstrings(char** arr, int arrSize, int* returnSize) {
    char** result = (char**)malloc(arrSize * sizeof(char*));
    *returnSize = arrSize;
    
    // Initialize result array with empty strings
    for(int i = 0; i < arrSize; i++) {
        result[i] = (char*)malloc(sizeof(char));
        result[i][0] = '\0';
    }
    
    // For each string in input array
    for(int i = 0; i < arrSize; i++) {
        int len = strlen(arr[i]);
        char* curr_best = NULL;
        
        // Try all possible substring lengths
        for(int sublen = 1; sublen <= len; sublen++) {
            // Try all possible starting positions
            for(int start = 0; start <= len - sublen; start++) {
                int found = 0;
                
                // Extract current substring
                char* substr = (char*)malloc((sublen + 1) * sizeof(char));
                strncpy(substr, arr[i] + start, sublen);
                substr[sublen] = '\0';
                
                // Check if this substring exists in other strings
                for(int j = 0; j < arrSize; j++) {
                    if(i == j) continue;
                    
                    char* pos = strstr(arr[j], substr);
                    if(pos != NULL) {
                        found = 1;
                        break;
                    }
                }
                
                // If substring not found in other strings
                if(!found) {
                    if(curr_best == NULL || 
                       strlen(substr) < strlen(curr_best) ||
                       (strlen(substr) == strlen(curr_best) && strcmp(substr, curr_best) < 0)) {
                        free(curr_best);
                        curr_best = strdup(substr);
                    }
                }
                free(substr);
            }
            
            // If we found a valid substring, no need to check longer lengths
            if(curr_best != NULL) break;
        }
        
        // Update result
        if(curr_best != NULL) {
            free(result[i]);
            result[i] = curr_best;
        }
    }
    
    return result;
}    