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
    const MOD = 1e9 + 7;
    const n = nums.length;
    let count = 0;

    // Create a map to count occurrences of each number
    const numCount = new Map();
    for (const num of nums) {
        numCount.set(num, (numCount.get(num) || 0) + 1);
    }

    // Iterate through the array to find special triplets
    for (let j = 1; j < n - 1; j++) {
        const midValue = nums[j];
        const leftValue = midValue * 2;
        const rightValue = midValue * 2;

        if (numCount.has(leftValue) && numCount.has(rightValue)) {
            const leftCount = numCount.get(leftValue);
            const rightCount = numCount.get(rightValue);

            // Exclude the current middle element from the counts
            if (leftValue === midValue) leftCount--;
            if (rightValue === midValue) rightCount--;

            count = (count + leftCount * rightCount) % MOD;
        }
    }

    return count;   
        
};