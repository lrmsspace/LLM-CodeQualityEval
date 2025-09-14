/**https://leetcode.com/problems/sum-of-floored-pairs/ */
//Given an integer array nums, return the sum of floor(nums[i] / nums[j]) for all pairs of indices 0 <= i, j < nums.length in the array. Since the answer may be too large, return it modulo 109 + 7.
//The floor() function returns the integer part of the division.
// 
//Example 1:
//Input: nums = [2,5,9]
//Output: 10
//Explanation:
//floor(2 / 5) = floor(2 / 9) = floor(5 / 9) = 0
//floor(2 / 2) = floor(5 / 5) = floor(9 / 9) = 1
//floor(5 / 2) = 2
//floor(9 / 2) = 4
//floor(9 / 5) = 1
//We calculate the floor of the division for every pair of indices in the array then sum them up.
//Example 2:
//Input: nums = [7,7,7,7,7,7,7]
//Output: 49
// 
//Constraints:
//	1 <= nums.length <= 105
//	1 <= nums[i] <= 105
/**
 * @param {number[]} nums
 * @return {number}
 */
var sumOfFlooredPairs = function(nums) {
    const max = Math.max(...nums);
    const cnt = new Array(max + 1).fill(0);
    for (const num of nums) {
        cnt[num]++;
    }
    const s = new Array(max + 1).fill(0);
    for (let i = 1; i <= max; i++) {
        s[i] = s[i - 1] + cnt[i];
    }
    let ans = 0;
    for (let i = 1; i <= max; i++) {
        if (cnt[i] === 0) continue;
        for (let j = 1; i * j <= max; j++) {
            const a = i * j - 1, b = Math.min(i * (j + 1) - 1, max);
            ans += cnt[i] * j * (s[b] - s[a]);
        }
    }
    return ans % (10 ** 9 + 7);  
};