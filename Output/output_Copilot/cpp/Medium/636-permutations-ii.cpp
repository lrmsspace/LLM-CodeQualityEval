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
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> out, visited(nums.size(), 0);
        sort(nums.begin(), nums.end());
        permuteUniqueDFS(nums, 0, visited, out, res);
        return res;        
    }
};