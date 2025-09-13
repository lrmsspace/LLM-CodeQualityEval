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
    let sum = nums.reduce((a, b) => a + b, 0);
    if (sum % k !== 0) return false;
    let target = sum / k;
    let visited = new Array(nums.length).fill(false);
    return dfs(0, 0, target, visited, nums, k);
};

function dfs(start, curSum, target, visited, nums, k) {
    if (k === 0) return true;
    if (curSum === target) return dfs(0, 0, target, visited, nums, k - 1);
    for (let i = start; i < nums.length; i++){
        if (visited[i] || curSum + nums[i] > target) continue;
        visited[i] = true;
        if (dfs(i + 1, curSum + nums[i], target, visited, nums, k)) return true;
        visited[i] = false;
    }
};