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
int countPartitions(int* nums, int numsSize, int k) {
    const int MOD = 1e9 + 7;
int countPartitionsUtil(int* nums, int numsSize, int k, int index, int currentSum, int totalSum, int** dp) {
    if (index == numsSize) {
        return (currentSum >= k && totalSum - currentSum >= k) ? 1 : 0;
    }
    if (dp[index][currentSum] != -1) {
        return dp[index][currentSum];
    }
    int include = countPartitionsUtil(nums, numsSize, k, index + 1, currentSum + nums[index], totalSum, dp);
    int exclude = countPartitionsUtil(nums, numsSize, k, index + 1, currentSum, totalSum, dp);
    dp[index][currentSum] = (include + exclude) % MOD;
    return dp[index][currentSum];
}

int countPartitions(int* nums, int numsSize, int k) {
    long long totalSum = 0;
    for (int i = 0; i < numsSize; i++) {
        totalSum += nums[i];
    }
    if (totalSum < 2 * k) {
        return 0;
    }
    int** dp = (int**)malloc(numsSize * sizeof(int*));
    for (int i = 0; i < numsSize; i++) {
        dp[i] = (int*)malloc((totalSum + 1) * sizeof(int));
        memset(dp[i], -1, (totalSum + 1) * sizeof(int));
    }
    int result = countPartitionsUtil(nums, numsSize, k, 0, 0, totalSum, dp);
    for (int i = 0; i < numsSize; i++) {
        free(dp[i]);
    }
    free(dp);
    return result;
}
}   
