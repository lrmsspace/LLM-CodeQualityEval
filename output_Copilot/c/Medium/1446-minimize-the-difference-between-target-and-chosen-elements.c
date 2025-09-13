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
    int dp[71][800] = {0};
    int i, j, k, l, m, n, min = 800;
    for (i = 0; i < matSize; i++) {
        if (i == 0) {
            for (j = 0; j < matColSize[i]; j++) {
                dp[i][mat[i][j]] = 1;
            }
        } else {
            for (j = 0; j < 800; j++) {
                if (dp[i - 1][j] == 1) {
                    for (k = 0; k < matColSize[i]; k++) {
                        dp[i][j + mat[i][k]] = 1;
                    }
                }
            }
        }
    }
    for (i = 0; i < 800; i++) {
        if (dp[matSize - 1][i] == 1) {
            if (min > abs(i - target)) {
                min = abs(i - target);
            }
        }
    }
    return min;    
}