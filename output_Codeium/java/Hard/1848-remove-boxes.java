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
        return dfs(dp, boxes, 0, n - 1);
        
    }
    
    private int dfs(int[][] dp, int[] boxes, int l, int r) {
        if (l > r) return 0;
        if (dp[l][r] > 0) return dp[l][r];
        int k = 1;
        while (l + k <= r && boxes[l] == boxes[l + k]) {
            k++;
        }
        int cur = (k * k) + dfs(dp, boxes, l + k, r);
        for (int i = l + k; i <= r; i++) {
            if (boxes[l] == boxes[i]) {
                cur = Math.max(cur, dfs(dp, boxes, l + 1, i - 1) + dfs(dp, boxes, i, r));
            }
        }
        dp[l][r] = cur;
        return cur;
    }
}