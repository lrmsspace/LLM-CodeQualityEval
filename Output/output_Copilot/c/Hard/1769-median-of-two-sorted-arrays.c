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
    int n = nums1Size + nums2Size;
    int a = 0, b = 0;
    int pre = -1, cur = -1;
    for (int i = 0; i <= n / 2; i++) {
        pre = cur;
        if (a < nums1Size && (b >= nums2Size || nums1[a] < nums2[b])) {
            cur = nums1[a++];
        } else {
            cur = nums2[b++];
        }
    }
    return n % 2 ? cur : (pre + cur) / 2.0;    
}