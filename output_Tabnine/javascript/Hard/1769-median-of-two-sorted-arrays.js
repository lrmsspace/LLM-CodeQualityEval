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
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findMedianSortedArrays = function(nums1, nums2) {
    const len1 = nums1.length;
    const len2 = nums2.length;
    
    if (len1 > len2) {
        return findMedianSortedArrays(nums2, nums1);
    }
    
    const totalLen = len1 + len2;
    const halfLen = Math.floor(totalLen / 2);
    
    let left = 0;
    let right = len1;
    
    while (left <= right) {
        const partitionX = Math.floor((left + right) / 2);
        const partitionY = halfLen - partitionX;
        
        const maxLeftX = partitionX === 0? -Infinity : nums1[partitionX - 1];
        const minRightX = partitionX === len1? Infinity : nums1[partitionX];
        
        const maxLeftY = partitionY === 0? -Infinity : nums2[partitionY - 1];
        const minRightY = partitionY === len2? Infinity : nums2[partitionY];
        
        if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
            if (totalLen % 2 === 0) {
                return (Math.max(maxLeftX, maxLeftY) + Math.min(minRightX, minRightY)) / 2;
            } else {
                return Math.max(maxLeftX, maxLeftY);
            }
        } else if (maxLeftX > minRightY) {
            right = partitionX - 1;
        } else {
            left = partitionX + 1;
        }


        // Edge case: when the total length is odd, the median is the larger of maxLeftX and maxLeftY
        if (totalLen % 2 === 1 && partitionX + partitionY === totalLen - 1) {
            return Math.max(maxLeftX, maxLeftY);
        }
    }
    
    // If the loop ends without finding the median, it means the input arrays are not sorted
    return null;
};