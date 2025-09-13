/**https://leetcode.com/problems/count-number-of-special-subsequences/ */
//A sequence is special if it consists of a positive number of 0s, followed by a positive number of 1s, then a positive number of 2s.
//	For example, [0,1,2] and [0,0,1,1,1,2] are special.
//	In contrast, [2,1,0], [1], and [0,1,2,0] are not special.
//Given an array nums (consisting of only integers 0, 1, and 2), return the number of different subsequences that are special. Since the answer may be very large, return it modulo 109 + 7.
//A subsequence of an array is a sequence that can be derived from the array by deleting some or no elements without changing the order of the remaining elements. Two subsequences are different if the set of indices chosen are different.
// 
//Example 1:
//Input: nums = [0,1,2,2]
//Output: 3
//Explanation: The special subsequences are bolded [0,1,2,2], [0,1,2,2], and [0,1,2,2].
//Example 2:
//Input: nums = [2,2,0,0]
//Output: 0
//Explanation: There are no special subsequences in [2,2,0,0].
//Example 3:
//Input: nums = [0,1,2,0,1,2]
//Output: 7
//Explanation: The special subsequences are bolded:
//- [0,1,2,0,1,2]
//- [0,1,2,0,1,2]
//- [0,1,2,0,1,2]
//- [0,1,2,0,1,2]
//- [0,1,2,0,1,2]
//- [0,1,2,0,1,2]
//- [0,1,2,0,1,2]
// 
//Constraints:
//	1 <= nums.length <= 105
//	0 <= nums[i] <= 2
/**
 * @param {number[]} nums
 * @return {number}
 */
var countSpecialSubsequences = function(nums) {
    const MOD = 1e9 + 7;
    let a = 0, b = 0, c = 0;
    for (const x of nums) {
        if (x === 0) a = (a * 3 + 1) % MOD;
        else if (x === 1) b = (a * 2 + b * 2) % MOD;
        else c = (b * 2 + c * 2) % MOD;
    }
    return c;

};