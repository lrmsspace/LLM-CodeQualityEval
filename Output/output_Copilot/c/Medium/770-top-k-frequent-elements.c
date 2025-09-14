/**https://leetcode.com/problems/top-k-frequent-elements/ */
//Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
// 
//Example 1:
//Input: nums = [1,1,1,2,2,3], k = 2
//Output: [1,2]
//Example 2:
//Input: nums = [1], k = 1
//Output: [1]
// 
//Constraints:
//	1 <= nums.length <= 105
//	-104 <= nums[i] <= 104
//	k is in the range [1, the number of unique elements in the array].
//	It is guaranteed that the answer is unique.
// 
//Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    int *res = (int *)malloc(sizeof(int) * k);
    *returnSize = k;
    int i, j, max = 0, maxIndex = 0;
    int *count = (int *)malloc(sizeof(int) * (2 * numsSize + 1));
    int *bucket = (int *)malloc(sizeof(int) * (numsSize + 1));
    for (i = 0; i < 2 * numsSize + 1; i++) {
        count[i] = 0;
    }
    for (i = 0; i < numsSize; i++) {
        count[nums[i] + numsSize]++;
    }
    for (i = 0; i < numsSize + 1; i++) {
        bucket[i] = 0;
    }
    for (i = 0; i < 2 * numsSize + 1; i++) {
        if (count[i] != 0) {
            bucket[count[i]]++;
        }
    }
    for (i = numsSize, j = 0; i >= 0 && j < k; i--) {
        if (bucket[i] != 0) {
            for (max = 0; max < bucket[i]; max++) {
                res[j++] = i - numsSize;
            }
        }
    }
    return res;    
}