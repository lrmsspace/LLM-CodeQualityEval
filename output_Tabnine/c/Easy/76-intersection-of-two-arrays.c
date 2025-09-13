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
    // Create an empty hash set
    int* hashSet = (int*)calloc(1001, sizeof(int));
    
    // Iterate through nums1 and mark the corresponding indices as 1
    for (int i = 0; i < nums1Size; i++) {
        hashSet[nums1[i]] = 1;
    }
    
    // Create an empty result array
    int* result = (int*)calloc(nums1Size, sizeof(int));
    *returnSize = 0;
    
    // Iterate through nums2 and add the intersection elements to the result array
    for (int i = 0; i < nums2Size; i++) {
        if (hashSet[nums2[i]] == 1) {
            result[*returnSize] = nums2[i];
            (*returnSize)++;
            hashSet[nums2[i]] = 0; // Mark the intersection element as visited
        }
    }
    
    // Free the hash set and return the result array
    free(hashSet);
    return result;

}