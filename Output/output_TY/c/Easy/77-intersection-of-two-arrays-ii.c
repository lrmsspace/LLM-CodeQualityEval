/**https://leetcode.com/problems/intersection-of-two-arrays-ii/ */
//Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.
// 
//Example 1:
//Input: nums1 = [1,2,2,1], nums2 = [2,2]
//Output: [2,2]
//Example 2:
//Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
//Output: [4,9]
//Explanation: [9,4] is also accepted.
// 
//Constraints:
//	1 <= nums1.length, nums2.length <= 1000
//	0 <= nums1[i], nums2[i] <= 1000
// 
//Follow up:
//	What if the given array is already sorted? How would you optimize your algorithm?
//	What if nums1's size is small compared to nums2's size? Which algorithm is better?
//	What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    // 哈希表大小
    const int hashSize = 1000;
    int* count1 = (int*)calloc(hashSize, sizeof(int));
    int* count2 = (int*)calloc(hashSize, sizeof(int));

    // 记录 nums1 中每个元素的出现次数
    for (int i = 0; i < nums1Size; i++) {
        count1[nums1[i] % hashSize]++;
    }

    // 记录 nums2 中每个元素的出现次数
    for (int i = 0; i < nums2Size; i++) {
        count2[nums2[i] % hashSize]++;
    }

    // 结果数组
    int* result = (int*)malloc((nums1Size < nums2Size ? nums1Size : nums2Size) * sizeof(int));
    *returnSize = 0;

    // 找到两个数组中共同出现的元素及其最小出现次数
    for (int i = 0; i < hashSize; i++) {
        if (count1[i] > 0 && count2[i] > 0) {
            int minCount = count1[i] < count2[i] ? count1[i] : count2[i];
            for (int j = 0; j < minCount; j++) {
                result[(*returnSize)++] = i;
            }
        }
    }

    // 释放内存
    free(count1);
    free(count2);

    return result;
}
