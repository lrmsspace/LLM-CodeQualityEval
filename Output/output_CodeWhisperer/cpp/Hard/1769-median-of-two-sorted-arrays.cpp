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
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int m = nums1.size();
        int n = nums2.size();
        int total = m + n;
        int half = total / 2;
        int AIndex = 0;
        int BIndex = 0;
        int median1 = 0;
        int median2 = 0;
        for (int i = 0; i <= half; i++) {
            median1 = median2;
            if (AIndex < m && (BIndex >= n || nums1[AIndex] < nums2[BIndex])) {
                median2 = nums1[AIndex];
                AIndex++;
            } else {
                median2 = nums2[BIndex];
                BIndex++;
            }
        }
        if (total % 2 == 0) {
            return (median1 + median2) / 2.0;
        } else {
            return median2;
        }
    }
};