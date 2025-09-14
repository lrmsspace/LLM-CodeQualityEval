/**https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/ */
//Given an integer array nums and an integer k, return the length of the shortest non-empty subarray of nums with a sum of at least k. If there is no such subarray, return -1.
//A subarray is a contiguous part of an array.
// 
//Example 1:
//Input: nums = [1], k = 1
//Output: 1
//Example 2:
//Input: nums = [1,2], k = 4
//Output: -1
//Example 3:
//Input: nums = [2,-1,2], k = 3
//Output: 3
// 
//Constraints:
//	1 <= nums.length <= 105
//	-105 <= nums[i] <= 105
//	1 <= k <= 109
int shortestSubarray(int* nums, int numsSize, int k) {
    int* prefixSum = (int*)malloc(sizeof(int) * (numsSize + 1));
    prefixSum[0] = 0;
    for (int i = 1; i <= numsSize; i++) {
        prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
    }
    
    int minLength = INT_MAX;
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j <= numsSize; j++) {
            int sum = prefixSum[j] - prefixSum[i];
            if (sum >= k && j - i < minLength) {
                minLength = j - i;
            }
        }
    }
    
    free(prefixSum);
    return minLength == INT_MAX? -1 : minLength;
    
}