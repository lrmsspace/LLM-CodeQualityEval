/*
 You are given an integer array nums and a non-negative integer k. A sequence of integers seq is called good if there are at most k indices i in the range [0, seq.length - 2] such that seq[i] != seq[i + 1].
 Return the maximum possible length of a good subsequence of nums.
 Example 1:
 Input: nums = [1,2,1,1,3], k = 2
 Output: 4
 Explanation:
 The maximum length subsequence is [1,2,1,1,3].
 Example 2:
 Input: nums = [1,2,3,4,5,1], k = 0
 Output: 2
 Explanation:
 The maximum length subsequence is [1,2,3,4,5,1].
 Constraints:
 1 <= nums.length <= 500
 1 <= nums[i] <= 109
 0 <= k <= min(nums.length, 25)
*/

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(k+1, 0));
        vector<vector<int>> cnt(n, vector<int>(k+1, 0));
        dp[0][0] = 1;
        cnt[0][0] = 1;
        for(int i = 1; i < n; i++){
            for(int j = 0; j <= k; j++){
                dp[i][j] = dp[i-1][j] + 1;
                if(nums[i] != nums[i-1]){
                    if(j > 0){
                        dp[i][j] = max(dp[i][j], cnt[i-1][j-1] + 1);
                    }
                }
                else{
                    if(j > 0){
                        dp[i][j] = max(dp[i][j], cnt[i-1][j] + 1);
                    }
                }
                cnt[i][j] = max(cnt[i-1][j], dp[i][j]);
            }
        }
        int ans = 0;
        for(int i = 0; i <= k; i++){
            ans = max(ans, dp[n-1][i]);
        }
        return ans;
      
    }
};