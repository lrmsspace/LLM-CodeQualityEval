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
class Solution {
    public int[] maxNumber(int[] nums1, int[] nums2, int k) {
        
        int[] res = new int[k];
        
        //Compare the first k elements of nums1 and nums2
        int i = 0, j = 0;
        while (i < k && j < nums1.length && j < nums2.length) {
            if (compare(nums1, i, nums2, j) >= 0) {
                res[i] = nums1[i];
                i++;
            } else {
                res[i] = nums2[j];
                j++;
            }
        }
        
        // Copy the remaining elements from nums1 and nums2
        while (i < k && j < nums1.length) {
            res[i] = nums1[j];
            i++;
            j++;
        }
        while (i < k && j < nums2.length) {
            res[i] = nums2[j];
            i++;
            j++;
        }
        
        // Remove leading zeros
        int start = 0;
        while (start < k - 1 && res[start] == 0) {
            start++;
        }
        
        // Reverse the result array
        int left = start;
        int right = k - 1;
        while (left < right) {
            int temp = res[left];
            res[left] = res[right];
            res[right] = temp;
            left++;
            right--;
        }
        
        return res;
    }
}