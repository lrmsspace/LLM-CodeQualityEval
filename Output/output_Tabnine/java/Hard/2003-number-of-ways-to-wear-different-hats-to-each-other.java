/**https://leetcode.com/problems/number-of-ways-to-wear-different-hats-to-each-other/ */
//There are n people and 40 types of hats labeled from 1 to 40.
//Given a 2D integer array hats, where hats[i] is a list of all hats preferred by the ith person.
//Return the number of ways that the n people wear different hats to each other.
//Since the answer may be too large, return it modulo 109 + 7.
// 
//Example 1:
//Input: hats = [[3,4],[4,5],[5]]
//Output: 1
//Explanation: There is only one way to choose hats given the conditions. 
//First person choose hat 3, Second person choose hat 4 and last one hat 5.
//Example 2:
//Input: hats = [[3,5,1],[3,5]]
//Output: 4
//Explanation: There are 4 ways to choose hats:
//(3,5), (5,3), (1,3) and (1,5)
//Example 3:
//Input: hats = [[1,2,3,4],[1,2,3,4],[1,2,3,4],[1,2,3,4]]
//Output: 24
//Explanation: Each person can choose hats labeled from 1 to 4.
//Number of Permutations of (1,2,3,4) = 24.
// 
//Constraints:
//	n == hats.length
//	1 <= n <= 10
//	1 <= hats[i].length <= 40
//	1 <= hats[i][j] <= 40
//	hats[i] contains a list of unique integers.
class Solution {
    public int numberWays(List<List<Integer>> hats) {
        int n = hats.size();
        int MOD = 1000000007;
        
        // Initialize dp array with size (n+1) * (1<<40)
        int[][] dp = new int[n + 1][1 << 40];
        Arrays.fill(dp[0], 1);
        
        // Initialize hatCount array with size 41
        int[] hatCount = new int[41];
        
        // Count the number of people for each hat
        for (int i = 0; i < n; i++) {
            for (int hat : hats.get(i)) {
                hatCount[hat]++;
            }
        }
        
        // Iterate through each person and each hat
        for (int i = 1; i <= n; i++) {
            int[] newDP = new int[1 << 40];
            
            // Iterate through each hat
            for (int hat = 1; hat <= 40; hat++) {
                // If the hat is available for the current person
                if ((hatCount[hat] > 0) && ((1 << hat) & (1 << (i - 1)))) {
                    // Iterate through all previous people and their hats
                    for (int prevHat = 1; prevHat <= 40; prevHat++) {
                        // If the previous person has the hat
                        if ((hatCount[prevHat] > 0) && ((1 << prevHat) & (1 << (i - 2)))) {
                            // Add the number of ways to choose the hat to the newDP array
                            newDP[hat | prevHat] = (newDP[hat | prevHat] + dp[i - 2][prevHat]) % MOD;
                        }
                    }
                }
            }
    
            // Copy the newDP array to the dp array
            dp[i] = Arrays.copyOf(newDP, newDP.length);
        }
        
        // Return the number of ways to choose hats to each other
        return dp[n][0];
        
    }
}