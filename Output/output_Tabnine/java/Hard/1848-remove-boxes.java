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
class Solution {
    public int removeBoxes(int[] boxes) {
        int n = boxes.length;
        int[][] dp = new int[n][n];
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                int k = 0;
                while (j < n && boxes[i] == boxes[j]) {
                    j++;
                    k++;
                }
                dp[i][j] = Math.max(dp[i][j], dp[i + 1][j] + dp[i + 1][j - 1] + k * k);
                for (int m = i + 1; m < j; m++) {
                    if (boxes[i] == boxes[m]) {
                        dp[i][j] = Math.max(dp[i][j], dp[i + 1][m - 1] + dp[m][j] + k * k);
                    }
                }
            }
        }
        return dp[0][n - 1];
        
    }
}