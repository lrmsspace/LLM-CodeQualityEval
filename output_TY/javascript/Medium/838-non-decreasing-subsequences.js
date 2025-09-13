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
    let result = [];
    let path = [];
    let used = new Array(nums.length).fill(false);
    
    const backtrack = (start) => {
        if (path.length >= 2) {
            result.push([...path]);
        }
        
        let usedSet = new Set();
        for (let i = start; i < nums.length; i++) {
            if (used[i] || usedSet.has(nums[i])) continue;
            
            used[i] = true;
            usedSet.add(nums[i]);
            path.push(nums[i]);
            backtrack(i + 1);
        }
    }
    
    backtrack(0);
    return result;
};