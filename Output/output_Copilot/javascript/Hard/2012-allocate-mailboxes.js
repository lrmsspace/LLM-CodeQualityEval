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
    houses.sort((a, b) => a - b);
    const n = houses.length;
    const dp = Array.from({ length: n + 1 }, () => Array(k + 1).fill(Infinity));
    for (let i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (let i = 1; i <= n; i++) {
        for (let j = 1; j <= k; j++) {
            for (let p = 0; p < i; p++) {
                const dist = getDistance(houses, p, i - 1);
                dp[i][j] = Math.min(dp[i][j], dp[p][j - 1] + dist);
            }
        }
    }
    return dp[n][k];    
};