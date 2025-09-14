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
class Solution {
public:
    int numSquarefulPerms(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<bool> used(n, false);
        unordered_map<int, vector<pair<int, int>>> graph;
        for (int i = 0; i < n - 1; ++i) {
            int sum = nums[i] + nums[i + 1];
            if (is_square(sum)) {
                graph[nums[i]].push_back({nums[i + 1], i});
                graph[nums[i + 1]].push_back({nums[i], i + 1});
            }
        }
        int res = 0;
        dfs(graph, used, nums, 0, res);
        return res;
        
    }
};