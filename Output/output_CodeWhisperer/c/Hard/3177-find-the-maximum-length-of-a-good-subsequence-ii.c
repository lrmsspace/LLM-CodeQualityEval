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
 1 <= nums.length <= 5 * 103
 1 <= nums[i] <= 109
 0 <= k <= min(50, nums.length)
*/

int maximumLength(int* nums, int numsSize, int k) {
    // dp[i][j] represents max length ending at i with j differences
    int dp[5001][51] = {0};
    
    // Initialize first element
    dp[0][0] = 1;
    
    int maxLen = 1;
    
    // For each position
    for(int i = 1; i < numsSize; i++) {
        // Copy previous state
        dp[i][0] = 1;
        
        // For each allowed difference count
        for(int j = 0; j <= k; j++) {
            // Take previous element without adding difference
            if(nums[i] == nums[i-1]) {
                dp[i][j] = dp[i-1][j] + 1;
            }
            // Take previous element and add difference
            else if(j > 0) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            
            if(dp[i][j] > maxLen) {
                maxLen = dp[i][j];
            }
        }
    }
    
    return maxLen;
}            
