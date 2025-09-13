/**https://leetcode.com/problems/advantage-shuffle/ */
//You are given two integer arrays nums1 and nums2 both of the same length. The advantage of nums1 with respect to nums2 is the number of indices i for which nums1[i] > nums2[i].
//Return any permutation of nums1 that maximizes its advantage with respect to nums2.
// 
//Example 1:
//Input: nums1 = [2,7,11,15], nums2 = [1,10,4,11]
//Output: [2,11,7,15]
//Example 2:
//Input: nums1 = [12,24,8,32], nums2 = [13,25,32,11]
//Output: [24,32,8,12]
// 
//Constraints:
//	1 <= nums1.length <= 105
//	nums2.length == nums1.length
//	0 <= nums1[i], nums2[i] <= 109
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* advantageCount(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    // Store sorted indices of nums1 and nums2
    int* sorted_nums1 = (int*)malloc(nums1Size * sizeof(int));
    int* sorted_nums2 = (int*)malloc(nums2Size * sizeof(int));
    for (int i = 0; i < nums1Size; i++) {
        sorted_nums1[i] = i;
        sorted_nums2[i] = i;
    }
    qsort(sorted_nums1, nums1Size, sizeof(int), (int (*)(const void*, const void*))compare);
    qsort(sorted_nums2, nums2Size, sizeof(int), (int (*)(const void*, const void*))compare);

    int* result = (int*)malloc(nums1Size * sizeof(int));
    for (int i = 0; i < nums1Size; i++) {
        if (nums1[sorted_nums1[i]] > nums2[sorted_nums2[i]]) {
            result[i] = nums1[sorted_nums1[i]];
        } else {
            result[i] = nums2[sorted_nums2[i]];
            sorted_nums2[i]++;
        }
    }    
    *returnSize = nums1Size;
    return result;  
    
}