/*
 You are given an integer array nums of length n.
 Your goal is to start at index 0 and reach index n - 1. You can only jump to indices greater than your current index.
 The score for a jump from index i to index j is calculated as (j - i) * nums[i].
 Return the maximum possible total score by the time you reach the last index.
 Example 1:
 Input: nums = [1,3,1,5]
 Output: 7
 Explanation:
 First, jump to index 1 and then jump to the last index. The final score is 1 * 1 + 2 * 3 = 7.
 Example 2:
 Input: nums = [4,3,1,3,2]
 Output: 16
 Explanation:
 Jump directly to the last index. The final score is 4 * 4 = 16.
 Constraints:
 1 <= nums.length <= 105
 1 <= nums[i] <= 105
*/

class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        int n = nums.size();
        vector<long long> dp(n);
        dp[n - 1] = nums[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            dp[i] = max(dp[i + 1] + nums[i], nums[i]);
        }
        long long res = 0;
        long long sum = 0;
        for(int i = 0; i < n - 1; i++) {
            sum += nums[i];
            res = max(res, sum + dp[i + 1]);
        }
        return res;

            
    }
};