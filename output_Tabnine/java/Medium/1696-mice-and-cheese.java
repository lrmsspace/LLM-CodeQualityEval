/**https://leetcode.com/problems/mice-and-cheese/ */
//There are two mice and n different types of cheese, each type of cheese should be eaten by exactly one mouse.
//A point of the cheese with index i (0-indexed) is:
//	reward1[i] if the first mouse eats it.
//	reward2[i] if the second mouse eats it.
//You are given a positive integer array reward1, a positive integer array reward2, and a non-negative integer k.
//Return the maximum points the mice can achieve if the first mouse eats exactly k types of cheese.
// 
//Example 1:
//Input: reward1 = [1,1,3,4], reward2 = [4,4,1,1], k = 2
//Output: 15
//Explanation: In this example, the first mouse eats the 2nd (0-indexed) and the 3rd types of cheese, and the second mouse eats the 0th and the 1st types of cheese.
//The total points are 4 + 4 + 3 + 4 = 15.
//It can be proven that 15 is the maximum total points that the mice can achieve.
//Example 2:
//Input: reward1 = [1,1], reward2 = [1,1], k = 2
//Output: 2
//Explanation: In this example, the first mouse eats the 0th (0-indexed) and 1st types of cheese, and the second mouse does not eat any cheese.
//The total points are 1 + 1 = 2.
//It can be proven that 2 is the maximum total points that the mice can achieve.
// 
//Constraints:
//	1 <= n == reward1.length == reward2.length <= 105
//	1 <= reward1[i], reward2[i] <= 1000
//	0 <= k <= n
class Solution {
    public int miceAndCheese(int[] reward1, int[] reward2, int k) {
        int n = reward1.length;
        int[][] dp = new int[n][k+1];
        int[][] dp2 = new int[n][k+1];
        
        for (int i = 0; i < n; i++) {
            Arrays.fill(dp[i], Integer.MIN_VALUE);
            Arrays.fill(dp2[i], Integer.MIN_VALUE);
        }
        
        dp[0][0] = reward1[0];
        dp2[0][0] = reward2[0];
        
        for (int i = 1; i < k; i++) {
            for (int j = 0; j < i; j++) {
                dp[j][i] = Math.max(dp[j][i], dp[j+1][i-1] + reward1[j]);
                dp2[j][i] = Math.max(dp2[j][i], dp2[j+1][i-1] + reward2[j]);
            }
        }
        
        for (int i = k; i < n; i++) {
            dp[i][k] = Math.max(dp[i][k], dp[i-1][k-1] + reward1[i]);
            dp2[i][k] = Math.max(dp2[i][k], dp2[i-1][k-1] + reward2[i]);
        }
        
        int max1 = Arrays.stream(dp[n-1]).max().getAsInt();
        int max2 = Arrays.stream(dp2[n-1]).max().getAsInt();
        return Math.max(max1, max2);
        
    }
}