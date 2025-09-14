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
        int n = nums.size();
        if(n == 0) return {};
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1), prev(n, -1);
        int max_len = 1, max_index = 0;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                    if(dp[i] > max_len){
                        max_len = dp[i];
                        max_index = i;
                    }
                }
            }
        }
        vector<int> res;
        for(int i = max_index; i != -1; i = prev[i]){
            res.push_back(nums[i]);
        }
        return res;     
    }
};