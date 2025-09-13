/**https://leetcode.com/problems/subarray-sum-equals-k/ */
//Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
//A subarray is a contiguous non-empty sequence of elements within an array.
// 
//Example 1:
//Input: nums = [1,1,1], k = 2
//Output: 2
//Example 2:
//Input: nums = [1,2,3], k = 3
//Output: 2
// 
//Constraints:
//	1 <= nums.length <= 2 * 104
//	-1000 <= nums[i] <= 1000
//	-107 <= k <= 107
int subarraySum(int* nums, int numsSize, int k) {
    int count = 0, sum = 0;
    int* prefixSum = (int*)malloc(sizeof(int) * (numsSize + 1));
    prefixSum[0] = 0;
    
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        prefixSum[i + 1] = sum;
    }
    
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j <= numsSize; j++) {
            if (prefixSum[j] - prefixSum[i] == k) {
                count++;
            }
        }
    }
    
    free(prefixSum);
    return count;
    
}