/*
 Given an array of integers called nums, you can perform any of the following operation while nums contains at least 2 elements:
 Choose the first two elements of nums and delete them.
 Choose the last two elements of nums and delete them.
 Choose the first and the last elements of nums and delete them.
 The score of the operation is the sum of the deleted elements.
 Your task is to find the maximum number of operations that can be performed, such that all operations have the same score.
 Return the maximum number of operations possible that satisfy the condition mentioned above.
 Example 1:
 Input: nums = [3,2,1,2,3,4]
 Output: 3
 Explanation: We perform the following operations:
 - Delete the first two elements, with score 3 + 2 = 5, nums = [1,2,3,4].
 - Delete the first and the last elements, with score 1 + 4 = 5, nums = [2,3].
 - Delete the first and the last elements, with score 2 + 3 = 5, nums = [].
 We are unable to perform any more operations as nums is empty.
 Example 2:
 Input: nums = [3,2,6,1,4]
 Output: 2
 Explanation: We perform the following operations:
 - Delete the first two elements, with score 3 + 2 = 5, nums = [6,1,4].
 - Delete the last two elements, with score 1 + 4 = 5, nums = [6].
 It can be proven that we can perform at most 2 operations.
 Constraints:
 2 <= nums.length <= 2000
 1 <= nums[i] <= 1000
*/

/**
 * @param {number[]} nums
 * @return {number}
 */
var maxOperations = function(nums) {
    const n = nums.length;
    const memo = new Map();
    
    const dp = (i, j, target) => {
        if (i >= j) return 0;
        const key = `${i}-${j}-${target}`;
        if (memo.has(key)) return memo.get(key);
        let res = 0;
        if (nums[i] + nums[i + 1] == target) {
            res = Math.max(res, 1 + dp(i + 2, j, target));
        }
        if (nums[j] + nums[j - 1] == target) {
            res = Math.max(res, 1 + dp(i, j - 2, target));
        }
        if (nums[i] + nums[j] == target) {
            res = Math.max(res, 1 + dp(i + 1, j - 1, target));
        }
        memo.set(key, res);
        return res;
    };
    
    return Math.max(
        dp(2, n - 1, nums[0] + nums[1]),
        dp(0, n - 3, nums[n - 2] + nums[n - 1]),
        dp(1, n - 2, nums[0] + nums[n - 1])
    ) + 1;
            
};