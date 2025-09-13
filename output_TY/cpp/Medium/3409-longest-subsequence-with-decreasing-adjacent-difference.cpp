/*
 You are given an array of integers nums.
 Your task is to find the length of the longest subsequence seq of nums, such that the absolute differences between consecutive elements form a non-increasing sequence of integers. In other words, for a subsequence seq0, seq1, seq2, ..., seqm of nums, |seq1 - seq0| >= |seq2 - seq1| >= ... >= |seqm - seqm - 1|.
 Return the length of such a subsequence.
 Example 1:
 Input: nums = [16,6,3]
 Output: 3
 Explanation: 
 The longest subsequence is [16, 6, 3] with the absolute adjacent differences [10, 3].
 Example 2:
 Input: nums = [6,5,3,4,2,1]
 Output: 4
 Explanation:
 The longest subsequence is [6, 4, 2, 1] with the absolute adjacent differences [2, 2, 1].
 Example 3:
 Input: nums = [10,20,10,19,10,20]
 Output: 5
 Explanation: 
 The longest subsequence is [10, 20, 10, 19, 10] with the absolute adjacent differences [10, 10, 9, 9].
 Constraints:
 2 <= nums.length <= 104
 1 <= nums[i] <= 300
*/

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        memset(dp, 0, sizeof(dp));
        int ans = 0;
        for(int i = 0; i < n; i++){
            int mx = 0;
            for(int j = i - 1; j >= 0; j--){
                if(nums[j] > nums[i]){
                    mx = max(mx, dp[j]);
                }
            }
            dp[i] = mx + 1;
            ans = max(ans, dp[i]);
        }
        return ans;
        
    }
};