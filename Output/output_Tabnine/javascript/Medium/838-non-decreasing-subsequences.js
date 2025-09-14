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
    let res = new Set();
    let dp = new Map();
    nums.sort((a, b) => a - b);
    
    function backtrack(start, prev) {
        if (start === nums.length) {
            res.add(prev.slice());
            return;
        }
        
        if (prev.length > 0 && nums[start] <= prev[prev.length - 1]) {
            backtrack(start + 1, prev);
            return;
        }
        
        for (let i = start; i < nums.length; i++) {
            if (prev.length === 0 || nums[i]!== prev[prev.length - 1]) {
                prev.push(nums[i]);
                backtrack(i + 1, prev);
                prev.pop();
            }
        }
    }
    
    backtrack(0, []);
    return Array.from(res);
    
};