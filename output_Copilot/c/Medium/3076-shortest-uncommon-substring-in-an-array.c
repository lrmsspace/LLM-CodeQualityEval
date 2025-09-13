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
    char** answer = (char**)malloc(arrSize * sizeof(char*));
    for (int i = 0; i < arrSize; i++) {
        answer[i] = (char*)malloc(21 * sizeof(char));  // Max length of substring is 20
    }

    for (int i = 0; i < arrSize; i++) {
        int found = 0;
        for (int len = 1; len <= 20; len++) {
            for (int start = 0; start <= 20 - len; start++) {
                char* sub = (char*)malloc((len + 1) * sizeof(char));
                strncpy(sub, arr[i] + start, len);
                sub[len] = '\0';

                int isUncommon = 1;
                for (int j = 0; j < arrSize; j++) {
                    if (i != j && strstr(arr[j], sub) != NULL) {
                        isUncommon = 0;
                        break;
                    }
                }

                if (isUncommon) {
                    if (!found || strcmp(sub, answer[i]) < 0) {
                        strcpy(answer[i], sub);
                        found = 1;
                    }
                }
                free(sub);
            }
        }
        if (!found) {
            strcpy(answer[i], "");
        }
    }

    *returnSize = arrSize;
    return answer;
}