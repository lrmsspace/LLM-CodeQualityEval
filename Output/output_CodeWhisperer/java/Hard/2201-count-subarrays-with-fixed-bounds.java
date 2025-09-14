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
        long res = 0, j = 0, k1 = -1, k2 = -1;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] < minK || nums[i] > maxK) {
                k1 = k2 = -1;
                j = i + 1;
            }
            if (nums[i] == minK) {
                k1 = i;
            }
            if (nums[i] == maxK) {
                k2 = i;
            }
            res += Math.max(0L, Math.min(k1, k2) - j + 1);
        }
        return res;      
    }
}