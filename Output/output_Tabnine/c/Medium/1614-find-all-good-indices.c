/**https://leetcode.com/problems/find-all-good-indices/ */
//You are given a 0-indexed integer array nums of size n and a positive integer k.
//We call an index i in the range k <= i < n - k good if the following conditions are satisfied:
//	The k elements that are just before the index i are in non-increasing order.
//	The k elements that are just after the index i are in non-decreasing order.
//Return an array of all good indices sorted in increasing order.
// 
//Example 1:
//Input: nums = [2,1,1,1,3,4,1], k = 2
//Output: [2,3]
//Explanation: There are two good indices in the array:
//- Index 2. The subarray [2,1] is in non-increasing order, and the subarray [1,3] is in non-decreasing order.
//- Index 3. The subarray [1,1] is in non-increasing order, and the subarray [3,4] is in non-decreasing order.
//Note that the index 4 is not good because [4,1] is not non-decreasing.
//Example 2:
//Input: nums = [2,1,1,2], k = 2
//Output: []
//Explanation: There are no good indices in this array.
// 
//Constraints:
//	n == nums.length
//	3 <= n <= 105
//	1 <= nums[i] <= 106
//	1 <= k <= n / 2
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* goodIndices(int* nums, int numsSize, int k, int* returnSize) {
    int* result = malloc(sizeof(int) * numsSize);
    *returnSize = 0;
    
    for (int i = k; i < numsSize - k; i++) {
        int left = 1, right = k - 1;
        while (left < k && nums[i - left] >= nums[i - left - 1]) left++;
        while (right >= 0 && nums[i + right] <= nums[i + right + 1]) right--;
        
        if (left == k && right == -1) {
            result[*returnSize] = i;
            (*returnSize)++;
        }
    }
    
    int* sortedResult = malloc(sizeof(int) * *returnSize);
    memcpy(sortedResult, result, sizeof(int) * *returnSize);
    qsort(sortedResult, *returnSize, sizeof(int), compare);
    
    free(result);
    return sortedResult;
    
}