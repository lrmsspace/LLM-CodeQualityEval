/**https://leetcode.com/problems/number-of-great-partitions/ */
//You are given an array nums consisting of positive integers and an integer k.
//Partition the array into two ordered groups such that each element is in exactly one group. A partition is called great if the sum of elements of each group is greater than or equal to k.
//Return the number of distinct great partitions. Since the answer may be too large, return it modulo 109 + 7.
//Two partitions are considered distinct if some element nums[i] is in different groups in the two partitions.
// 
//Example 1:
//Input: nums = [1,2,3,4], k = 4
//Output: 6
//Explanation: The great partitions are: ([1,2,3], [4]), ([1,3], [2,4]), ([1,4], [2,3]), ([2,3], [1,4]), ([2,4], [1,3]) and ([4], [1,2,3]).
//Example 2:
//Input: nums = [3,3,3], k = 4
//Output: 0
//Explanation: There are no great partitions for this array.
//Example 3:
//Input: nums = [6,6], k = 2
//Output: 2
//Explanation: We can either put nums[0] in the first partition or in the second partition.
//The great partitions will be ([6], [6]) and ([6], [6]).
// 
//Constraints:
//	1 <= nums.length, k <= 1000
//	1 <= nums[i] <= 109
class Solution {
    public int countPartitions(int[] nums, int k) {
        int mod = (int) 1e9 + 7;
        long sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if (sum < k) return 0;

        int n = nums.length;
        long[][] dp = new long[n + 1][(int) (sum + 1)];
        dp[0][0] = 1; // Base case: one way to make sum 0 with 0 elements

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= sum; j++) {
                dp[i][j] = dp[i - 1][j]; // Exclude current element
                if (j >= nums[i - 1]) {
                    dp[i][j] += dp[i - 1][j - nums[i - 1]]; // Include current element
                    dp[i][j] %= mod;
                }
            }
        }

        long totalWays = pow(2, n, mod); // Total ways to partition the array
        long invalidWays = 0;
        for (int j = k; j <= sum; j++) {
            invalidWays += dp[n][j];
            invalidWays %= mod;
        }

        return (int) ((totalWays - invalidWays + mod) % mod);        
    }
}