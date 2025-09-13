/*
 You are given a binary string s and an integer k.
 You are also given a 2D integer array queries, where queries[i] = [li, ri].
 A binary string satisfies the k-constraint if either of the following conditions holds:
 The number of 0's in the string is at most k.
 The number of 1's in the string is at most k.
 Return an integer array answer, where answer[i] is the number of substrings of s[li..ri] that satisfy the k-constraint.
 Example 1:
 Input: s = "0001111", k = 2, queries = [[0,6]]
 Output: [26]
 Explanation:
 For the query [0, 6], all substrings of s[0..6] = "0001111" satisfy the k-constraint except for the substrings s[0..5] = "000111" and s[0..6] = "0001111".
 Example 2:
 Input: s = "010101", k = 1, queries = [[0,5],[1,4],[2,3]]
 Output: [15,9,3]
 Explanation:
 The substrings of s with a length greater than 3 do not satisfy the k-constraint.
 Constraints:
 1 <= s.length <= 105
 s[i] is either '0' or '1'.
 1 <= k <= s.length
 1 <= queries.length <= 105
 queries[i] == [li, ri]
 0 <= li <= ri < s.length
 All queries are distinct.
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
long long* countKConstraintSubstrings(char* s, int k, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    int n = strlen(s);
    long long* answer = (long long*)malloc(queriesSize * sizeof(long long));
    int* prefixSum = (int*)malloc((n + 1) * sizeof(int));
    prefixSum[0] = 0;
    for (int i = 0; i < n; i++) {
        prefixSum[i + 1] = prefixSum[i] + (s[i] == '0' ? 1 : 0);
    }
    for (int i = 0; i < queriesSize; i++) {
        int l = queries[i][0];
        int r = queries[i][1];
        int count = 0;
        for (int j = l; j <= r; j++) {
            for (int k = j; k <= r; k++) {
                int zeros = prefixSum[k + 1] - prefixSum[j];
                int ones = k - j + 1 - zeros;
                if (zeros <= k && ones <= k) {
                    count++;
                }
            }
        }
        answer[i] = count;
    }
    *returnSize = queriesSize;
    free(prefixSum);
    return answer;
        
}