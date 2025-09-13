/*
 You are given an array of integers nums of length n and a positive integer k.
 The power of an array is defined as:
 Its maximum element if all of its elements are consecutive and sorted in ascending order.
 -1 otherwise.
 You need to find the power of all subarrays of nums of size k.
 Return an integer array results of size n - k + 1, where results[i] is the power of nums[i..(i + k - 1)].
 Example 1:
 Input: nums = [1,2,3,4,3,2,5], k = 3
 Output: [3,4,-1,-1,-1]
 Explanation:
 There are 5 subarrays of nums of size 3:
 [1, 2, 3] with the maximum element 3.
 [2, 3, 4] with the maximum element 4.
 [3, 4, 3] whose elements are not consecutive.
 [4, 3, 2] whose elements are not sorted.
 [3, 2, 5] whose elements are not consecutive.
 Example 2:
 Input: nums = [2,2,2,2,2], k = 4
 Output: [-1,-1]
 Example 3:
 Input: nums = [3,2,3,2,3,2], k = 2
 Output: [-1,3,-1,3,-1]
 Constraints:
 1 <= n == nums.length <= 500
 1 <= nums[i] <= 105
 1 <= k <= n
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* resultsArray(int* nums, int numsSize, int k, int* returnSize) {
    *returnSize = numsSize - k + 1;
    int* results = (int*)malloc((*returnSize) * sizeof(int));
    
    for (int i = 0; i < *returnSize; i++) {
        int max = nums[i];
        int is_consecutive = 1;
        for (int j = 1; j < k; j++) {
            if (nums[i + j] > max) {
                max = nums[i + j];
            }
            if (nums[i + j] != nums[i + j - 1] + 1) {
                is_consecutive = 0;
            }
        }
        results[i] = is_consecutive ? max : -1;
    }
    
    return results;

}