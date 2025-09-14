/*
 You are given a 0-indexed array nums consisting of positive integers.
 A partition of an array into one or more contiguous subarrays is called good if no two subarrays contain the same number.
 Return the total number of good partitions of nums.
 Since the answer may be large, return it modulo 109 + 7.
 Example 1:
 Input: nums = [1,2,3,4]
 Output: 8
 Explanation: The 8 possible good partitions are: ([1], [2], [3], [4]), ([1], [2], [3,4]), ([1], [2,3], [4]), ([1], [2,3,4]), ([1,2], [3], [4]), ([1,2], [3,4]), ([1,2,3], [4]), and ([1,2,3,4]).
 Example 2:
 Input: nums = [1,1,1,1]
 Output: 1
 Explanation: The only possible good partition is: ([1,1,1,1]).
 Example 3:
 Input: nums = [1,2,1,3]
 Output: 2
 Explanation: The 2 possible good partitions are: ([1,2,1], [3]) and ([1,2,1,3]).
 Constraints:
 1 <= nums.length <= 105
 1 <= nums[i] <= 109
*/

/**
 * @param {number[]} nums
 * @return {number}
 */
var numberOfGoodPartitions = function(nums) {
    const MOD = 1e9 + 7;
    const n = nums.length;
    const count = Array(n + 1).fill(0);
    
    for (let i = 0; i < n; i++) {
        count[nums[i]]++;
    }
    
    let ans = 0;
    let maxCount = 0;
    
    for (let i = 1; i <= n; i++) {
        maxCount = Math.max(maxCount, count[i]);
        
        if (maxCount === i) {
            ans = (ans + count[i] * (count[i] - 1)) % MOD;
        }
    }
    
    return ans;
    
};