/*
 You are given an integer array nums. A good subsequence is defined as a subsequence of nums where the absolute difference between any two consecutive elements in the subsequence is exactly 1.
 Return the sum of all possible good subsequences of nums.
 Since the answer may be very large, return it modulo 109 + 7.
 Note that a subsequence of size 1 is considered good by definition.
 Example 1:
 Input: nums = [1,2,1]
 Output: 14
 Explanation:
 Good subsequences are: [1], [2], [1], [1,2], [2,1], [1,2,1].
 The sum of elements in these subsequences is 14.
 Example 2:
 Input: nums = [3,4,5]
 Output: 40
 Explanation:
 Good subsequences are: [3], [4], [5], [3,4], [4,5], [3,4,5].
 The sum of elements in these subsequences is 40.
 Constraints:
 1 <= nums.length <= 105
 0 <= nums[i] <= 105
*/

int sumOfGoodSubsequences(int* nums, int numsSize) {
    int max = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > max) {
            max = nums[i];
        }
    }
    int* dp = (int*)calloc(max + 1, sizeof(int));
    dp[0] = 1;
    for (int i = 0; i < numsSize; i++) {
        int* newDp = (int*)calloc(max + 1, sizeof(int));
        for (int j = 0; j <= max; j++) {
            newDp[j] = dp[j];
            if (nums[i] == j) {
                newDp[j] = (newDp[j] * 2 + 1) % 1000000007;
            } else if (nums[i] > j) {
                newDp[nums[i]] = (newDp[nums[i]] + dp[j]) % 1000000007;
            }
        }
        free(dp);
        dp = newDp;
    }
    int sum = 0;
    for (int i = 1; i <= max; i++) {
        sum = (sum + dp[i]) % 1000000007;
    }
    free(dp);
    return sum;

}