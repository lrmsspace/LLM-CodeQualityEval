/**https://leetcode.com/problems/sum-of-subsequence-widths/ */
//The width of a sequence is the difference between the maximum and minimum elements in the sequence.
//Given an array of integers nums, return the sum of the widths of all the non-empty subsequences of nums. Since the answer may be very large, return it modulo 109 + 7.
//A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].
// 
//Example 1:
//Input: nums = [2,1,3]
//Output: 6
//Explanation: The subsequences are [1], [2], [3], [2,1], [2,3], [1,3], [2,1,3].
//The corresponding widths are 0, 0, 0, 1, 1, 2, 2.
//The sum of these widths is 6.
//Example 2:
//Input: nums = [2]
//Output: 0
// 
//Constraints:
//	1 <= nums.length <= 105
//	1 <= nums[i] <= 105
/**
 * @param {number[]} nums
 * @return {number}
 */
var sumSubseqWidths = function(nums) {
    const MOD = 1e9 + 7;
    let res = 0, n = nums.length;
    nums.sort((a, b) => a - b);
    for (let i = 0; i < n; i++) {
        let left = (1 << i) - 1, right = (1 << (n - i - 1)) - 1;
        res = (res + (nums[i] - nums[n - i - 1]) * left * right % MOD) % MOD;
    }
    return res;
    
};