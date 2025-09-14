/**https://leetcode.com/problems/permutations-ii/ */
//Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.
// 
//Example 1:
//Input: nums = [1,1,2]
//Output:
//[[1,1,2],
// [1,2,1],
// [2,1,1]]
//Example 2:
//Input: nums = [1,2,3]
//Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// 
//Constraints:
//	1 <= nums.length <= 8
//	-10 <= nums[i] <= 10
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permuteUnique = function(nums) {
    const res = [];
    const visited = new Array(nums.length).fill(false);
    nums.sort((a, b) => a - b);
    const backtrack = (path) => {
        if (path.length === nums.length) {
            res.push([...path]);
            return;
        }
        for (let i = 0; i < nums.length; i++) {
            if (visited[i] || (i > 0 && nums[i] === nums[i - 1] && !visited[i - 1])) continue;
            visited[i] = true;
            path.push(nums[i]);
            backtrack(path);
            visited[i] = false;
            path.pop();
        }
    };
    backtrack([]);
    return res;
};