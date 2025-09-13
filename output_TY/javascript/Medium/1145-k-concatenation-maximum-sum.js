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
    let sum = 0, maxSum = 0, maxSumSoFar = 0, maxSumSoFar2 = 0, maxSumSoFar3 = 0;
    for(let i = 0; i < arr.length; i++){
        sum += arr[i];
        maxSumSoFar = Math.max(maxSumSoFar, sum);
    }
    if(k === 1){
        return maxSumSoFar;
    }
    for(let i = 0; i < arr.length; i++){
        maxSumSoFar2 += arr[i];
        maxSumSoFar3 = Math.max(maxSumSoFar3, maxSumSoFar2);
    }
    if(k === 2){
        return maxSumSoFar3;
    }
    return Math.max(maxSumSoFar3, maxSumSoFar + sum * (k - 2));

};