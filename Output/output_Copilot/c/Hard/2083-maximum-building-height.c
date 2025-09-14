/**https://leetcode.com/problems/maximum-building-height/ */
//You want to build n new buildings in a city. The new buildings will be built in a line and are labeled from 1 to n.
//However, there are city restrictions on the heights of the new buildings:
//	The height of each building must be a non-negative integer.
//	The height of the first building must be 0.
//	The height difference between any two adjacent buildings cannot exceed 1.
//Additionally, there are city restrictions on the maximum height of specific buildings. These restrictions are given as a 2D integer array restrictions where restrictions[i] = [idi, maxHeighti] indicates that building idi must have a height less than or equal to maxHeighti.
//It is guaranteed that each building will appear at most once in restrictions, and building 1 will not be in restrictions.
//Return the maximum possible height of the tallest building.
// 
//Example 1:
//Input: n = 5, restrictions = [[2,1],[4,1]]
//Output: 2
//Explanation: The green area in the image indicates the maximum allowed height for each building.
//We can build the buildings with heights [0,1,2,1,2], and the tallest building has a height of 2.
//Example 2:
//Input: n = 6, restrictions = []
//Output: 5
//Explanation: The green area in the image indicates the maximum allowed height for each building.
//We can build the buildings with heights [0,1,2,3,4,5], and the tallest building has a height of 5.
//Example 3:
//Input: n = 10, restrictions = [[5,3],[2,5],[7,4],[10,3]]
//Output: 5
//Explanation: The green area in the image indicates the maximum allowed height for each building.
//We can build the buildings with heights [0,1,2,3,3,4,4,5,4,3], and the tallest building has a height of 5.
// 
//Constraints:
//	2 <= n <= 109
//	0 <= restrictions.length <= min(n - 1, 105)
//	2 <= idi <= n
//	idi is unique.
//	0 <= maxHeighti <= 109
int maxBuilding(int n, int** restrictions, int restrictionsSize, int* restrictionsColSize) {
       int m = restrictionsSize;
        int len = m + 2;
        int dp[len][2];
        dp[0][0] = 1;
        dp[0][1] = 0;
        for (int i = 1; i <= m; i++) {
            dp[i][0] = restrictions[i - 1][0];
            dp[i][1] = restrictions[i - 1][1];
        }
        dp[m + 1][0] = n;
        dp[m + 1][1] = n - 1;
        qsort(dp, len, sizeof(int) * 2, cmp);
        for (int i = 1; i < len; i++) {
            dp[i][1] = fmin(dp[i][1], dp[i - 1][1] + dp[i][0] - dp[i - 1][0]);
        }
        for (int i = len - 2; i >= 0; i--) {
            dp[i][1] = fmin(dp[i][1], dp[i + 1][1] + dp[i + 1][0] - dp[i][0]);
        }
        int res = 0;
        for (int i = 1; i < len; i++) {
            int h = dp[i][1] + dp[i][0] - dp[i - 1][0];
            h = fmin(h, dp[i - 1][1] + dp[i][0] - dp[i - 1][0]);
            res = fmax(res, (h + dp[i - 1][1]) / 2);
        }
        return res;     
}