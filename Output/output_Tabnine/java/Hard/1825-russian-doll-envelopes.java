/**https://leetcode.com/problems/russian-doll-envelopes/ */
//You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.
//One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.
//Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).
//Note: You cannot rotate an envelope.
// 
//Example 1:
//Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
//Output: 3
//Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
//Example 2:
//Input: envelopes = [[1,1],[1,1],[1,1]]
//Output: 1
// 
//Constraints:
//	1 <= envelopes.length <= 105
//	envelopes[i].length == 2
//	1 <= wi, hi <= 105
class Solution {
    public int maxEnvelopes(int[][] envelopes) {
        int n = envelopes.length;
        if (n == 0) return 0;
        
        // Sort the envelopes by width in descending order and height in ascending order
        Arrays.sort(envelopes, (a, b) -> b[0] - a[0] == 0? a[1] - b[1] : b[0] - a[0]);
        
        // Initialize a dynamic programming array dp of size n+1 with all elements set to 1
        int[] dp = new int[n+1];
        Arrays.fill(dp, 1);
        
        // Iterate through the sorted envelopes
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                // If the current envelope can fit into the previous envelope, update dp[i]
                if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1]) {
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                }
            }
        }
        
        // Return the maximum number of envelopes that can be Russian doll
        return Arrays.stream(dp).max().getAsInt();
        
    }
}