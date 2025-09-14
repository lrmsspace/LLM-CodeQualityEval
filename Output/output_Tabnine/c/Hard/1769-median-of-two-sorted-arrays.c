/**https://leetcode.com/problems/median-of-two-sorted-arrays/ */
//Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
//The overall run time complexity should be O(log (m+n)).
// 
//Example 1:
//Input: nums1 = [1,3], nums2 = [2]
//Output: 2.00000
//Explanation: merged array = [1,2,3] and median is 2.
//Example 2:
//Input: nums1 = [1,2], nums2 = [3,4]
//Output: 2.50000
//Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
// 
//Constraints:
//	nums1.length == m
//	nums2.length == n
//	0 <= m <= 1000
//	0 <= n <= 1000
//	1 <= m + n <= 2000
//	-106 <= nums1[i], nums2[i] <= 106
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int totalSize = nums1Size + nums2Size;
    int mid = totalSize / 2;
    int* merged = (int*)malloc(totalSize * sizeof(int));
    int i = 0, j = 0, k = 0;
    
    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] < nums2[j]) {
            merged[k++] = nums1[i++];
        } else {
            merged[k++] = nums2[j++];
        }
    }
    
    while (i < nums1Size) {
        merged[k++] = nums1[i++];
    }
    
    while (j < nums2Size) {
        merged[k++] = nums2[j++];
    }
    
    double median;
    if (totalSize % 2 == 0) {
        median = (merged[mid - 1] + merged[mid]) / 2.0;
    } else {
        median = merged[mid];
    }
    
    free(merged);
    return median;
    
}