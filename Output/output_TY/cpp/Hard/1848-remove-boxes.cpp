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
public:
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, 0)));

        for (int i = 0; i < n; i++) {
            dp[i][i][0] = (i + 1) * (i + 1);
        }

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                for (int k = 0; k < j; k++) {
                    dp[i][j][k] = max(dp[i][j][k], dp[i][k][0] + dp[k + 1][j][0] + (i == 0 ? 0 : (i + 1) * (i + 1)));
                    if (boxes[i] == boxes[k + 1]) {
                        dp[i][j][k] = max(dp[i][j][k], dp[i][k][k + 1] + (i == 0 ? 0 : (i + 1) * (i + 1)));
                    }
                }
            }
        }
        return dp[0][n - 1][0];
    }
};