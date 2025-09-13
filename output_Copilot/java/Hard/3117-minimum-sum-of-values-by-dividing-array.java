/*
 You are given two arrays nums and andValues of length n and m respectively.
 The value of an array is equal to the last element of that array.
 You have to divide nums into m disjoint contiguous subarrays such that for the ith subarray [li, ri], the bitwise AND of the subarray elements is equal to andValues[i], in other words, nums[li] & nums[li + 1] & ... & nums[ri] == andValues[i] for all 1 <= i <= m, where & represents the bitwise AND operator.
 Return the minimum possible sum of the values of the m subarrays nums is divided into. If it is not possible to divide nums into m subarrays satisfying these conditions, return -1.
 Example 1:
 Input: nums = [1,4,3,3,2], andValues = [0,3,3,2]
 Output: 12
 Explanation:
 The only possible way to divide nums is:
 [1,4] as 1 & 4 == 0.
 [3] as the bitwise AND of a single element subarray is that element itself.
 [3] as the bitwise AND of a single element subarray is that element itself.
 [2] as the bitwise AND of a single element subarray is that element itself.
 The sum of the values for these subarrays is 4 + 3 + 3 + 2 = 12.
 Example 2:
 Input: nums = [2,3,5,7,7,7,5], andValues = [0,7,5]
 Output: 17
 Explanation:
 There are three ways to divide nums:
 [[2,3,5],[7,7,7],[5]] with the sum of the values 5 + 7 + 5 == 17.
 [[2,3,5,7],[7,7],[5]] with the sum of the values 7 + 7 + 5 == 19.
 [[2,3,5,7,7],[7],[5]] with the sum of the values 7 + 7 + 5 == 19.
 The minimum possible sum of the values is 17.
 Example 3:
 Input: nums = [1,2,3,4], andValues = [2]
 Output: -1
 Explanation:
 The bitwise AND of the entire array nums is 0. As there is no possible way to divide nums into a single subarray to have the bitwise AND of elements 2, return -1.
 Constraints:
 1 <= n == nums.length <= 104
 1 <= m == andValues.length <= min(n, 10)
 1 <= nums[i] < 105
 0 <= andValues[j] < 105
*/

class Solution {
    public int minimumValueSum(int[] nums, int[] andValues) {
        int n = nums.length;
        int m = andValues.length;

        // Create a DP table to store the minimum sum for each subarray
        int[][] dp = new int[m + 1][n + 1];
        for (int i = 0; i <= m; i++) {
            Arrays.fill(dp[i], Integer.MAX_VALUE);
        }
        dp[0][0] = 0;

        // Fill the DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // Check if we can form the i-th subarray ending at j-th element
                int andValue = andValues[i - 1];
                int currAnd = 0;
                for (int k = j; k >= 1; k--) {
                    currAnd &= nums[k - 1];
                    if (currAnd == andValue) {
                        dp[i][j] = Math.min(dp[i][j], dp[i - 1][k - 1] + nums[j - 1]);
                    }
                }
            }
        }

        // Find the minimum sum for the last subarray
        int minSum = Integer.MAX_VALUE;
        for (int j = 1; j <= n; j++) {
            minSum = Math.min(minSum, dp[m][j]);
        }

        return minSum == Integer.MAX_VALUE ? -1 : minSum;
    }
}