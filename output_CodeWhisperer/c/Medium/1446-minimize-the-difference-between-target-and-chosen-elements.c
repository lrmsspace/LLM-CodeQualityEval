/**https://leetcode.com/problems/minimize-the-difference-between-target-and-chosen-elements/ */
//You are given an m x n integer matrix mat and an integer target.
//Choose one integer from each row in the matrix such that the absolute difference between target and the sum of the chosen elements is minimized.
//Return the minimum absolute difference.
//The absolute difference between two numbers a and b is the absolute value of a - b.
// 
//Example 1:
//Input: mat = [[1,2,3],[4,5,6],[7,8,9]], target = 13
//Output: 0
//Explanation: One possible choice is to:
//- Choose 1 from the first row.
//- Choose 5 from the second row.
//- Choose 7 from the third row.
//The sum of the chosen elements is 13, which equals the target, so the absolute difference is 0.
//Example 2:
//Input: mat = [[1],[2],[3]], target = 100
//Output: 94
//Explanation: The best possible choice is to:
//- Choose 1 from the first row.
//- Choose 2 from the second row.
//- Choose 3 from the third row.
//The sum of the chosen elements is 6, and the absolute difference is 94.
//Example 3:
//Input: mat = [[1,2,9,8,7]], target = 6
//Output: 1
//Explanation: The best choice is to choose 7 from the first row.
//The absolute difference is 1.
// 
//Constraints:
//	m == mat.length
//	n == mat[i].length
//	1 <= m, n <= 70
//	1 <= mat[i][j] <= 70
//	1 <= target <= 800
int minimizeTheDifference(int** mat, int matSize, int* matColSize, int target) {
    int m = matSize;
    int n = matColSize[0];
    int dp[71] = {0};
    dp[0] = 1;
    for (int i = 0; i < m; i++) {
        int dp2[71] = {0};
        for (int j = 0; j <= 70; j++) {
            if (dp[j] == 0) continue;
            for (int k = 0; k < n; k++) {
                if (j + mat[i][k] > 70) continue;
                dp2[j + mat[i][k]] = 1;
            }
        }
        for (int j = 0; j <= 70; j++) {
            if (dp2[j] == 0) continue;
            dp[j] = 1;
        }
    }
    int ans = 100000;
    for (int i = 0; i <= 70; i++) {
        if (dp[i] == 0) continue;
        ans = fmin(ans, abs(i - target));
    }
    return ans;
}