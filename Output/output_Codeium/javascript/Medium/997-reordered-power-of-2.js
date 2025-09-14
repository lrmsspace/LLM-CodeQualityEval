/**https://leetcode.com/problems/reordered-power-of-2/ */
//You are given an integer n. We reorder the digits in any order (including the original order) such that the leading digit is not zero.
//Return true if and only if we can do this so that the resulting number is a power of two.
// 
//Example 1:
//Input: n = 1
//Output: true
//Example 2:
//Input: n = 10
//Output: false
// 
//Constraints:
//	1 <= n <= 109
/**
 * @param {number} n
 * @return {boolean}
 */
var reorderedPowerOf2 = function(n) {
    let nums = n.toString().split('').sort((a, b) => a - b);
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] !== '0') {
            let num = parseInt(nums.slice(i).join(''));
            if (num !== 0 && (num & (num - 1)) === 0) return true;
        }
    }
    return false;
};