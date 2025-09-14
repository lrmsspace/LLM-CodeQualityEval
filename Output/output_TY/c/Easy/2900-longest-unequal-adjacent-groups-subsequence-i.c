/*
 You are given a string array words and a binary array groups both of length n.
 A subsequence of words is alternating if for any two consecutive strings in the sequence, their corresponding elements at the same indices in groups are different (that is, there cannot be consecutive 0 or 1).
 Your task is to select the longest alternating subsequence from words.
 Return the selected subsequence. If there are multiple answers, return any of them.
 Note: The elements in words are distinct.
 Example 1:
 Input: words = ["e","a","b"], groups = [0,0,1]
 Output: ["e","b"]
 Explanation: A subsequence that can be selected is ["e","b"] because groups[0] != groups[2]. Another subsequence that can be selected is ["a","b"] because groups[1] != groups[2]. It can be demonstrated that the length of the longest subsequence of indices that satisfies the condition is 2.
 Example 2:
 Input: words = ["a","b","c","d"], groups = [1,0,1,1]
 Output: ["a","b","c"]
 Explanation: A subsequence that can be selected is ["a","b","c"] because groups[0] != groups[1] and groups[1] != groups[2]. Another subsequence that can be selected is ["a","b","d"] because groups[0] != groups[1] and groups[1] != groups[3]. It can be shown that the length of the longest subsequence of indices that satisfies the condition is 3.
 Constraints:
 1 <= n == words.length == groups.length <= 100
 1 <= words[i].length <= 10
 groups[i] is either 0 or 1.
 words consists of distinct strings.
 words[i] consists of lowercase English letters.
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** getLongestSubsequence(char** words, int wordsSize, int* groups, int groupsSize, int* returnSize) {
    *returnSize = 0;
    char **res = (char **)malloc(sizeof(char *) * wordsSize);
    int i, j, k, l, m, n, max_len = 0;
    int *len = (int *)malloc(sizeof(int) * wordsSize);
    int *index = (int *)malloc(sizeof(int) * wordsSize);
    
    for (i = 0; i < wordsSize; i++) {
        len[i] = 1;
        index[i] = i;
    }
    
    for (i = 0; i < wordsSize; i++) {
        for (j = i + 1; j < wordsSize; j++) {
            if (groups[i] != groups[j]) {
                if (strcmp(words[i], words[j]) < 0) {
                    if (len[j] < len[i] + 1) {
                        len[j] = len[i] + 1;
                        index[j] = i;
                    }
                }
            }
        }
    }
    for (i = 0; i < wordsSize; i++) {
        if (len[i] > max_len) {
            max_len = len[i];
        }
    }
    for (i = 0; i < wordsSize; i++) {
        if (len[i] == max_len) {
            res[(*returnSize)++] = words[i];
        }
    }
    for (i = 0; i < *returnSize; i++) {
        for (j = i + 1; j < *returnSize; j++) {
            if (strcmp(res[i], res[j]) > 0) {
                char *tmp = res[i];
                res[i] = res[j];
                res[j] = tmp;
            }
        }
    }
    return res;
    
}