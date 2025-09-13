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
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        sort(nums.begin(), nums.end());
        
        function<void(int)> backtrack = [&](int start) {
            result.push_back(subset);
            for (int i = start; i < nums.size(); ++i) {
                if (i > start && nums[i] == nums[i - 1]) continue;
                subset.push_back(nums[i]);
                backtrack(i + 1);
                subset.pop_back();
            }
        };
        
        backtrack(0);
        return result;

    }
};