/*
 There is an m x n cake that needs to be cut into 1 x 1 pieces.
 You are given integers m, n, and two arrays:
 horizontalCut of size m - 1, where horizontalCut[i] represents the cost to cut along the horizontal line i.
 verticalCut of size n - 1, where verticalCut[j] represents the cost to cut along the vertical line j.
 In one operation, you can choose any piece of cake that is not yet a 1 x 1 square and perform one of the following cuts:
 Cut along a horizontal line i at a cost of horizontalCut[i].
 Cut along a vertical line j at a cost of verticalCut[j].
 After the cut, the piece of cake is divided into two distinct pieces.
 The cost of a cut depends only on the initial cost of the line and does not change.
 Return the minimum total cost to cut the entire cake into 1 x 1 pieces.
 Example 1:
 Input: m = 3, n = 2, horizontalCut = [1,3], verticalCut = [5]
 Output: 13
 Explanation:
 Perform a cut on the vertical line 0 with cost 5, current total cost is 5.
 Perform a cut on the horizontal line 0 on 3 x 1 subgrid with cost 1.
 Perform a cut on the horizontal line 0 on 3 x 1 subgrid with cost 1.
 Perform a cut on the horizontal line 1 on 2 x 1 subgrid with cost 3.
 Perform a cut on the horizontal line 1 on 2 x 1 subgrid with cost 3.
 The total cost is 5 + 1 + 1 + 3 + 3 = 13.
 Example 2:
 Input: m = 2, n = 2, horizontalCut = [7], verticalCut = [4]
 Output: 15
 Explanation:
 Perform a cut on the horizontal line 0 with cost 7.
 Perform a cut on the vertical line 0 on 1 x 2 subgrid with cost 4.
 Perform a cut on the vertical line 0 on 1 x 2 subgrid with cost 4.
 The total cost is 7 + 4 + 4 = 15.
 Constraints:
 1 <= m, n <= 20
 horizontalCut.length == m - 1
 verticalCut.length == n - 1
 1 <= horizontalCut[i], verticalCut[i] <= 103
*/

int minimumCost(int m, int n, int* horizontalCut, int horizontalCutSize, int* verticalCut, int verticalCutSize) {
    int i, j, k, min, min1, min2, sum = 0;
    int** dp = (int**)malloc(sizeof(int*) * m);
    for (i = 0; i < m; i++) {
        dp[i] = (int*)malloc(sizeof(int) * n);
        for (j = 0; j < n; j++) {
            dp[i][j] = 0;
        }
    }
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            min1 = INT_MAX;
            min2 = INT_MAX;
            for (k = 0; k < i; k++) {
                min1 = min1 < dp[k][j] + verticalCut[j] ? min1 : dp[k][j] + verticalCut[j];
            }
            for (k = 0; k < j; k++) {
                min2 = min2 < dp[i][k] + horizontalCut[i] ? min2 : dp[i][k] + horizontalCut[i];
            }
            dp[i][j] = min1 < min2 ? min1 : min2;
        }
    }
    return dp[m - 1][n - 1];    
}