/*
 You are given two arrays, nums and target.
 In a single operation, you may increment any element of nums by 1.
 Return the minimum number of operations required so that each element in target has at least one multiple in nums.
 Example 1:
 Input: nums = [1,2,3], target = [4]
 Output: 1
 Explanation:
 The minimum number of operations required to satisfy the condition is 1.
 Increment 3 to 4 with just one operation, making 4 a multiple of itself.
 Example 2:
 Input: nums = [8,4], target = [10,5]
 Output: 2
 Explanation:
 The minimum number of operations required to satisfy the condition is 2.
 Increment 8 to 10 with 2 operations, making 10 a multiple of both 5 and 10.
 Example 3:
 Input: nums = [7,9,10], target = [7]
 Output: 0
 Explanation:
 Target 7 already has a multiple in nums, so no additional operations are needed.
 Constraints:
 1 <= nums.length <= 5 * 104
 1 <= target.length <= 4
 target.length <= nums.length
 1 <= nums[i], target[i] <= 104
*/

/**
 * @param {number[]} nums
 * @param {number[]} target
 * @return {number}
 */
var minimumIncrements = function(nums, target) {
    const n = nums.length;
    const targetMap = new Map();
    let minOperations = 0;
    
    // Count the frequency of each target element
    for (const num of target) {
        targetMap.set(num, (targetMap.get(num) || 0) + 1);
    }
    // Count the frequency of each num element
    for (let i = 0; i < n; i++) {
        const num = nums[i];
        // If the num element is not a multiple of the target element, increment it by 1
        if (num % target[i]!== 0) {
            minOperations++;
            // Update the target frequency by subtracting 1
            targetMap.set(target[i], targetMap.get(target[i]) - 1);
            // If the target frequency becomes 0, remove it from the map
            if (targetMap.get(target[i]) === 0) {
                targetMap.delete(target[i]);
            }
        }
    }
    
    return minOperations;
    
};