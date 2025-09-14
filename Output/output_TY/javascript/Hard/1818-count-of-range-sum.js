/**https://leetcode.com/problems/count-of-range-sum/ */
//Given an integer array nums and two integers lower and upper, return the number of range sums that lie in [lower, upper] inclusive.
//Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j inclusive, where i <= j.
// 
//Example 1:
//Input: nums = [-2,5,-1], lower = -2, upper = 2
//Output: 3
//Explanation: The three ranges are: [0,0], [2,2], and [0,2] and their respective sums are: -2, -1, 2.
//Example 2:
//Input: nums = [0], lower = 0, upper = 0
//Output: 1
// 
//Constraints:
//	1 <= nums.length <= 105
//	-231 <= nums[i] <= 231 - 1
//	-105 <= lower <= upper <= 105
//	The answer is guaranteed to fit in a 32-bit integer.
/**
 * @param {number[]} nums
 * @param {number} lower
 * @param {number} upper
 * @return {number}
 */
var countRangeSum = function(nums, lower, upper) {
    let sum = 0;
    let count = 0;
    let map = new Map();
    map.set(0, 1);
    for (let i = 0; i < nums.length; i++) {
        sum += nums[i];
        let left = sum - upper;
        let right = sum - lower;
        let leftCount = map.get(left) || 0;
        let rightCount = map.get(right) || 0;
        count += rightCount - leftCount;
        map.set(sum, (map.get(sum) || 0) + 1);
    }
    return count;
};