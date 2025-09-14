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
    const n = nums.length;
    if (n === 0) return 0;
    
    const sums = new Array(n + 1).fill(0);
    for (let i = 0; i < n; i++) {
        sums[i + 1] = sums[i] + nums[i];
    }
    
    const count = new Array(n + 1).fill(0);
    let ans = 0;
    
    for (let i = 1; i <= n; i++) {
        for (let j = 0; j < i; j++) {
            const sum = sums[i] - sums[j];
            if (lower <= sum && sum <= upper) ans += count[i - j];
            if (sum < lower) count[i] = count[i] + 1;
        }
    }
    
    return ans;
    
};