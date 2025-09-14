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
int* numSmallerByFrequency(char ** queries, int queriesSize, char ** words, int wordsSize, int* returnSize){
    int* ans = (int*)malloc(sizeof(int)*queriesSize);
    memset(ans, 0, sizeof(int)*queriesSize);
    int* w = (int*)malloc(sizeof(int)*wordsSize);
    memset(w, 0, sizeof(int)*wordsSize);
    int* q = (int*)malloc(sizeof(int)*queriesSize);
    memset(q, 0, sizeof(int)*queriesSize);
    for(int i=0;i<wordsSize;i++){
        int cnt = 0;
        for(int j=0;j<strlen(words[i]);j++){
            if(words[i][j]==words[i][0])
                cnt++;
        }
        w[i] = cnt;
    }
    for(int i=0;i<queriesSize;i++){
        int cnt = 0;
        for(int j=0;j<strlen(queries[i]);j++){
            if(queries[i][j]==queries[i][0])
                cnt++;
        }
        q[i] = cnt;
    }
    for(int i=0;i<queriesSize;i++){
        for(int j=0;j<wordsSize;j++){
            if(w[j]>q[i])
                ans[i]++;
        }
    }
    *returnSize = queriesSize;
    return ans;
}