/*
 You are given an integer array nums. In one operation, you can select a subarray and replace it with a single element equal to its maximum value.
 Return the maximum possible size of the array after performing zero or more operations such that the resulting array is non-decreasing.
 Example 1:
 Input: nums = [4,2,5,3,5]
 Output: 3
 Explanation:
 One way to achieve the maximum size is:
 Replace subarray nums[1..2] = [2, 5] with 5 → [4, 5, 3, 5].
 Replace subarray nums[2..3] = [3, 5] with 5 → [4, 5, 5].
 The final array [4, 5, 5] is non-decreasing with size 3.
 Example 2:
 Input: nums = [1,2,3]
 Output: 3
 Explanation:
 No operation is needed as the array [1,2,3] is already non-decreasing.
 Constraints:
 1 <= nums.length <= 2 * 105
 1 <= nums[i] <= 2 * 105
*/

class Solution {
    public int maximumPossibleSize(int[] nums) {
        int n = nums.length;
        int[] dp = new int[n];
        dp[0] = 1;

        for (int i = 1; i < n; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[j] <= nums[i]) {
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                }
            }
        }

        int maxSize = 0;
        for (int size : dp) {
            maxSize = Math.max(maxSize, size);
        }

        return maxSize;
    }
}