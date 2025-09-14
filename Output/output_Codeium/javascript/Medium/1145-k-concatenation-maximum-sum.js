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
    let sum = 0;
    for (let num of arr) {
        sum += num;
    }
    if (k === 1) {
        return Math.max(0, sum);
    }
    let maxSum = -Infinity;
    let currSum = 0;
    for (let i = 0; i < arr.length * k; i++) {
        currSum += arr[i % arr.length];
        maxSum = Math.max(maxSum, currSum);
        if (currSum < 0) {
            currSum = 0;
        }
    }
    return Math.max(sum * (k - 2), maxSum) % (10**9 + 7);
};