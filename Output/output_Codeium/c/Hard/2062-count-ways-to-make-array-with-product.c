/**https://leetcode.com/problems/count-ways-to-make-array-with-product/ */
//You are given a 2D integer array, queries. For each queries[i], where queries[i] = [ni, ki], find the number of different ways you can place positive integers into an array of size ni such that the product of the integers is ki. As the number of ways may be too large, the answer to the ith query is the number of ways modulo 109 + 7.
//Return an integer array answer where answer.length == queries.length, and answer[i] is the answer to the ith query.
// 
//Example 1:
//Input: queries = [[2,6],[5,1],[73,660]]
//Output: [4,1,50734910]
//Explanation: Each query is independent.
//[2,6]: There are 4 ways to fill an array of size 2 that multiply to 6: [1,6], [2,3], [3,2], [6,1].
//[5,1]: There is 1 way to fill an array of size 5 that multiply to 1: [1,1,1,1,1].
//[73,660]: There are 1050734917 ways to fill an array of size 73 that multiply to 660. 1050734917 modulo 109 + 7 = 50734910.
//Example 2:
//Input: queries = [[1,1],[2,2],[3,3],[4,4],[5,5]]
//Output: [1,2,3,10,5]
// 
//Constraints:
//	1 <= queries.length <= 104 
//	1 <= ni, ki <= 104
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* waysToFillArray(int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    *returnSize = queriesSize;
    int* result = (int*)malloc(queriesSize * sizeof(int));
    for (int i = 0; i < queriesSize; i++) {
        int n = queries[i][0];
        long long k = queries[i][1];
        long long count = 1;
        for (int j = 1; j <= n; j++) {
            if (k % j == 0) {
                count += (k / j) % 1000000007;
            }
        }
        result[i] = count % 1000000007;
    }
    return result;
}