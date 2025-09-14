/**https://leetcode.com/problems/allocate-mailboxes/ */
//Given the array houses where houses[i] is the location of the ith house along a street and an integer k, allocate k mailboxes in the street.
//Return the minimum total distance between each house and its nearest mailbox.
//The test cases are generated so that the answer fits in a 32-bit integer.
// 
//Example 1:
//Input: houses = [1,4,8,10,20], k = 3
//Output: 5
//Explanation: Allocate mailboxes in position 3, 9 and 20.
//Minimum total distance from each houses to nearest mailboxes is |3-1| + |4-3| + |9-8| + |10-9| + |20-20| = 5 
//Example 2:
//Input: houses = [2,3,5,12,18], k = 2
//Output: 9
//Explanation: Allocate mailboxes in position 3 and 14.
//Minimum total distance from each houses to nearest mailboxes is |2-3| + |3-3| + |5-3| + |12-14| + |18-14| = 9.
// 
//Constraints:
//	1 <= k <= houses.length <= 100
//	1 <= houses[i] <= 104
//	All the integers of houses are unique.
/**
 * @param {number[]} houses
 * @param {number} k
 * @return {number}
 */
var minDistance = function(houses, k) {
    const n = houses.length;
    const dp = Array(n).fill(0).map(() => Array(k + 1).fill(0));
    
    // Initialize dp[i][j] as infinity for all i, j
    for (let i = 0; i < n; i++) {
        for (let j = 1; j <= k; j++) {
            dp[i][j] = Infinity;
        }
    }
    
    // Initialize dp[i][1] as the distance from house i to mailbox i
    for (let i = 0; i < n; i++) {
        dp[i][1] = Math.abs(houses[i] - i);
    }
    
    // Fill the dp table
    for (let i = 2; i <= n; i++) {
        for (let j = 1; j <= Math.min(i, k); j++) {
            for (let m = 1; m <= i - 1; m++) {
                dp[i][j] = Math.min(dp[i][j], dp[m - 1][j - 1] + Math.max(houses[m] - houses[0], houses[i - 1] - houses[m]));
            }
        }
    }
    
    return dp[n - 1][k];
    
};