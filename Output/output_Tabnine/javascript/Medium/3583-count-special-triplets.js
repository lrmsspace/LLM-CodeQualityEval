/*
 You are given an integer array nums.
 A special triplet is defined as a triplet of indices (i, j, k) such that:
 0 <= i < j < k < n, where n = nums.length
 nums[i] == nums[j] * 2
 nums[k] == nums[j] * 2
 Return the total number of special triplets in the array.
 Since the answer may be large, return it modulo 109 + 7.
 Example 1:
 Input: nums = [6,3,6]
 Output: 1
 Explanation:
 The only special triplet is (i, j, k) = (0, 1, 2), where:
 nums[0] = 6, nums[1] = 3, nums[2] = 6
 nums[0] = nums[1] * 2 = 3 * 2 = 6
 nums[2] = nums[1] * 2 = 3 * 2 = 6
 Example 2:
 Input: nums = [0,1,0,0]
 Output: 1
 Explanation:
 The only special triplet is (i, j, k) = (0, 2, 3), where:
 nums[0] = 0, nums[2] = 0, nums[3] = 0
 nums[0] = nums[2] * 2 = 0 * 2 = 0
 nums[3] = nums[2] * 2 = 0 * 2 = 0
 Example 3:
 Input: nums = [8,4,2,8,4]
 Output: 2
 Explanation:
 There are exactly two special triplets:
 (i, j, k) = (0, 1, 3)
 nums[0] = 8, nums[1] = 4, nums[3] = 8
 nums[0] = nums[1] * 2 = 4 * 2 = 8
 nums[3] = nums[1] * 2 = 4 * 2 = 8
 (i, j, k) = (1, 2, 4)
 nums[1] = 4, nums[2] = 2, nums[4] = 4
 nums[1] = nums[2] * 2 = 2 * 2 = 4
 nums[4] = nums[2] * 2 = 2 * 2 = 4
 Constraints:
 3 <= n == nums.length <= 105
 0 <= nums[i] <= 105
*/

/**
 * @param {number[]} nums
 * @return {number}
 */
var specialTriplets = function(nums) {
    let n = nums.length;
    let count = 0;
    const MOD = 1e9 + 7;
    
    // Sort the array
    nums.sort((a, b) => a - b);
    // Initialize a map to store the frequency of each number   
    let freq = new Map();
    for (let num of nums) {
        freq.set(num, (freq.get(num) || 0) + 1);
    }
    
    // Iterate through the array
    for (let i = 0; i < n - 2; i++) {
        // Check if the current number is a special triplet
        if (nums[i] === nums[i + 1] * 2) {
            // Check if the next number is a special triplet
            if (nums[i + 1] === nums[i + 2] * 2) {
                // Count the special triplets by multiplying their frequencies
                count += freq.get(nums[i]) * freq.get(nums[i + 1]) * freq.get(nums[i + 2]);
                count %= MOD;
            }
        }
    }
    
    return count;   
    
};