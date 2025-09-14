/**https://leetcode.com/problems/count-the-number-of-fair-pairs/ */
//Given a 0-indexed integer array nums of size n and two integers lower and upper, return the number of fair pairs.
//A pair (i, j) is fair if:
//	0 <= i < j < n, and
//	lower <= nums[i] + nums[j] <= upper
// 
//Example 1:
//Input: nums = [0,1,7,4,4,5], lower = 3, upper = 6
//Output: 6
//Explanation: There are 6 fair pairs: (0,3), (0,4), (0,5), (1,3), (1,4), and (1,5).
//Example 2:
//Input: nums = [1,7,9,2,5], lower = 11, upper = 11
//Output: 1
//Explanation: There is a single fair pair: (2,3).
// 
//Constraints:
//	1 <= nums.length <= 105
//	nums.length == n
//	-109 <= nums[i] <= 109
//	-109 <= lower <= upper <= 109
/**
 * @param {number[]} nums
 * @param {number} lower
 * @param {number} upper
 * @return {number}
 */
var countFairPairs = function(nums, lower, upper) {
    const n = nums.length;
    const count = Array(n).fill(0);
    const mod = 10**9 + 7;
    nums.sort((a, b) => a - b);
    
    let ans = 0;
    for (let i = 0; i < n; i++) {
        let left = lower - nums[i], right = upper - nums[i];
        let l = Math.max(0, Math.floor(left / 2)), r = Math.min(i, Math.floor(right / 2));
        ans = (ans + (r - l + 1) * count[l]) % mod;
        count[i + 1] = (count[i + 1] + count[l]) % mod;
    }
    
    return ans;
    
};