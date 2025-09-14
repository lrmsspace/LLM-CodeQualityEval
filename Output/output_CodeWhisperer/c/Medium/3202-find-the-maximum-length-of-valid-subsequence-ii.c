/*
 You are given an integer array nums and a positive integer k.
 A subsequence sub of nums with length x is called valid if it satisfies:
 (sub[0] + sub[1]) % k == (sub[1] + sub[2]) % k == ... == (sub[x - 2] + sub[x - 1]) % k.
 Return the length of the longest valid subsequence of nums.
 Example 1:
 Input: nums = [1,2,3,4,5], k = 2
 Output: 5
 Explanation:
 The longest valid subsequence is [1, 2, 3, 4, 5].
 Example 2:
 Input: nums = [1,4,2,3,1,4], k = 3
 Output: 4
 Explanation:
 The longest valid subsequence is [1, 4, 1, 4].
 Constraints:
 2 <= nums.length <= 103
 1 <= nums[i] <= 107
 1 <= k <= 103
*/

int maximumLength(int* nums, int numsSize, int k) {
    // dp[i][j] represents the longest valid subsequence ending at index i with remainder j
    int dp[1001][1001] = {0};
    int maxLen = 0;
    
    // Initialize dp array for single elements
    for(int i = 0; i < numsSize; i++) {
        dp[i][0] = 1;
        maxLen = 1;
    }
    
    // For each ending position
    for(int i = 1; i < numsSize; i++) {
        // Try each previous position as start of pair
        for(int j = 0; j < i; j++) {
            // Get remainder when pair sum divided by k
            int rem = (nums[j] + nums[i]) % k;
            
            // If this is first pair, length is 2
            if(dp[j][0] == 1) {
                dp[i][rem] = 2;
            }
            // If remainder matches previous pair's remainder
            // Extend the subsequence
            else {
                for(int r = 0; r < k; r++) {
                    if(dp[j][r] > 0 && r == rem) {
                        dp[i][rem] = dp[j][r] + 1;
                    }
                }
            }
            
            // Update max length found
            if(dp[i][rem] > maxLen) {
                maxLen = dp[i][rem];
            }
        }
    }
    
    return maxLen;
}    