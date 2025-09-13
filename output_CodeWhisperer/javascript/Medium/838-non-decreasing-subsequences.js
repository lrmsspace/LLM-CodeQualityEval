/**https://leetcode.com/problems/non-decreasing-subsequences/ */
//Given an integer array nums, return all the different possible non-decreasing subsequences of the given array with at least two elements. You may return the answer in any order.
// 
//Example 1:
//Input: nums = [4,6,7,7]
//Output: [[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
//Example 2:
//Input: nums = [4,4,3,2,1]
//Output: [[4,4]]
// 
//Constraints:
//	1 <= nums.length <= 15
//	-100 <= nums[i] <= 100
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var findSubsequences = function(nums) {
    let ans = [];
    let n = nums.length;
    let dfs = (idx, path) => {
        if (path.length >= 2) {
            ans.push([...path]);
        }
        let used = new Set();
        for (let i = idx; i < n; i++) {
            if (used.has(nums[i])) {
                continue;
            }
            if (path.length == 0 || nums[i] >= path[path.length - 1]) {
                used.add(nums[i]);
                path.push(nums[i]);
                dfs(i + 1, path);
                path.pop();
            }
        }
    }
    dfs(0, []);
    return ans;
};