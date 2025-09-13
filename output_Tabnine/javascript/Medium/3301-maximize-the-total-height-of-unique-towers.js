/*
 You are given an array maximumHeight, where maximumHeight[i] denotes the maximum height the ith tower can be assigned.
 Your task is to assign a height to each tower so that:
 The height of the ith tower is a positive integer and does not exceed maximumHeight[i].
 No two towers have the same height.
 Return the maximum possible total sum of the tower heights. If it's not possible to assign heights, return -1.
 Example 1:
 Input: maximumHeight = [2,3,4,3]
 Output: 10
 Explanation:
 We can assign heights in the following way: [1, 2, 4, 3].
 Example 2:
 Input: maximumHeight = [15,10]
 Output: 25
 Explanation:
 We can assign heights in the following way: [15, 10].
 Example 3:
 Input: maximumHeight = [2,2,1]
 Output: -1
 Explanation:
 It's impossible to assign positive heights to each index so that no two towers have the same height.
 Constraints:
 1 <= maximumHeight.length <= 105
 1 <= maximumHeight[i] <= 109
*/

/**
 * @param {number[]} maximumHeight
 * @return {number}
 */
var maximumTotalSum = function(maximumHeight) {
    const n = maximumHeight.length;
    const dp = new Array(n + 1).fill(0);
    
    for (let i = n - 1; i >= 0; i--) {
        dp[i] = Math.max(dp[i + 1], maximumHeight[i]);
    }
    
    let maxSum = 0;
    let sum = 0;
    
    for (let i = 0; i < n; i++) {
        sum += dp[i];
        maxSum = Math.max(maxSum, sum);
    }
    
    return maxSum === sum? maxSum : -1; 
    
};