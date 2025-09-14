/**https://leetcode.com/problems/count-number-of-ways-to-place-houses/ */
//There is a street with n * 2 plots, where there are n plots on each side of the street. The plots on each side are numbered from 1 to n. On each plot, a house can be placed.
//Return the number of ways houses can be placed such that no two houses are adjacent to each other on the same side of the street. Since the answer may be very large, return it modulo 109 + 7.
//Note that if a house is placed on the ith plot on one side of the street, a house can also be placed on the ith plot on the other side of the street.
// 
//Example 1:
//Input: n = 1
//Output: 4
//Explanation: 
//Possible arrangements:
//1. All plots are empty.
//2. A house is placed on one side of the street.
//3. A house is placed on the other side of the street.
//4. Two houses are placed, one on each side of the street.
//Example 2:
//Input: n = 2
//Output: 9
//Explanation: The 9 possible arrangements are shown in the diagram above.
// 
//Constraints:
//	1 <= n <= 104
class Solution {
    public int countHousePlacements(int n) {
        int MOD = (int) 1e9 + 7;
        int[][] dp = new int[n][2];
        dp[0][0] = 1; // Place a house on the left side
        dp[0][1] = 1; // Place a house on the right side
        
        for (int i = 1; i < n; i++) {
            dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MOD; // Place a house on the left side
            dp[i][1] = dp[i][0]; // Place a house on the right side
        }
        
        return (dp[n - 1][0] + dp[n - 1][1]) % MOD; // Return the number of ways to place houses modulo 10^9 + 7
        
    }
}