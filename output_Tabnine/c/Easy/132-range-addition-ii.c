/**https://leetcode.com/problems/range-addition-ii/ */
//You are given an m x n matrix M initialized with all 0's and an array of operations ops, where ops[i] = [ai, bi] means M[x][y] should be incremented by one for all 0 <= x < ai and 0 <= y < bi.
//Count and return the number of maximum integers in the matrix after performing all the operations.
// 
//Example 1:
//Input: m = 3, n = 3, ops = [[2,2],[3,3]]
//Output: 4
//Explanation: The maximum integer in M is 2, and there are four of it in M. So return 4.
//Example 2:
//Input: m = 3, n = 3, ops = [[2,2],[3,3],[3,3],[3,3],[2,2],[3,3],[3,3],[3,3],[2,2],[3,3],[3,3],[3,3]]
//Output: 4
//Example 3:
//Input: m = 3, n = 3, ops = []
//Output: 9
// 
//Constraints:
//	1 <= m, n <= 4 * 104
//	0 <= ops.length <= 104
//	ops[i].length == 2
//	1 <= ai <= m
//	1 <= bi <= n
int maxCount(int m, int n, int** ops, int opsSize, int* opsColSize) {
    int* rowMax = (int*)calloc(m, sizeof(int));
    int* colMax = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < opsSize; i++) {
        rowMax[ops[i][0] - 1] = fmax(rowMax[ops[i][0] - 1], ops[i][1]);
        colMax[ops[i][1] - 1] = fmax(colMax[ops[i][1] - 1], ops[i][0]);
    }
    int maxCount = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            maxCount += min(rowMax[i], colMax[j]);
        }
    }
    free(rowMax);
    free(colMax);
    return maxCount;
}