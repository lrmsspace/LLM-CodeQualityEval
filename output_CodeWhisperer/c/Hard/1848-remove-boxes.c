/**https://leetcode.com/problems/remove-boxes/ */
//You are given several boxes with different colors represented by different positive numbers.
//You may experience several rounds to remove boxes until there is no box left. Each time you can choose some continuous boxes with the same color (i.e., composed of k boxes, k >= 1), remove them and get k * k points.
//Return the maximum points you can get.
// 
//Example 1:
//Input: boxes = [1,3,2,2,2,3,4,3,1]
//Output: 23
//Explanation:
//[1, 3, 2, 2, 2, 3, 4, 3, 1] 
//----> [1, 3, 3, 4, 3, 1] (3*3=9 points) 
//----> [1, 3, 3, 3, 1] (1*1=1 points) 
//----> [1, 1] (3*3=9 points) 
//----> [] (2*2=4 points)
//Example 2:
//Input: boxes = [1,1,1]
//Output: 9
//Example 3:
//Input: boxes = [1]
//Output: 1
// 
//Constraints:
//	1 <= boxes.length <= 100
//	1 <= boxes[i] <= 100
int removeBoxes(int* boxes, int boxesSize) {
    int n = boxesSize;
    int dp[n][n][n + 1];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            dp[i][j][0] = 0;
        }
    }
    for (int l = 1; l <= n; l++) {
        for (int i = 0; i <= n - l; i++) {
            int j = i + l - 1;
            for (int k = 0; k <= i; k++) {
                int res = (k + 1) * (k + 1) + dp[i + 1][j][0];
                for (int m = i + 1; m <= j; m++) {
                    if (boxes[i] == boxes[m]) {
                        res = fmax(res, dp[i + 1][m - 1][0] + dp[m][j][k + 1]);
                    }
                }
                dp[i][j][k] = res;
            }
        }
    }
    return dp[0][n - 1][0];
    
}