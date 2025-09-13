/**https://leetcode.com/problems/partition-to-k-equal-sum-subsets/ */
//Given an integer array nums and an integer k, return true if it is possible to divide this array into k non-empty subsets whose sums are all equal.
// 
//Example 1:
//Input: nums = [4,3,2,3,5,2,1], k = 4
//Output: true
//Explanation: It is possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
//Example 2:
//Input: nums = [1,2,3,4], k = 3
//Output: false
// 
//Constraints:
//	1 <= k <= nums.length <= 16
//	1 <= nums[i] <= 104
//	The frequency of each element is in the range [1, 4].
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */
var canPartitionKSubsets = function(nums, k) {
    let sum = 0;
    for (let num of nums) {
        sum += num;
    }
    if (sum % k != 0) {
        return false;
    }
    let target = sum / k;
    let used = new Array(nums.length).fill(false);
    let backtrack = function(k, subsetSum) {
        if (k == 0) {
            return true;
        }
        if (subsetSum == target) {
            return backtrack(k - 1, 0);
        }
        for (let i = 0; i < nums.length; i++) {
            if (used[i] || subsetSum + nums[i] > target) {
                continue;
            }
            used[i] = true;
            if (backtrack(k, subsetSum + nums[i])) {
                return true;
            }
            used[i] = false;
        }
        return false;
    }
    return backtrack(k, 0);
};