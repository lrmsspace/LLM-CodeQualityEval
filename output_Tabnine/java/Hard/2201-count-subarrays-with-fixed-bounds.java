/**https://leetcode.com/problems/count-subarrays-with-fixed-bounds/ */
//You are given an integer array nums and two integers minK and maxK.
//A fixed-bound subarray of nums is a subarray that satisfies the following conditions:
//	The minimum value in the subarray is equal to minK.
//	The maximum value in the subarray is equal to maxK.
//Return the number of fixed-bound subarrays.
//A subarray is a contiguous part of an array.
// 
//Example 1:
//Input: nums = [1,3,5,2,7,5], minK = 1, maxK = 5
//Output: 2
//Explanation: The fixed-bound subarrays are [1,3,5] and [1,3,5,2].
//Example 2:
//Input: nums = [1,1,1,1], minK = 1, maxK = 1
//Output: 10
//Explanation: Every subarray of nums is a fixed-bound subarray. There are 10 possible subarrays.
// 
//Constraints:
//	2 <= nums.length <= 105
//	1 <= nums[i], minK, maxK <= 106
class Solution {
    public long countSubarrays(int[] nums, int minK, int maxK) {
        int n = nums.length;
        long count = 0;
        int left = 0;
        int[] leftMin = new int[n];
        int[] leftMax = new int[n];
        leftMin[0] = nums[0];
        leftMax[0] = nums[0];
        
        for (int i = 1; i < n; i++) {
            leftMin[i] = Math.min(nums[i], leftMin[i - 1]);
            leftMax[i] = Math.max(nums[i], leftMax[i - 1]);
        }
        
        for (int right = 0; right < n; right++) {
            while (left < right && leftMin[left] < minK) left++;
            while (left < right && leftMax[right] > maxK) right--;
            count += right - left + 1;
        }
        
        return count;
    }
}