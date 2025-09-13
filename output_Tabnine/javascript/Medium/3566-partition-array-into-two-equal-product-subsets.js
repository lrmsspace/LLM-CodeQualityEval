/*
 You are given an integer array nums containing distinct positive integers and an integer target.
 Determine if you can partition nums into two non-empty disjoint subsets, with each element belonging to exactly one subset, such that the product of the elements in each subset is equal to target.
 Return true if such a partition exists and false otherwise.
 A subset of an array is a selection of elements of the array.
 Example 1:
 Input: nums = [3,1,6,8,4], target = 24
 Output: true
 Explanation: The subsets [3, 8] and [1, 6, 4] each have a product of 24. Hence, the output is true.
 Example 2:
 Input: nums = [2,5,3,7], target = 15
 Output: false
 Explanation: There is no way to partition nums into two non-empty disjoint subsets such that both subsets have a product of 15. Hence, the output is false.
 Constraints:
 3 <= nums.length <= 12
 1 <= target <= 1015
 1 <= nums[i] <= 100
 All elements of nums are distinct.
*/

/**
 * @param {number[]} nums
 * @param {number} target
 * @return {boolean}
 */
var checkEqualPartitions = function(nums, target) {
    // Calculate the sum of all elements in nums
    let sum = nums.reduce((acc, val) => acc + val, 0);
    
    // Check if the sum is divisible by target
    if (sum % target!== 0) {
        return false;
    }
    
    // Calculate the required sum for each subset
    let requiredSum = sum / target;
    
    // Initialize a 2D dp array with dimensions (target + 1) x (nums.length + 1)
    let dp = Array.from({ length: target + 1 }, () => Array(nums.length + 1).fill(false));
    
    // Initialize the first row and column of the dp array
    for (let i = 0; i <= target; i++) {
        dp[i][0] = true;
    }
    for (let j = 0; j <= nums.length; j++) {
        dp[0][j] = false;
    }
    // Fill the dp array
    for (let i = 1; i <= target; i++) {
        for (let j = 1; j <= nums.length; j++) {
            if (nums[j - 1] <= i) {
                dp[i][j] = dp[i][j - 1] || dp[i - nums[j - 1]][j - 1];
            } else {
                dp[i][j] = dp[i][j - 1];
            }
        }
    }
    
    // Check if there is a subset with a product equal to requiredSum
    return dp[requiredSum][nums.length];
    
};