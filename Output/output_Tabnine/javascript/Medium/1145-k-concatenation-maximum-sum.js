/**https://leetcode.com/problems/k-concatenation-maximum-sum/ */
//Given an integer array arr and an integer k, modify the array by repeating it k times.
//For example, if arr = [1, 2] and k = 3 then the modified array will be [1, 2, 1, 2, 1, 2].
//Return the maximum sub-array sum in the modified array. Note that the length of the sub-array can be 0 and its sum in that case is 0.
//As the answer can be very large, return the answer modulo 109 + 7.
// 
//Example 1:
//Input: arr = [1,2], k = 3
//Output: 9
//Example 2:
//Input: arr = [1,-2,1], k = 5
//Output: 2
//Example 3:
//Input: arr = [-1,-2], k = 7
//Output: 0
// 
//Constraints:
//	1 <= arr.length <= 105
//	1 <= k <= 105
//	-104 <= arr[i] <= 104
/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number}
 */
var kConcatenationMaxSum = function(arr, k) {
    const MOD = 10 ** 9 + 7;
    
    // Calculate the prefix sum of the array
    const prefixSum = arr.reduce((acc, curr) => acc + curr, 0);
    
    // Calculate the maximum sub-array sum using Kadane's algorithm
    let maxSum = Number.NEGATIVE_INFINITY;
    let currentSum = 0;
    for (let num of arr) {
        currentSum = Math.max(num, currentSum + num);
        maxSum = Math.max(maxSum, currentSum);
    }
    
    // Calculate the maximum sub-array sum after concatenating the array k times
    let maxSumAfterConcat = maxSum * k;
    
    // Calculate the maximum sub-array sum using prefix sum
    let maxSumAfterPrefix = prefixSum * Math.max(0, k - 2);
    
    // Find the maximum sub-array sum by considering the two cases
    return Math.max(maxSumAfterConcat, maxSumAfterPrefix) % MOD;
    
};