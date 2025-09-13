/**https://leetcode.com/problems/two-out-of-three/ */
//Given three integer arrays nums1, nums2, and nums3, return a distinct array containing all the values that are present in at least two out of the three arrays. You may return the values in any order.
// 
//Example 1:
//Input: nums1 = [1,1,3,2], nums2 = [2,3], nums3 = [3]
//Output: [3,2]
//Explanation: The values that are present in at least two arrays are:
//- 3, in all three arrays.
//- 2, in nums1 and nums2.
//Example 2:
//Input: nums1 = [3,1], nums2 = [2,3], nums3 = [1,2]
//Output: [2,3,1]
//Explanation: The values that are present in at least two arrays are:
//- 2, in nums2 and nums3.
//- 3, in nums1 and nums2.
//- 1, in nums1 and nums3.
//Example 3:
//Input: nums1 = [1,2,2], nums2 = [4,3,3], nums3 = [5]
//Output: []
//Explanation: No value is present in at least two arrays.
// 
//Constraints:
//	1 <= nums1.length, nums2.length, nums3.length <= 100
//	1 <= nums1[i], nums2[j], nums3[k] <= 100
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoOutOfThree(int* nums1, int nums1Size, int* nums2, int nums2Size, int* nums3, int nums3Size, int* returnSize){
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int* result = (int*)malloc(sizeof(int) * 100);
    int count = 0;
    for (i = 0; i < nums1Size; i++) {
        for (j = 0; j < nums2Size; j++) {
           if (nums1[i] == nums2[j])
        }
    }
    return result;
}