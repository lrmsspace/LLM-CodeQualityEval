/**https://leetcode.com/problems/subsets-ii/ */
//Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
//The solution set must not contain duplicate subsets. Return the solution in any order.
// 
//Example 1:
//Input: nums = [1,2,2]
//Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
//Example 2:
//Input: nums = [0]
//Output: [[],[0]]
// 
//Constraints:
//	1 <= nums.length <= 10
//	-10 <= nums[i] <= 10
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var subsetsWithDup = function(nums) {
    let result = [];
    nums.sort((a, b) => a - b); // Sort the array to handle duplicates
    const backtrack = (start, path) => {
        result.push([...path]); // Add the current subset to the result
        for (let i = start; i < nums.length; i++) {
            if (i > start && nums[i] === nums[i - 1]) continue; // Skip duplicates
            path.push(nums[i]); // Include the current number
            backtrack(i + 1, path); // Recurse with the next index
            path.pop(); // Backtrack
        }
    };
    backtrack(0, []);
    return result;    
};