/*
 You are given an integer array nums and a positive integer k.
 The value of a sequence seq of size 2 * x is defined as:
 (seq[0] OR seq[1] OR ... OR seq[x - 1]) XOR (seq[x] OR seq[x + 1] OR ... OR seq[2 * x - 1]).
 Return the maximum value of any subsequence of nums having size 2 * k.
 Example 1:
 Input: nums = [2,6,7], k = 1
 Output: 5
 Explanation:
 The subsequence [2, 7] has the maximum value of 2 XOR 7 = 5.
 Example 2:
 Input: nums = [4,2,5,6,7], k = 2
 Output: 2
 Explanation:
 The subsequence [4, 5, 6, 7] has the maximum value of (4 OR 5) XOR (6 OR 7) = 2.
 Constraints:
 2 <= nums.length <= 400
 1 <= nums[i] < 27
 1 <= k <= nums.length / 2
*/

/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var maxValue = function(nums, k) {
    const n = nums.length;
    let maxVal = 0;

    for (let i = 0; i < n; i++) {
        for (let j = i + 1; j < n; j++) {
            const left = nums.slice(i, j + 1);
            const right = nums.slice(j + 1, j + 1 + k);
            const currentVal = (left.reduce((a, b) => a | b, 0) ^ right.reduce((a, b) => a | b, 0));
            maxVal = Math.max(maxVal, currentVal);
        }
    }
    return maxVal;
};