/**https://leetcode.com/problems/decrease-elements-to-make-array-zigzag/ */
//Given an array nums of integers, a move consists of choosing any element and decreasing it by 1.
//An array A is a zigzag array if either:
//	Every even-indexed element is greater than adjacent elements, ie. A[0] > A[1] < A[2] > A[3] < A[4] > ...
//	OR, every odd-indexed element is greater than adjacent elements, ie. A[0] < A[1] > A[2] < A[3] > A[4] < ...
//Return the minimum number of moves to transform the given array nums into a zigzag array.
// 
//Example 1:
//Input: nums = [1,2,3]
//Output: 2
//Explanation: We can decrease 2 to 0 or 3 to 1.
//Example 2:
//Input: nums = [9,6,1,6,2]
//Output: 4
// 
//Constraints:
//	1 <= nums.length <= 1000
//	1 <= nums[i] <= 1000
class Solution {
    public int movesToMakeZigzag(int[] nums) {
        int[] nums1 = new int[nums.length];
        int[] nums2 = new int[nums.length];
        int sum1 = 0;
        int sum2 = 0;
        for (int i = 0; i < nums.length; i++) {
            if (i % 2 == 0) {
                nums1[i] = nums[i] - 1;
                nums2[i] = nums[i] - 1;
            } else {
                nums1[i] = nums[i] + 1;
                nums2[i] = nums[i] + 1;
            }
       }
       for (int i = 0; i < nums.length; i++) {
           int temp = 0;
           for (int j = 0; j < nums.length; j++) {
               if (i != j) {
                   temp = Math.max(temp, Math.abs(nums1[i] - nums1[j]));
                   temp = Math.max(temp, Math.abs(nums2[i] - nums2[j]));
               }
           }
           sum1 = Math.min(sum1, temp);
           sum2 = Math.min(sum2, temp);
       }
       return Math.min(sum1, sum2);
    }
}