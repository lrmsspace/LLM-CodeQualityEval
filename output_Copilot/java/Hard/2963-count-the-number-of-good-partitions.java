/*
 You are given a 0-indexed array nums consisting of positive integers.
 A partition of an array into one or more contiguous subarrays is called good if no two subarrays contain the same number.
 Return the total number of good partitions of nums.
 Since the answer may be large, return it modulo 109 + 7.
 Example 1:
 Input: nums = [1,2,3,4]
 Output: 8
 Explanation: The 8 possible good partitions are: ([1], [2], [3], [4]), ([1], [2], [3,4]), ([1], [2,3], [4]), ([1], [2,3,4]), ([1,2], [3], [4]), ([1,2], [3,4]), ([1,2,3], [4]), and ([1,2,3,4]).
 Example 2:
 Input: nums = [1,1,1,1]
 Output: 1
 Explanation: The only possible good partition is: ([1,1,1,1]).
 Example 3:
 Input: nums = [1,2,1,3]
 Output: 2
 Explanation: The 2 possible good partitions are: ([1,2,1], [3]) and ([1,2,1,3]).
 Constraints:
 1 <= nums.length <= 105
 1 <= nums[i] <= 109
*/

class Solution {
    public int numberOfGoodPartitions(int[] nums) {
        int n = nums.length;
        int mod = 1000000007;
        long[] dp = new long[n + 1];
        dp[0] = 1; // Base case: one way to partition an empty array

        // Map to store the last occurrence of each number
        Map<Integer, Integer> lastOccurrence = new HashMap<>();

        for (int i = 1; i <= n; i++) {
            int num = nums[i - 1];
            dp[i] = (2 * dp[i - 1]) % mod; // Double the number of partitions from the previous index

            if (lastOccurrence.containsKey(num)) {
                int lastIndex = lastOccurrence.get(num);
                dp[i] = (dp[i] - dp[lastIndex - 1] + mod) % mod; // Subtract partitions that would repeat the number
            }

            lastOccurrence.put(num, i); // Update the last occurrence of the current number
        }

        return (int) dp[n]; // Return the total number of good partitions          
    }
}