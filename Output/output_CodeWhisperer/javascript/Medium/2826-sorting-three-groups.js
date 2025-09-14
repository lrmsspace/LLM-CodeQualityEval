/*
 You are given an integer array nums. Each element in nums is 1, 2 or 3. In each operation, you can remove an element from nums. Return the minimum number of operations to make nums non-decreasing.
 Example 1:
 Input: nums = [2,1,3,2,1]
 Output: 3
 Explanation:
 One of the optimal solutions is to remove nums[0], nums[2] and nums[3].
 Example 2:
 Input: nums = [1,3,2,1,3,3]
 Output: 2
 Explanation:
 One of the optimal solutions is to remove nums[1] and nums[2].
 Example 3:
 Input: nums = [2,2,2,2,3,3]
 Output: 0
 Explanation:
 nums is already non-decreasing.
 Constraints:
 1 <= nums.length <= 100
 1 <= nums[i] <= 3
 Follow-up: Can you come up with an algorithm that runs in O(n) time complexity?
*/

/**
 * @param {number[]} nums
 * @return {number}
 */
var minimumOperations = function(nums) {
    const n = nums.length;
    const dp = new Array(n + 1).fill(0).map(() => new Array(4).fill(0));
    
    for (let i = 1; i <= n; i++) {
        for (let j = 1; j <= 3; j++) {
            dp[i][j] = dp[i - 1][j];
            if (nums[i - 1] === j) {
                dp[i][j] = Math.max(dp[i][j], dp[i - 1][j - 1] + 1);
            } else if (nums[i - 1] < j) {
                dp[i][j] = Math.max(dp[i][j], dp[i - 1][nums[i - 1]] + 1);
            }
        }
    }
    
    return n - Math.max(...dp[n]);


};