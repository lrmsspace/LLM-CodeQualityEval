/**https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/ */
//Given an array of integers, return the maximum sum for a non-empty subarray (contiguous elements) with at most one element deletion. In other words, you want to choose a subarray and optionally delete one element from it so that there is still at least one element left and the sum of the remaining elements is maximum possible.
//Note that the subarray needs to be non-empty after deleting one element.
// 
//Example 1:
//Input: arr = [1,-2,0,3]
//Output: 4
//Explanation: Because we can choose [1, -2, 0, 3] and drop -2, thus the subarray [1, 0, 3] becomes the maximum value.
//Example 2:
//Input: arr = [1,-2,-2,3]
//Output: 3
//Explanation: We just choose [3] and it's the maximum sum.
//Example 3:
//Input: arr = [-1,-1,-1,-1]
//Output: -1
//Explanation: The final subarray needs to be non-empty. You can't choose [-1] and delete -1 from it, then get an empty subarray to make the sum equals to 0.
// 
//Constraints:
//	1 <= arr.length <= 105
//	-104 <= arr[i] <= 104
/**
 * @param {number[]} arr
 * @return {number}
 */
var maximumSum = function(arr) {
    let n = arr.length;
    if(n === 0) return 0;
    
    let dp = Array(n).fill(0);
    dp[0] = arr[0];
    let maxSum = dp[0];
    
    for(let i = 1; i < n; i++) {
        dp[i] = Math.max(arr[i], dp[i-1] + arr[i]);
        maxSum = Math.max(maxSum, dp[i]);
    }
    
    if(n === 1) return maxSum;
    
    let dp2 = Array(n).fill(0);
    dp2[0] = dp[0];
    let maxSum2 = dp2[0];
    
    for(let i = 1; i < n; i++) {
        dp2[i] = Math.max(dp[i], dp2[i-1] + arr[i]);
        maxSum2 = Math.max(maxSum2, dp2[i]);
    }
    
    return Math.max(maxSum, maxSum2);

    
};