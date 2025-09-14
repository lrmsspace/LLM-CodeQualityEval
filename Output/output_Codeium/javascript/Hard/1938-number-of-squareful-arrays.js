/**https://leetcode.com/problems/number-of-squareful-arrays/ */
//An array is squareful if the sum of every pair of adjacent elements is a perfect square.
//Given an integer array nums, return the number of permutations of nums that are squareful.
//Two permutations perm1 and perm2 are different if there is some index i such that perm1[i] != perm2[i].
// 
//Example 1:
//Input: nums = [1,17,8]
//Output: 2
//Explanation: [1,8,17] and [17,8,1] are the valid permutations.
//Example 2:
//Input: nums = [2,2,2]
//Output: 1
// 
//Constraints:
//	1 <= nums.length <= 12
//	0 <= nums[i] <= 109
/**
 * @param {number[]} nums
 * @return {number}
 */
var numSquarefulPerms = function(nums) {
const isPerfectSquare = (num) => {
    const sqrt = Math.sqrt(num);
    return sqrt === Math.floor(sqrt);
};

const backtrack = (nums, used, path, result) => {
    if (path.length === nums.length) {
        result.push([...path]);
        return;
    }
    for (let i = 0; i < nums.length; i++) {
        if (used[i] || (i > 0 && nums[i] === nums[i - 1] && !used[i - 1])) continue;
        if (path.length === 0 || isPerfectSquare(path[path.length - 1] + nums[i])) {
            used[i] = true;
            path.push(nums[i]);
            backtrack(nums, used, path, result);
            path.pop();
            used[i] = false;
        }
    }
};

nums.sort((a, b) => a - b);
const result = [];
backtrack(nums, Array(nums.length).fill(false), [], result);
return result.length;

};