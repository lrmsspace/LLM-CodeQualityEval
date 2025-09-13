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
int removeBoxes(int* boxes, int boxesSize){
    int *dp = (int *)malloc(sizeof(int) * boxesSize * boxesSize);
    for (int i = 0; i < boxesSize; i++) {
        dp[i * boxesSize + i] = 1;
    }
    for (int i = boxesSize - 2; i >= 0; i--) {
        for (int j = i + 1; j < boxesSize; j++) {
            dp[i * boxesSize + j] = dp[(i + 1) * boxesSize + j] + (boxes[i] == boxes[i + 1] ? dp[i + 2 * boxesSize + j] : 0);
        }
    }
    return dp[0];
}