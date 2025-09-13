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
    const res = [];
    const dfs = (i, path) => {
        if (path.length > 1) res.push([...path]);
        const used = new Set();
        for (let j = i; j < nums.length; j++) {
            if (used.has(nums[j])) continue;
            if (path.length && path[path.length-1] > nums[j]) continue;
            used.add(nums[j]);
            path.push(nums[j]);
            dfs(j + 1, path);
            path.pop();
        }
    };
    dfs(0, []);
    return res;
    
};