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
/**
 * @param {number[][]} envelopes
 * @return {number}
 */
var maxEnvelopes = function(envelopes) {
    // Sort the envelopes by width in descending order and height in ascending order
    envelopes.sort((a, b) => b[0] - a[0] || a[1] - b[1]);
    
    // Initialize a dp array to store the maximum number of envelopes that can be Russian doll up to each envelope
    const dp = new Array(envelopes.length).fill(1);
    
    // Iterate through the sorted envelopes
    for (let i = 1; i < envelopes.length; i++) {
        // Iterate through the previous envelopes
        for (let j = 0; j < i; j++) {
            // If the current envelope can be Russian doll, update the dp array
            if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1]) {
                dp[i] = Math.max(dp[i], dp[j] + 1);
            }
        }
    }
    
    // Return the maximum number of envelopes that can be Russian doll
    return Math.max(...dp);
    
};