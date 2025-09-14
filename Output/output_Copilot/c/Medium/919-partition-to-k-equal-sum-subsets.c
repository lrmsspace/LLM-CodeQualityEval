/**https://leetcode.com/problems/partition-to-k-equal-sum-subsets/ */
//Given an integer array nums and an integer k, return true if it is possible to divide this array into k non-empty subsets whose sums are all equal.
// 
//Example 1:
//Input: nums = [4,3,2,3,5,2,1], k = 4
//Output: true
//Explanation: It is possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
//Example 2:
//Input: nums = [1,2,3,4], k = 3
//Output: false
// 
//Constraints:
//	1 <= k <= nums.length <= 16
//	1 <= nums[i] <= 104
//	The frequency of each element is in the range [1, 4].
bool canPartitionKSubsets(int* nums, int numsSize, int k) {
        
        int sum = 0;
        for (int i = 0; i < numsSize; i++) {
            sum += nums[i];
        }
        if (sum % k) {
            return false;
        }
        
        int target = sum / k;
        int visited = 0;
        int* dp = (int*)malloc((1 << numsSize) * sizeof(int));
        memset(dp, -1, (1 << numsSize) * sizeof(int));
        dp[0] = 0;
        
        for (int mask = 0; mask < (1 << numsSize); mask++) {
            if (dp[mask] == -1) {
                continue;
            }
            for (int i = 0; i < numsSize; i++) {
                if (!(mask & (1 << i)) && dp[mask] + nums[i] <= target) {
                    int newMask = mask | (1 << i);
                    int newSum = dp[mask] + nums[i];
                    if (newSum == target) {
                        newSum = 0;
                        visited++;
                    }
                    dp[newMask] = newSum;
                }
            }
        }
        
        return visited == k;
}