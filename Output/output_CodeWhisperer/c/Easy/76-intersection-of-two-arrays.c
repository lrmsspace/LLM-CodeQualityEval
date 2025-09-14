/**https://leetcode.com/problems/intersection-of-two-arrays/ */
//Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.
// 
//Example 1:
//Input: nums1 = [1,2,2,1], nums2 = [2,2]
//Output: [2]
//Example 2:
//Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
//Output: [9,4]
//Explanation: [4,9] is also accepted.
// 
//Constraints:
//	1 <= nums1.length, nums2.length <= 1000
//	0 <= nums1[i], nums2[i] <= 1000
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * nums1Size);
    *returnSize = 0;
    for (int i = 0; i < nums1Size; i++) {
        for (int j = 0; j < nums2Size; j++) {
            if (nums1[i] == nums2[j]) {
                int found = 0;
                for (int k = 0; k < *returnSize; k++) {
                    if (result[k] == nums1[i]) {
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    result[*returnSize] = nums1[i];
                    (*returnSize)++;
                }
                break;
            }
        }
    }
    return result;
    
}