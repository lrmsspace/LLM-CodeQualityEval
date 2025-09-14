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
    int dp[101][101][101] = {0};
    int dp2[101][101][101] = {0};
    for (int i = 0; i < boxesSize; i++) {
        for (int j = i; j >= 0; j--) {
            for (int k = j; k < boxesSize && boxes[k] == boxes[j]; k++) {
                int points = (k - j + 1) * (k - j + 1) + dp2[j + 1][k][i];
                dp[j][k][i] = max(dp[j][k][i], points + dp[j][j][i - 1]);
                dp2[j][k][i] = max(dp2[j][k][i], dp[j][k][i]);
            }
        }
    }
    return dp[0][boxesSize - 1][boxesSize - 1];
}