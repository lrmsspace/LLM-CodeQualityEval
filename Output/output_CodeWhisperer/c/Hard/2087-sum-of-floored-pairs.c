/**https://leetcode.com/problems/sum-of-floored-pairs/ */
//Given an integer array nums, return the sum of floor(nums[i] / nums[j]) for all pairs of indices 0 <= i, j < nums.length in the array. Since the answer may be too large, return it modulo 109 + 7.
//The floor() function returns the integer part of the division.
// 
//Example 1:
//Input: nums = [2,5,9]
//Output: 10
//Explanation:
//floor(2 / 5) = floor(2 / 9) = floor(5 / 9) = 0
//floor(2 / 2) = floor(5 / 5) = floor(9 / 9) = 1
//floor(5 / 2) = 2
//floor(9 / 2) = 4
//floor(9 / 5) = 1
//We calculate the floor of the division for every pair of indices in the array then sum them up.
//Example 2:
//Input: nums = [7,7,7,7,7,7,7]
//Output: 49
// 
//Constraints:
//	1 <= nums.length <= 105
//	1 <= nums[i] <= 105
int sumOfFlooredPairs(int* nums, int numsSize) {
    int i, j;
    int* dp = (int*)malloc(sizeof(int) * numsSize);
    int* dp2 = (int*)malloc(sizeof(int) * numsSize);
    for (i = 0; i < numsSize; i++) {
        dp[i] = 1;
        dp2[i] = 0;
        for (j = 0; j < i; j++) {
            if (nums[i] % nums[j] == 0) {
                dp[i] += dp[j];
                dp2[i] += dp[j];
            }
        }
    }
    int sum = 0;
    for (i = 0; i < numsSize; i++) {
        sum = (sum + dp2[i]) % 1000000007;
    }
    return sum;
}