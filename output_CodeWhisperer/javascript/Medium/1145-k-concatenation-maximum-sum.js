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
    let mod = 1000000007;
    let sum = 0;
    let max = 0;
    for (let i = 0; i < arr.length; i++) {
        sum += arr[i];
        max = Math.max(max, sum);
        if (sum < 0) {
            sum = 0;
        }
    }
    let max1 = max;
    sum = 0;
    for (let i = arr.length - 1; i >= 0; i--) {
        sum += arr[i];
        max1 = Math.max(max1, sum);
        if (sum < 0) {
            sum = 0;
        }
    }
    let max2 = max1 + max;
    if (k == 1) {
        return max1 % mod;
    }
    sum = 0;
    for (let i = 0; i < arr.length; i++) {
        sum += arr[i];
        if (sum < 0) {
            sum = 0;
        }
        max2 = Math.max(max2, sum);
        if (sum < 0) {
            sum = 0;
        }
    }
    if (sum > 0) {
        max2 += (k - 2) * sum;
    }
    return max2 % mod;
};