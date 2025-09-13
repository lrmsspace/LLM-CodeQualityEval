/*
 You are given two integer arrays nums1 and nums2 of sizes n and m, respectively. Calculate the following values:
 answer1 : the number of indices i such that nums1[i] exists in nums2.
 answer2 : the number of indices i such that nums2[i] exists in nums1.
 Return [answer1,answer2].
 Example 1:
 Input: nums1 = [2,3,2], nums2 = [1,2]
 Output: [2,1]
 Explanation:
 Example 2:
 Input: nums1 = [4,3,2,3,1], nums2 = [2,2,5,2,3,6]
 Output: [3,4]
 Explanation:
 The elements at indices 1, 2, and 3 in nums1 exist in nums2 as well. So answer1 is 3.
 The elements at indices 0, 1, 3, and 4 in nums2 exist in nums1. So answer2 is 4.
 Example 3:
 Input: nums1 = [3,4,2,3], nums2 = [1,5]
 Output: [0,0]
 Explanation:
 No numbers are common between nums1 and nums2, so answer is [0,0].
 Constraints:
 n == nums1.length
 m == nums2.length
 1 <= n, m <= 100
 1 <= nums1[i], nums2[i] <= 100
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findIntersectionValues(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int count1 = 0, count2 = 0;
    for (int i = 0; i < nums1Size; i++) {
        for (int j = 0; j < nums2Size; j++) {
            if (nums1[i] == nums2[j])
                count1++;
        }
    }
    for (int i = 0; i < nums2Size; i++) {
        for (int j = 0; j < nums1Size; j++) {
            if (nums2[i] == nums1[j])
                count2++;
        }
    }
    *returnSize = 2;
    int* result = (int*)malloc(sizeof(int) * 2);
    result[0] = count1;
    result[1] = count2;
    return result;
}