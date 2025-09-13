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
    let m = nums1.length;
    let n = nums2.length;
    let i = 0;
    let j = 0;
    let k = 0;
    let mid = Math.floor((m+n)/2);
    let median = 0;
    let temp = [];
    while(i<m && j<n){
        if(nums1[i]<nums2[j]){
            temp[k] = nums1[i];
            i++;
        }else{
            temp[k] = nums2[j];
            j++;
        }
        k++;
    }
    while(i<m){
        temp[k] = nums1[i];
    }
    while(j<n){
        temp[k] = nums2[j];
    }
    if(mid%2==0){
        median = (temp[mid]+temp[mid-1])/2;
    }else{
        median = temp[mid];
    }
    return median;
};