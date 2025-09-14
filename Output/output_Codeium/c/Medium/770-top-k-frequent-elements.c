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
    int count[200001] = {0};
    int* res = (int*)malloc(k * sizeof(int));
    int max = 0;
    for (int i = 0; i < numsSize; i++) {
        count[nums[i] + 100000]++;
        max = max > count[nums[i] + 100000] ? max : count[nums[i] + 100000];
    }
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < 200001; j++) {
            if (count[j] == max) {
                res[i] = j - 100000;
                max--;
                break;
            }
        }
    }
    *returnSize = k;
    return res;
}