/**https://leetcode.com/problems/next-greater-element-iii/ */
//Given a positive integer n, find the smallest integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive integer exists, return -1.
//Note that the returned integer should fit in 32-bit integer, if there is a valid answer but it does not fit in 32-bit integer, return -1.
// 
//Example 1:
//Input: n = 12
//Output: 21
//Example 2:
//Input: n = 21
//Output: -1
// 
//Constraints:
//	1 <= n <= 231 - 1
/**
 * @param {number} n
 * @return {number}
 */
var nextGreaterElement = function(n) {
    let arr = n.toString().split('').map(Number);
    let len = arr.length;
    let i = len - 2;

    while (i >= 0 && arr[i] >= arr[i + 1]) {
        i--;
    }

    if (i < 0) return -1;

    let j = len - 1;
    while (arr[j] <= arr[i]) {
        j--;
    }

    [arr[i], arr[j]] = [arr[j], arr[i]];
    let result = parseInt(arr.slice(0, i + 1).concat(arr.slice(i + 1).reverse()).join(''));

    return result > Math.pow(2, 31) - 1 ? -1 : result;    
};