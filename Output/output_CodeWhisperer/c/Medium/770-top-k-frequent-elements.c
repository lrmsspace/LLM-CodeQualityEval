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
    int* result = (int*)malloc(sizeof(int) * k);
    *returnSize = k;
    int* count = (int*)calloc(20001, sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        count[nums[i] + 10000]++;
    }
    int* bucket = (int*)calloc(numsSize + 1, sizeof(int));
    for (int i = 0; i < 20001; i++) {
        if (count[i] > 0) {
            bucket[count[i]]++;
            bucket[count[i]]--;
        }
    }
    int j = 0;
    for (int i = numsSize; i >= 0; i--) {
        while (bucket[i] > 0) {
            for (int m = 0; m < 20001; m++) {
                if (count[m] == i) {
                    result[j++] = m - 10000;
                    bucket[i]--;
                    if (j == k) {
                        return result;
                    }
                }
            }
        }
    }
    return result;
}