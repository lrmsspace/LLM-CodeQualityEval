/*
 You are given an integer n and a 2D integer array queries.
 There are n cities numbered from 0 to n - 1. Initially, there is a unidirectional road from city i to city i + 1 for all 0 <= i < n - 1.
 queries[i] = [ui, vi] represents the addition of a new unidirectional road from city ui to city vi. After each query, you need to find the length of the shortest path from city 0 to city n - 1.
 Return an array answer where for each i in the range [0, queries.length - 1], answer[i] is the length of the shortest path from city 0 to city n - 1 after processing the first i + 1 queries.
 Example 1:
 Input: n = 5, queries = [[2,4],[0,2],[0,4]]
 Output: [3,2,1]
 Explanation: 
 After the addition of the road from 2 to 4, the length of the shortest path from 0 to 4 is 3.
 After the addition of the road from 0 to 2, the length of the shortest path from 0 to 4 is 2.
 After the addition of the road from 0 to 4, the length of the shortest path from 0 to 4 is 1.
 Example 2:
 Input: n = 4, queries = [[0,3],[0,2]]
 Output: [1,1]
 Explanation:
 After the addition of the road from 0 to 3, the length of the shortest path from 0 to 3 is 1.
 After the addition of the road from 0 to 2, the length of the shortest path remains 1.
 Constraints:
 3 <= n <= 500
 1 <= queries.length <= 500
 queries[i].length == 2
 0 <= queries[i][0] < queries[i][1] < n
 1 < queries[i][1] - queries[i][0]
 There are no repeated roads among the queries.
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shortestDistanceAfterQueries(int n, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    
    int *res = (int *)malloc(sizeof(int) * queriesSize);
    memset(res, 0, sizeof(int) * queriesSize);
    
    int *dis = (int *)malloc(sizeof(int) * n);
    memset(dis, 0, sizeof(int) * n);
    
    int *cnt = (int *)malloc(sizeof(int) * n);
    memset(cnt, 0, sizeof(int) * n);
    
    for (int i = 0; i < queriesSize; i++) {
        int a = queries[i][0];
        int b = queries[i][1];
        
        dis[a]++;
    }
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            dis[i] += dis[i - 1];
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (i < n - 1) {
            dis[i] += dis[i + 1];
        }
    }
    for (int i = 0; i < queriesSize; i++) {
        int a = queries[i][0];
        int b = queries[i][1];
        
        cnt[a]++;
        if (b + 1 < n) {
            cnt[b + 1]--;
        }
    }
    for (int i = 1; i < n; i++) {
        cnt[i] += cnt[i - 1];
    }
    for (int i = 0; i < n; i++) {
        dis[i] *= cnt[i];
    }
    return dis;
}