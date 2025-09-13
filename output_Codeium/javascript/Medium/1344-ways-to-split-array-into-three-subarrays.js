/**https://leetcode.com/problems/ways-to-split-array-into-three-subarrays/ */
//A split of an integer array is good if:
//	The array is split into three non-empty contiguous subarrays - named left, mid, right respectively from left to right.
//	The sum of the elements in left is less than or equal to the sum of the elements in mid, and the sum of the elements in mid is less than or equal to the sum of the elements in right.
//Given nums, an array of non-negative integers, return the number of good ways to split nums. As the number may be too large, return it modulo 109 + 7.
// 
//Example 1:
//Input: nums = [1,1,1]
//Output: 1
//Explanation: The only good way to split nums is [1] [1] [1].
//Example 2:
//Input: nums = [1,2,2,2,5,0]
//Output: 3
//Explanation: There are three good ways of splitting nums:
//[1] [2] [2,2,5,0]
//[1] [2,2] [2,5,0]
//[1,2] [2,2] [5,0]
//Example 3:
//Input: nums = [3,2,1]
//Output: 0
//Explanation: There is no good way to split nums.
// 
//Constraints:
//	3 <= nums.length <= 105
//	0 <= nums[i] <= 104
/**
 * @param {number[]} nums
 * @return {number}
 */
var waysToSplit = function(nums) {
    const MOD = 1e9 + 7;
    const n = nums.length;
    const sum = nums.reduce((a, b) => a + b, 0);
    const preSum = new Array(n).fill(0);
    preSum[0] = nums[0];
    for (let i = 1; i < n; ++i) {
        preSum[i] = preSum[i - 1] + nums[i];
    }
    let res = 0;
    for (let i = 1; i < n - 1; ++i) {
        for (let j = i + 1; j < n; ++j) {
            const leftSum = preSum[i - 1];
            const midSum = preSum[j - 1] - leftSum;
            const rightSum = sum - midSum - leftSum;
            if (leftSum <= midSum && midSum <= rightSum) {
                res = (res + 1) % MOD;
            }
        }
    }

    return res;
};