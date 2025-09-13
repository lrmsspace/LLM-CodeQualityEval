/**https://leetcode.com/problems/count-subarrays-with-median-k/ */
//You are given an array nums of size n consisting of distinct integers from 1 to n and a positive integer k.
//Return the number of non-empty subarrays in nums that have a median equal to k.
//Note:
//	The median of an array is the middle element after sorting the array in ascending order. If the array is of even length, the median is the left middle element.
//	
//		For example, the median of [2,3,1,4] is 2, and the median of [8,4,3,5,1] is 4.
//	
//	
//	A subarray is a contiguous part of an array.
// 
//Example 1:
//Input: nums = [3,2,1,4,5], k = 4
//Output: 3
//Explanation: The subarrays that have a median equal to 4 are: [4], [4,5] and [1,4,5].
//Example 2:
//Input: nums = [2,3,1], k = 3
//Output: 1
//Explanation: [3] is the only subarray that has a median equal to 3.
// 
//Constraints:
//	n == nums.length
//	1 <= n <= 105
//	1 <= nums[i], k <= n
//	The integers in nums are distinct.
class Solution {
    public int countSubarrays(int[] nums, int k) {
        int n = nums.length;
        int[] left = new int[n];
        int[] right = new int[n];
        
        int[] prefixSum = new int[n + 1];
        prefixSum[0] = 0;

        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
            left[i] = i + 1 - binarySearch(prefixSum, k, 0, i);
        }
        
        prefixSum[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            prefixSum[i] = prefixSum[i + 1] + nums[i];
            right[i] = n - i - 1 - binarySearch(prefixSum, k, i + 1, n - 1);
        }
        
        int count = 0;
        for (int i = 0; i < n; i++) {
            count += left[i] * right[i];
        }
        
        return count;
    }
}