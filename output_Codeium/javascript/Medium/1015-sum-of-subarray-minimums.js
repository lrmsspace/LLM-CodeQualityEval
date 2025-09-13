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
const MOD = 1e9 + 7;
let stack = [];
let prev = new Array(arr.length).fill(-1);
let next = new Array(arr.length).fill(arr.length);

// Calculate previous less element for each element
for (let i = 0; i < arr.length; i++) {
    while (stack.length && arr[stack[stack.length - 1]] >= arr[i]) {
        stack.pop();
    }
    prev[i] = stack.length ? stack[stack.length - 1] : -1;
    stack.push(i);
}

stack = [];

// Calculate next less element for each element
for (let i = arr.length - 1; i >= 0; i--) {
    while (stack.length && arr[stack[stack.length - 1]] > arr[i]) {
        stack.pop();
    }
    next[i] = stack.length ? stack[stack.length - 1] : arr.length;
    stack.push(i);
}

let result = 0;

// Calculate the sum of subarray minimums
for (let i = 0; i < arr.length; i++) {
    result = (result + arr[i] * (i - prev[i]) * (next[i] - i)) % MOD;
}

return result;

};