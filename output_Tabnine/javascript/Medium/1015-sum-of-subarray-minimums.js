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
    const MOD = 10 ** 9 + 7;
    const n = arr.length;
    const stack = [];
    const left = new Array(n).fill(0);
    const right = new Array(n).fill(0);
    
    for (let i = 0; i < n; i++) {
        while (stack.length && arr[stack[stack.length - 1]] > arr[i]) {
            right[stack.pop()] = i;
        }
        left[i] = stack.length? stack[stack.length - 1] : -1;
        stack.push(i);
    }
    
    let ans = 0;
    for (let i = 0; i < n; i++) {
        ans = (ans + arr[i] * (i - left[i]) * (right[i] - i)) % MOD;
    }
    
    return ans;
    
};