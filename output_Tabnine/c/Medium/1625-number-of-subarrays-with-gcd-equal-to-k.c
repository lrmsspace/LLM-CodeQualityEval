/**https://leetcode.com/problems/number-of-subarrays-with-gcd-equal-to-k/ */
//Given an integer array nums and an integer k, return the number of subarrays of nums where the greatest common divisor of the subarray's elements is k.
//A subarray is a contiguous non-empty sequence of elements within an array.
//The greatest common divisor of an array is the largest integer that evenly divides all the array elements.
// 
//Example 1:
//Input: nums = [9,3,1,2,6,3], k = 3
//Output: 4
//Explanation: The subarrays of nums where 3 is the greatest common divisor of all the subarray's elements are:
//- [9,3,1,2,6,3]
//- [9,3,1,2,6,3]
//- [9,3,1,2,6,3]
//- [9,3,1,2,6,3]
//Example 2:
//Input: nums = [4], k = 7
//Output: 0
//Explanation: There are no subarrays of nums where 7 is the greatest common divisor of all the subarray's elements.
// 
//Constraints:
//	1 <= nums.length <= 1000
//	1 <= nums[i], k <= 109
int subarrayGCD(int* nums, int numsSize, int k) {
    int count = 0;
    int prefix[numsSize + 1];
    prefix[0] = 1;
    for (int i = 0; i < numsSize; i++) {
        prefix[i + 1] = prefix[i] * nums[i] % k;
    }
    int* dp = (int*)calloc(k + 1, sizeof(int));
    for (int i = 1; i <= numsSize; i++) {
        for (int j = k; j >= nums[i - 1]; j--) {
            dp[j] = (dp[j] + dp[j - nums[i - 1]]) % MOD;
        }
    }
    for (int i = 1; i <= k; i++) {
        count = (count + dp[i]) % MOD;
    }
    free(dp);
    return count;
    
}