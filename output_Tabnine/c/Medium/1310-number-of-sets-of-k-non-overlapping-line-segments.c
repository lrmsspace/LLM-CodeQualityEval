/**https://leetcode.com/problems/number-of-sets-of-k-non-overlapping-line-segments/ */
//Given n points on a 1-D plane, where the ith point (from 0 to n-1) is at x = i, find the number of ways we can draw exactly k non-overlapping line segments such that each segment covers two or more points. The endpoints of each segment must have integral coordinates. The k line segments do not have to cover all n points, and they are allowed to share endpoints.
//Return the number of ways we can draw k non-overlapping line segments. Since this number can be huge, return it modulo 109 + 7.
// 
//Example 1:
//Input: n = 4, k = 2
//Output: 5
//Explanation: The two line segments are shown in red and blue.
//The image above shows the 5 different ways {(0,2),(2,3)}, {(0,1),(1,3)}, {(0,1),(2,3)}, {(1,2),(2,3)}, {(0,1),(1,2)}.
//Example 2:
//Input: n = 3, k = 1
//Output: 3
//Explanation: The 3 ways are {(0,1)}, {(0,2)}, {(1,2)}.
//Example 3:
//Input: n = 30, k = 7
//Output: 796297179
//Explanation: The total number of possible ways to draw 7 line segments is 3796297200. Taking this number modulo 109 + 7 gives us 796297179.
// 
//Constraints:
//	2 <= n <= 1000
//	1 <= k <= n-1
int numberOfSets(int n, int k) {
    // Create an array dp of size n+1 to store the number of ways to draw k non-overlapping line segments
    int[] dp = new int[n + 1];
    // Initialize dp[0] and dp[1]
    dp[0] = dp[1] = 1;
    
    // Iterate from 2 to n
    for (int i = 2; i <= n; i++) {
        // Calculate the number of ways to draw k non-overlapping line segments for each possible number of segments
        for (int j = 1; j <= k && j <= i; j++) {
            // Add the number of ways to draw (i-j) non-overlapping line segments to the number of ways to draw j non-overlapping line segments
            dp[i] = (dp[i] + dp[i - j]) % (int) (1e9 + 7);
        }
    }
    
    // Return the number of ways to draw k non-overlapping line segments
    return dp[n];
    
}