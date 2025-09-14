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
    var n = arr.length;
    var left = new Array(n).fill(-1);
    var right = new Array(n).fill(n);
    var stack = [];
    for(var i = 0; i < n; i++){
        while(stack.length && arr[stack[stack.length - 1]] >= arr[i]){
            right[stack.pop()] = i;
        }
        stack.push(i);
    }
    while(stack.length){
        left[stack.pop()] = -1;
    }
    var ans = 0;
    for(var i = 0; i < n; i++){
        ans += (right[i] - i) * (i - left[i]) * arr[i];
    }
    return ans % 1000000007;
};