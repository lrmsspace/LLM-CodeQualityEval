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

class Solution {
    public int maximumLength(int[] nums, int k) {
        int n = nums.length;
        int[][] dp = new int[n][k + 1];
        int maxLen = 1;
        
        for (int i = 0; i < n; i++) {
            dp[i][nums[i] % (k + 1)] = 1;
        }
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < k + 1; j++) {
                for (int l = 0; l < k + 1; l++) {
                    int mod = (j + l) % (k + 1);
                    dp[i][mod] = Math.max(dp[i][mod], dp[i - 1][j] + 1);
                    maxLen = Math.max(maxLen, dp[i][mod]);
                }
            }
        }
        
        return maxLen;
                
    }
}