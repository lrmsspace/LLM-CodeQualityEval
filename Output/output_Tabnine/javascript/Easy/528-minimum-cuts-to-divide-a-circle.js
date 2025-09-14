/**https://leetcode.com/problems/minimum-cuts-to-divide-a-circle/ */
//A valid cut in a circle can be:
//	A cut that is represented by a straight line that touches two points on the edge of the circle and passes through its center, or
//	A cut that is represented by a straight line that touches one point on the edge of the circle and its center.
//Some valid and invalid cuts are shown in the figures below.
//Given the integer n, return the minimum number of cuts needed to divide a circle into n equal slices.
// 
//Example 1:
//Input: n = 4
//Output: 2
//Explanation: 
//The above figure shows how cutting the circle twice through the middle divides it into 4 equal slices.
//Example 2:
//Input: n = 3
//Output: 3
//Explanation:
//At least 3 cuts are needed to divide the circle into 3 equal slices. 
//It can be shown that less than 3 cuts cannot result in 3 slices of equal size and shape.
//Also note that the first cut will not divide the circle into distinct parts.
// 
//Constraints:
//	1 <= n <= 100
/**
 * @param {number} n
 * @return {number}
 */
var numberOfCuts = function(n) {
    // Base case: if n is 1, return 0 (no cuts needed)
    if (n === 1) return 0;
    
    // For n greater than 1, we need to find the smallest number of cuts
    // that can divide the circle into n equal slices.
    // We can use dynamic programming to solve this problem.
    // Initialize an array dp with the same length as n+1, where dp[i] represents the minimum number of cuts needed to divide the circle into i slices.
    // Set dp[1] = 0 (no cuts needed for 1 slice).
    // Iterate from 2 to n:
    //     For each value i, find the maximum j such that 2^j <= i and dp[j] + 1 < dp[i].
    //     If such j exists, update dp[i] to dp[j] + 1.
    // Return dp[n] as the minimum number of cuts needed to divide the circle into n equal slices.
    const dp = Array(n+1).fill(Infinity);
    dp[1] = 0;
    
    for (let i = 2; i <= n; i++) {
        for (let j = 1; j <= Math.floor(Math.log2(i)); j++) {
            if (2 ** j <= i && dp[j] + 1 < dp[i]) {
                dp[i] = dp[j] + 1;
                break;
            }
        }
    }
    
    return dp[n];
    
};