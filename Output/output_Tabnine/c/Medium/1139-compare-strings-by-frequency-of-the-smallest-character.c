/**https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/ */
//Let the function f(s) be the frequency of the lexicographically smallest character in a non-empty string s. For example, if s = "dcce" then f(s) = 2 because the lexicographically smallest character is 'c', which has a frequency of 2.
//You are given an array of strings words and another array of query strings queries. For each query queries[i], count the number of words in words such that f(queries[i]) < f(W) for each W in words.
//Return an integer array answer, where each answer[i] is the answer to the ith query.
// 
//Example 1:
//Input: queries = ["cbd"], words = ["zaaaz"]
//Output: [1]
//Explanation: On the first query we have f("cbd") = 1, f("zaaaz") = 3 so f("cbd") < f("zaaaz").
//Example 2:
//Input: queries = ["bbb","cc"], words = ["a","aa","aaa","aaaa"]
//Output: [1,2]
//Explanation: On the first query only f("bbb") < f("aaaa"). On the second query both f("aaa") and f("aaaa") are both > f("cc").
// 
//Constraints:
//	1 <= queries.length <= 2000
//	1 <= words.length <= 2000
//	1 <= queries[i].length, words[i].length <= 10
//	queries[i][j], words[i][j] consist of lowercase English letters.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* numSmallerByFrequency(char** queries, int queriesSize, char** words, int wordsSize, int* returnSize) {
    int* result = malloc(queriesSize * sizeof(int));
    *returnSize = queriesSize;
    
    // Count the frequency of the smallest character in each word
    int** freq = malloc(wordsSize * sizeof(int*));
    for (int i = 0; i < wordsSize; i++) {
        freq[i] = malloc(26 * sizeof(int));
        memset(freq[i], 0, 26 * sizeof(int));
        freq[i][words[i][0] - 'a'] = 1;
        for (int j = 1; j < strlen(words[i]); j++) {
            freq[i][words[i][j] - 'a']++;
        }
    }
    
    // Count the number of words with smaller frequency
    for (int i = 0; i < queriesSize; i++) {
        int smaller = 0;
        for (int j = 0; j < wordsSize; j++) {
            if (freq[j][queries[i][0] - 'a'] < freq[i][queries[i][0] - 'a']) {
                smaller++;
            }
        }
        result[i] = smaller;
    }
    
    // Free the memory
    for (int i = 0; i < wordsSize; i++) {
        free(freq[i]);
    }
    free(freq);
    
    return result;
    
}