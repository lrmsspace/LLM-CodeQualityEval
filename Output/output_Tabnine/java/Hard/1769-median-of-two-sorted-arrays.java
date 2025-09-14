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
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int m = nums1.length, n = nums2.length;
        if (m > n) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int left = 0, right = m;
        while (left <= right) {
            int partitionX = left + (right - left) / 2;
            int partitionY = (m + n + 1) / 2 - partitionX;
            
            int maxLeftX = (partitionX == 0)? Integer.MIN_VALUE : nums1[partitionX - 1];
            int minRightX = (partitionX == m)? Integer.MAX_VALUE : nums1[partitionX];
            
            int maxLeftY = (partitionY == 0)? Integer.MIN_VALUE : nums2[partitionY - 1];
            int minRightY = (partitionY == n)? Integer.MAX_VALUE : nums2[partitionY];
    
            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                if ((m + n) % 2 == 0) {
                    return ((double) Math.max(maxLeftX, maxLeftY) + Math.min(minRightX, minRightY)) / 2;
                } else {
                    return Math.max(maxLeftX, maxLeftY);
                }
            } else if (maxLeftX > minRightY) {
                right = partitionX - 1;
            } else {
                left = partitionX + 1;
            }

        }
        return 0.0; // This line will never be executed as the while loop will always terminate.
        
    }
}