/**https://leetcode.com/problems/sum-of-subarray-minimums/ */
//Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.
// 
//Example 1:
//Input: arr = [3,1,2,4]
//Output: 17
//Explanation: 
//Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
//Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
//Sum is 17.
//Example 2:
//Input: arr = [11,81,94,43,3]
//Output: 444
// 
//Constraints:
//	1 <= arr.length <= 3 * 104
//	1 <= arr[i] <= 3 * 104
/**
 * @param {number[]} arr
 * @return {number}
 */
var sumSubarrayMins = function(arr) {
    let n = arr.length;
    let stack = [];
    let dp = new Array(n).fill(0);
    let sum = 0;
    for (let i = 0; i < n; i++) {
        while (stack.length > 0 && arr[stack[stack.length - 1]] >= arr[i]) {
            stack.pop();
        }
        if (stack.length > 0) {
            let j = stack[stack.length - 1];
            dp[i] = dp[j] + (i - j) * arr[i];
        } else {
            dp[i] = (i + 1) * arr[i];
        }
        stack.push(i);
        sum = (sum + dp[i]) % 1000000007;
    }
    return sum;
};