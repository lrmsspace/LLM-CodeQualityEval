/**https://leetcode.com/problems/create-maximum-number/ */
//You are given two integer arrays nums1 and nums2 of lengths m and n respectively. nums1 and nums2 represent the digits of two numbers. You are also given an integer k.
//Create the maximum number of length k <= m + n from digits of the two numbers. The relative order of the digits from the same array must be preserved.
//Return an array of the k digits representing the answer.
// 
//Example 1:
//Input: nums1 = [3,4,6,5], nums2 = [9,1,2,5,8,3], k = 5
//Output: [9,8,6,5,3]
//Example 2:
//Input: nums1 = [6,7], nums2 = [6,0,4], k = 5
//Output: [6,7,6,0,4]
//Example 3:
//Input: nums1 = [3,9], nums2 = [8,9], k = 3
//Output: [9,8,9]
// 
//Constraints:
//	m == nums1.length
//	n == nums2.length
//	1 <= m, n <= 500
//	0 <= nums1[i], nums2[i] <= 9
//	1 <= k <= m + n
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxNumber(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int* returnSize) {
    // Convert the arrays into strings for easier manipulation
    char *str1 = malloc((nums1Size + 1) * sizeof(char));
    char *str2 = malloc((nums2Size + 1) * sizeof(char));
    
    for (int i = 0; i < nums1Size; i++) {
        sprintf(str1 + i, "%d", nums1[i]);
    }
    str1[nums1Size] = '\0';
    
    for (int i = 0; i < nums2Size; i++) {
        sprintf(str2 + i, "%d", nums2[i]);
    }
    str2[nums2Size] = '\0';
    
    // Find the maximum number of k digits from nums1 and nums2
    char *maxNum = findMaxNumber(str1, str2, k);
    
    // Convert the maximum number back into an array of integers
    int *result = malloc((k + 1) * sizeof(int));
    *returnSize = k;
    
    for (int i = 0; i < k; i++) {
        result[i] = maxNum[i] - '0';
    }
    
    // Free the temporary strings
    free(str1);
    free(str2);
    free(maxNum);
    
    return result;
    
}