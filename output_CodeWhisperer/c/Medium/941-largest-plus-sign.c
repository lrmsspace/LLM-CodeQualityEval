/**https://leetcode.com/problems/largest-plus-sign/ */
//You are given an integer n. You have an n x n binary grid grid with all values initially 1's except for some indices given in the array mines. The ith element of the array mines is defined as mines[i] = [xi, yi] where grid[xi][yi] == 0.
//Return the order of the largest axis-aligned plus sign of 1's contained in grid. If there is none, return 0.
//An axis-aligned plus sign of 1's of order k has some center grid[r][c] == 1 along with four arms of length k - 1 going up, down, left, and right, and made of 1's. Note that there could be 0's or 1's beyond the arms of the plus sign, only the relevant area of the plus sign is checked for 1's.
// 
//Example 1:
//Input: n = 5, mines = [[4,2]]
//Output: 2
//Explanation: In the above grid, the largest plus sign can only be of order 2. One of them is shown.
//Example 2:
//Input: n = 1, mines = [[0,0]]
//Output: 0
//Explanation: There is no plus sign, so return 0.
// 
//Constraints:
//	1 <= n <= 500
//	1 <= mines.length <= 5000
//	0 <= xi, yi < n
//	All the pairs (xi, yi) are unique.
int orderOfLargestPlusSign(int n, int** mines, int minesSize, int* minesColSize) {
    int** dp = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        dp[i] = (int*)malloc(sizeof(int) * n);
        memset(dp[i], 0, sizeof(int) * n);
    }
    for (int i = 0; i < minesSize; i++) {
        dp[mines[i][0]][mines[i][1]] = -1;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dp[i][j] == -1) {
                continue;
            }
            int left = j > 0 ? dp[i][j - 1] : 0;
            int top = i > 0 ? dp[i - 1][j] : 0;
            dp[i][j] = 1 + (left == 0 ? 0 : left);
            int k = 1;
            while (k <= top && k <= left && k <= dp[i - k][j] && k <= dp[i][j - k]) {
                k++;
            }
            dp[i][j] = k;
            ans = fmax(ans, dp[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        free(dp[i]);
    }
    free(dp);
    return ans;
}