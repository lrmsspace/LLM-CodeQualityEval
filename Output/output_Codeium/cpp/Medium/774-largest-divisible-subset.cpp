/**https://leetcode.com/problems/largest-divisible-subset/ */
//Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:
//	answer[i] % answer[j] == 0, or
//	answer[j] % answer[i] == 0
//If there are multiple solutions, return any of them.
// 
//Example 1:
//Input: nums = [1,2,3]
//Output: [1,2]
//Explanation: [1,3] is also accepted.
//Example 2:
//Input: nums = [1,2,4,8]
//Output: [1,2,4,8]
// 
//Constraints:
//	1 <= nums.length <= 1000
//	1 <= nums[i] <= 2 * 109
//	All the integers in nums are unique.
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.empty()) return {};
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, 1), previous(n, -1);
        int max_subset_size = 0, max_subset_index = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    previous[i] = j;
                }
            }
            if (dp[i] > max_subset_size) {
                max_subset_size = dp[i];
                max_subset_index = i;
            }
        }
        
        vector<int> largest_subset;
        for (int i = max_subset_index; i >= 0; i = previous[i]) {
            largest_subset.push_back(nums[i]);
            if (previous[i] == i) break;
        }
        
        reverse(largest_subset.begin(), largest_subset.end());
        
        return largest_subset;

    }
};