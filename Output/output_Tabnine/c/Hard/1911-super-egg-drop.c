/**https://leetcode.com/problems/super-egg-drop/ */
//You are given k identical eggs and you have access to a building with n floors labeled from 1 to n.
//You know that there exists a floor f where 0 <= f <= n such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break.
//Each move, you may take an unbroken egg and drop it from any floor x (where 1 <= x <= n). If the egg breaks, you can no longer use it. However, if the egg does not break, you may reuse it in future moves.
//Return the minimum number of moves that you need to determine with certainty what the value of f is.
// 
//Example 1:
//Input: k = 1, n = 2
//Output: 2
//Explanation: 
//Drop the egg from floor 1. If it breaks, we know that f = 0.
//Otherwise, drop the egg from floor 2. If it breaks, we know that f = 1.
//If it does not break, then we know f = 2.
//Hence, we need at minimum 2 moves to determine with certainty what the value of f is.
//Example 2:
//Input: k = 2, n = 6
//Output: 3
//Example 3:
//Input: k = 3, n = 14
//Output: 4
// 
//Constraints:
//	1 <= k <= 100
//	1 <= n <= 104
int superEggDrop(int k, int n) {
    // Dynamic Programming
    // dp[i][j] represents the minimum number of moves needed to determine with certainty the floor f that an egg dropped from floor i to floor j will break.
    // Initially, dp[i][0] = 0 for all i, as there is no floor to break from when an egg is dropped from the first floor.
    // dp[0][j] = j for all j, as it takes j moves to drop an egg from the first floor to the jth floor.
    int[][] dp = new int[k + 1][n + 1];
    for (int i = 1; i <= k; i++) {
        dp[i][0] = 0;
        dp[i][1] = 1;
    }
    for (int j = 1; j <= n; j++) {
        dp[1][j] = j;
    }
    
    // Build up the dp table using binary search
    for (int i = 2; i <= k; i++) {
        for (int j = 2; j <= n; j++) {
            int lo = 1, hi = j;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                int breakFloor = dp[i - 1][mid - 1];
                int notBreakFloor = dp[i][j - mid];
                if (breakFloor == notBreakFloor) {
                    // The floor that breaks is the mid point
                    dp[i][j] = mid;
                    break;
                } else if (breakFloor < notBreakFloor) {
                    // The floor that breaks is on the right side
                    lo = mid + 1;
                } else {
                    // The floor that breaks is on the left side
                    hi = mid - 1;
                }
            }
        }
    }
    
    // Return the minimum number of moves needed to determine with certainty the floor f
    return dp[k][n];
    
}