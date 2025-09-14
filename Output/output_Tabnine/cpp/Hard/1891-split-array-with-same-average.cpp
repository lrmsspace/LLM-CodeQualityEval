/**https://leetcode.com/problems/split-array-with-same-average/ */
//You are given an integer array nums.
//You should move each element of nums into one of the two arrays A and B such that A and B are non-empty, and average(A) == average(B).
//Return true if it is possible to achieve that and false otherwise.
//Note that for an array arr, average(arr) is the sum of all the elements of arr over the length of arr.
// 
//Example 1:
//Input: nums = [1,2,3,4,5,6,7,8]
//Output: true
//Explanation: We can split the array into [1,4,5,8] and [2,3,6,7], and both of them have an average of 4.5.
//Example 2:
//Input: nums = [3,1]
//Output: false
// 
//Constraints:
//	1 <= nums.length <= 30
//	0 <= nums[i] <= 104
class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2!= 0) return false;
        int target = sum / 2;
        
        // dp[i][j] represents whether it is possible to split nums[0..i-1] into two subarrays A and B,
        // with sum of A equal to j.
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
        dp[0][0] = true;
        
        for (int i = 1; i <= n; ++i) {
            for (int j = target; j >= nums[i - 1]; --j) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
            }
        }
        
        return dp[n][target];
        
    }
};