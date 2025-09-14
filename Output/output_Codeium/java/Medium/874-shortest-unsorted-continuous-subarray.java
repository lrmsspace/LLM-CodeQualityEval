/**https://leetcode.com/problems/shortest-unsorted-continuous-subarray/ */
//Given an integer array nums, you need to find one continuous subarray such that if you only sort this subarray in non-decreasing order, then the whole array will be sorted in non-decreasing order.
//Return the shortest such subarray and output its length.
// 
//Example 1:
//Input: nums = [2,6,4,8,10,9,15]
//Output: 5
//Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
//Example 2:
//Input: nums = [1,2,3,4]
//Output: 0
//Example 3:
//Input: nums = [1]
//Output: 0
// 
//Constraints:
//	1 <= nums.length <= 104
//	-105 <= nums[i] <= 105
// 
//Follow up: Can you solve it in O(n) time complexity?
class Solution {
    public int findUnsortedSubarray(int[] nums) {
        int start = 0, end = nums.length - 1;
        while (start < end && nums[start] <= nums[start + 1]) start++;
        while (start < end && nums[end] >= nums[end - 1]) end--;
        if (end - start <= 0) return 0;
        int min = Integer.MAX_VALUE, max = Integer.MIN_VALUE;
        for (int i = start; i <= end; i++) {
            min = Math.min(min, nums[i]);
            max = Math.max(max, nums[i]);
        }
        while (start > 0 && nums[start - 1] > min) start--;
        while (end < nums.length - 1 && nums[end + 1] < max) end++;
        return end - start + 1;
    }
}