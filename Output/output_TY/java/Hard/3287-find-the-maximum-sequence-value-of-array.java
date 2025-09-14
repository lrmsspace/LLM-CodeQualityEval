/*
 You are given an integer array nums and a positive integer k.
 The value of a sequence seq of size 2 * x is defined as:
 (seq[0] OR seq[1] OR ... OR seq[x - 1]) XOR (seq[x] OR seq[x + 1] OR ... OR seq[2 * x - 1]).
 Return the maximum value of any subsequence of nums having size 2 * k.
 Example 1:
 Input: nums = [2,6,7], k = 1
 Output: 5
 Explanation:
 The subsequence [2, 7] has the maximum value of 2 XOR 7 = 5.
 Example 2:
 Input: nums = [4,2,5,6,7], k = 2
 Output: 2
 Explanation:
 The subsequence [4, 5, 6, 7] has the maximum value of (4 OR 5) XOR (6 OR 7) = 2.
 Constraints:
 2 <= nums.length <= 400
 1 <= nums[i] < 27
 1 <= k <= nums.length / 2
*/

class Solution {
    public int maxValue(int[] nums, int k) {

        int n = nums.length;
        int[] dp = new int[n];
        Arrays.fill(dp, 0);
        
        for(int i = 0; i < n; i++) {
            int maxXor = 0;
            for(int j = i; j >= 0; j--) {
                maxXor = Math.max(maxXor, nums[j]);
                dp[i] = Math.max(dp[i], maxXor ^ dp[j - 1]);
            }
        }
        
        return dp[n - 1];
        
    }
}