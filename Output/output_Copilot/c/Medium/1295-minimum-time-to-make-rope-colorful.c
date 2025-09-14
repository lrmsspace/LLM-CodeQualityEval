/**https://leetcode.com/problems/minimum-time-to-make-rope-colorful/ */
//Alice has n balloons arranged on a rope. You are given a 0-indexed string colors where colors[i] is the color of the ith balloon.
//Alice wants the rope to be colorful. She does not want two consecutive balloons to be of the same color, so she asks Bob for help. Bob can remove some balloons from the rope to make it colorful. You are given a 0-indexed integer array neededTime where neededTime[i] is the time (in seconds) that Bob needs to remove the ith balloon from the rope.
//Return the minimum time Bob needs to make the rope colorful.
// 
//Example 1:
//Input: colors = "abaac", neededTime = [1,2,3,4,5]
//Output: 3
//Explanation: In the above image, 'a' is blue, 'b' is red, and 'c' is green.
//Bob can remove the blue balloon at index 2. This takes 3 seconds.
//There are no longer two consecutive balloons of the same color. Total time = 3.
//Example 2:
//Input: colors = "abc", neededTime = [1,2,3]
//Output: 0
//Explanation: The rope is already colorful. Bob does not need to remove any balloons from the rope.
//Example 3:
//Input: colors = "aabaa", neededTime = [1,2,3,4,1]
//Output: 2
//Explanation: Bob will remove the balloons at indices 0 and 4. Each balloons takes 1 second to remove.
//There are no longer two consecutive balloons of the same color. Total time = 1 + 1 = 2.
// 
//Constraints:
//	n == colors.length == neededTime.length
//	1 <= n <= 105
//	1 <= neededTime[i] <= 104
//	colors contains only lowercase English letters.
int minCost(char* colors, int* neededTime, int neededTimeSize) {
    int i, j, k, n = strlen(colors);
    int dp[26][2];
    memset(dp, 0, sizeof(dp));
    for (i = 0; i < n; i++) {
        j = colors[i] - 'a';
        int dp2[26][2];
        memset(dp2, 0, sizeof(dp2));
        for (k = 0; k < 26; k++) {
            if (dp[k][0] > 0) {
                if (k != j) {
                    dp2[j][1] = fmax(dp2[j][1], dp[k][0] + neededTime[i]);
                } else {
                    dp2[j][0] = fmax(dp2[j][0], dp[k][0]);
                    dp2[j][1] = fmax(dp2[j][1], dp[k][1] + neededTime[i]);
                }
            }
            if (dp[k][1] > 0) {
                if (k != j) {
                    dp2[j][1] = fmax(dp2[j][1], dp[k][1] + neededTime[i]);
                } else {
                    dp2[j][1] = fmax(dp2[j][1], dp[k][1] + neededTime[i]);
                }
            }
        }
        memcpy(dp, dp2, sizeof(dp));
    }
    int ans = 0;
    for (i = 0; i < 26; i++) {
        ans = fmax(ans, dp[i][0]);
        ans = fmax(ans, dp[i][1]);
    }
    return ans;    
}