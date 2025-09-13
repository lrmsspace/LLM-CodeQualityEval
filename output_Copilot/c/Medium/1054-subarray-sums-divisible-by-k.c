/**https://leetcode.com/problems/subarray-sums-divisible-by-k/ */
//Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.
//A subarray is a contiguous part of an array.
// 
//Example 1:
//Input: nums = [4,5,0,-2,-3,1], k = 5
//Output: 7
//Explanation: There are 7 subarrays with a sum divisible by k = 5:
//[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
//Example 2:
//Input: nums = [5], k = 9
//Output: 0
// 
//Constraints:
//	1 <= nums.length <= 3 * 104
//	-104 <= nums[i] <= 104
//	2 <= k <= 104
int subarraysDivByK(int* nums, int numsSize, int k) {
    int count = 0;
    int *sums = (int *)malloc(sizeof(int) * numsSize);
    sums[0] = nums[0];
    for (int i = 1; i < numsSize; i++) {
        sums[i] = sums[i - 1] + nums[i];
    }
    for (int i = 0; i < numsSize; i++) {
        if (sums[i] % k == 0) {
            count++;
        }
        for (int j = 0; j < i; j++) {
            if ((sums[i] - sums[j]) % k == 0) {
                count++;
            }
        }
    }
    return count;    
}