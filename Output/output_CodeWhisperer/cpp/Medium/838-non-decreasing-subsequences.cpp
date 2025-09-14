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
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> path;
        function<void(int)> dfs = [&](int start) {
            if (path.size() >= 2) {
                res.push_back(path);
            }
            unordered_set<int> used;
            for (int i = start; i < n; i++) {
                if (used.count(nums[i])) continue;
                if (path.empty() || nums[i] >= path.back()) {
                    used.insert(nums[i]);
                    path.push_back(nums[i]);
                    dfs(i + 1);
                    path.pop_back();
                }
            }
        };
        dfs(0);
        return res;      
    }
};