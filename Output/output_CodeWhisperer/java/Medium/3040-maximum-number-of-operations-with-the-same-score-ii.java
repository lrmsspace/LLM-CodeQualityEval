/*
 Given an array of integers called nums, you can perform any of the following operation while nums contains at least 2 elements:
 Choose the first two elements of nums and delete them.
 Choose the last two elements of nums and delete them.
 Choose the first and the last elements of nums and delete them.
 The score of the operation is the sum of the deleted elements.
 Your task is to find the maximum number of operations that can be performed, such that all operations have the same score.
 Return the maximum number of operations possible that satisfy the condition mentioned above.
 Example 1:
 Input: nums = [3,2,1,2,3,4]
 Output: 3
 Explanation: We perform the following operations:
 - Delete the first two elements, with score 3 + 2 = 5, nums = [1,2,3,4].
 - Delete the first and the last elements, with score 1 + 4 = 5, nums = [2,3].
 - Delete the first and the last elements, with score 2 + 3 = 5, nums = [].
 We are unable to perform any more operations as nums is empty.
 Example 2:
 Input: nums = [3,2,6,1,4]
 Output: 2
 Explanation: We perform the following operations:
 - Delete the first two elements, with score 3 + 2 = 5, nums = [6,1,4].
 - Delete the last two elements, with score 1 + 4 = 5, nums = [6].
 It can be proven that we can perform at most 2 operations.
 Constraints:
 2 <= nums.length <= 2000
 1 <= nums[i] <= 1000
*/

class Solution {
    public int maxOperations(int[] nums) {
        int n = nums.length;
        int[][] dp = new int[n][n];
        int max = 1;
        for (int i = 0; i < n - 1; i++) {
            dp[i][i + 1] = nums[i] + nums[i + 1];
        }
        
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                int score = nums[i] + nums[i + 1];
                if (score == dp[i + 2][j]) {
                    dp[i][j] = Math.max(dp[i][j], dp[i + 2][j] + score);
                    max = Math.max(max, dp[i + 2][j] / score + 1);
                }
                score = nums[j - 1] + nums[j];
                if (score == dp[i][j - 2]) {
                    dp[i][j] = Math.max(dp[i][j], dp[i][j - 2] + score);
                    max = Math.max(max, dp[i][j - 2] / score + 1);
                }
                if (nums[i] + nums[j] == nums[i + 1]) {
                    dp[i][j] = Math.max(dp[i][j], dp[i + 1][j - 1] + 2 * nums[i]);
                    max = Math.max(max, dp[i + 1][j - 1] / nums[i] + 2);
                }
            }
        }
        return max;           
    }
}