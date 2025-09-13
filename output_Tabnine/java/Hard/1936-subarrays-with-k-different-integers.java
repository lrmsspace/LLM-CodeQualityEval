/**https://leetcode.com/problems/subarrays-with-k-different-integers/ */
//Given an integer array nums and an integer k, return the number of good subarrays of nums.
//A good array is an array where the number of different integers in that array is exactly k.
//	For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
//A subarray is a contiguous part of an array.
// 
//Example 1:
//Input: nums = [1,2,1,2,3], k = 2
//Output: 7
//Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]
//Example 2:
//Input: nums = [1,2,1,3,4], k = 3
//Output: 3
//Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].
// 
//Constraints:
//	1 <= nums.length <= 2 * 104
//	1 <= nums[i], k <= nums.length
class Solution {
    public int subarraysWithKDistinct(int[] nums, int k) {
        int n = nums.length;
        int[] left = new int[n];
        int[] right = new int[n];
        int[] diff = new int[n];
        
        // Count the number of different integers on the left side
        left[0] = nums[0] == nums[1]? 1 : 0;
        for (int i = 1; i < n - 1; i++) {
            left[i] = nums[i] == nums[i - 1]? left[i - 1] + 1 : 0;
        }
        
        // Count the number of different integers on the right side
        right[n - 1] = nums[n - 1] == nums[n - 2]? 1 : 0;
        for (int i = n - 2; i >= 1; i--) {
            right[i] = nums[i] == nums[i + 1]? right[i + 1] + 1 : 0;
        }
        
        // Count the number of different integers between two indices
        for (int i = 0; i < n - 1; i++) {
            diff[i] = left[i] + right[i + 1];
        }
        
        // Count the number of good subarrays with exactly k different integers
        int result = 0;
        for (int i = 0; i < n - k; i++) {
            result += diff[i] == k? 1 : 0;
        }
        for (int i = n - k; i < n; i++) {
            result += diff[i] == k - 1? 1 : 0;
        }
        
        return result;
        
    }
}