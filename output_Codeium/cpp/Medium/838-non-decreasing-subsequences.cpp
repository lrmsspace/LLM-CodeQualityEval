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
        vector<vector<int>> result;
        int n = nums.size();
        for (int mask = 0; mask < (1 << n); ++mask) {
            vector<int> sub;
            bool increasing = true;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    if (!sub.empty() && nums[i] < sub.back()) {
                        increasing = false;
                        break;
                    }
                    sub.push_back(nums[i]);
                }
            }
            if (increasing && sub.size() >= 2) result.push_back(sub);
        }
        return result;
    }
};