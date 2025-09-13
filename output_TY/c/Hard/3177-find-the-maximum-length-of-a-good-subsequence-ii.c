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
    int i, j, count, max_len, len;
    int *dp;
    
    dp = (int *)malloc(sizeof(int) * numsSize);
    memset(dp, 0, sizeof(int) * numsSize);
    
    max_len = 0;
    for (i = 0; i < numsSize; i++) {
        count = 0;
        for (j = i - 1; j >= 0; j--) {
            if (nums[j] == nums[i]) {
                count = dp[j] + 1;
                break;
            }
        }
        if (count > k) {
            max_len = max(max_len, count);  
}
    }
    return max_len;
    
}