/**https://leetcode.com/problems/maximum-number-of-points-from-grid-queries/ */
//You are given an m x n integer matrix grid and an array queries of size k.
//Find an array answer of size k such that for each integer queries[i] you start in the top left cell of the matrix and repeat the following process:
//	If queries[i] is strictly greater than the value of the current cell that you are in, then you get one point if it is your first time visiting this cell, and you can move to any adjacent cell in all 4 directions: up, down, left, and right.
//	Otherwise, you do not get any points, and you end this process.
//After the process, answer[i] is the maximum number of points you can get. Note that for each query you are allowed to visit the same cell multiple times.
//Return the resulting array answer.
// 
//Example 1:
//Input: grid = [[1,2,3],[2,5,7],[3,5,1]], queries = [5,6,2]
//Output: [5,8,1]
//Explanation: The diagrams above show which cells we visit to get points for each query.
//Example 2:
//Input: grid = [[5,2,1],[1,1,2]], queries = [3]
//Output: [0]
//Explanation: We can not get any points because the value of the top left cell is already greater than or equal to 3.
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	2 <= m, n <= 1000
//	4 <= m * n <= 105
//	k == queries.length
//	1 <= k <= 104
//	1 <= grid[i][j], queries[i] <= 106
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxPoints(int** grid, int gridSize, int* gridColSize, int* queries, int queriesSize, int* returnSize) {
    int m = gridSize, n = *gridColSize;
    int* answer = (int*)malloc(sizeof(int) * queriesSize);
    int* sorted = (int*)malloc(sizeof(int) * m * n);
    int* idx = (int*)malloc(sizeof(int) * m * n);
    for (int i = 0; i < m * n; i++) {
        sorted[i] = grid[i / n][i % n];
        idx[i] = i;
    }
    qsort(idx, m * n, sizeof(int), cmp);
    int* dp = (int*)malloc(sizeof(int) * m * n);
    for (int i = 0; i < m * n; i++) {
        int x = idx[i] / n, y = idx[i] % n;
        dp[i] = sorted[i];
        if (x > 0 && sorted[i] > sorted[i - n]) {
            dp[i] = fmax(dp[i], dp[i - n] + sorted[i]);
        }
        if (y > 0 && sorted[i] > sorted[i - 1]) {
            dp[i] = fmax(dp[i], dp[i - 1] + sorted[i]);
        }
    }
    for (int i = 0; i < queriesSize; i++) {
        int left = 0, right = m * n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (sorted[mid] < queries[i]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if (right == -1) {
            answer[i] = m * n;
        } else {
            answer[i] = dp[right];
        }
    }
    *returnSize = queriesSize;
    return answer;    
}