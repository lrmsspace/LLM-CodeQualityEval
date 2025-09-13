/**https://leetcode.com/problems/wiggle-sort-ii/ */
//Given an integer array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....
//You may assume the input array always has a valid answer.
// 
//Example 1:
//Input: nums = [1,5,1,1,6,4]
//Output: [1,6,1,5,1,4]
//Explanation: [1,4,1,5,1,6] is also accepted.
//Example 2:
//Input: nums = [1,3,2,2,3,1]
//Output: [2,3,1,3,1,2]
// 
//Constraints:
//	1 <= nums.length <= 5 * 104
//	0 <= nums[i] <= 5000
//	It is guaranteed that there will be an answer for the given input nums.
// 
//Follow Up: Can you do it in O(n) time and/or in-place with O(1) extra space?
class Solution {
    public void wiggleSort(int[] nums) {
        int n = nums.length;
        // First, sort the array
        Arrays.sort(nums);
        
        // Then, divide the array into two halves
        int mid = (n + 1) / 2;
        int[] left = new int[mid];
        int[] right = new int[n - mid];
        System.arraycopy(nums, 0, left, 0, mid);
        System.arraycopy(nums, mid, right, 0, n - mid);
        
        // Then, rearrange the array
        int i = 0, j = n - 1, k = 0;
        while (k < n) {
            if (k % 2 == 0) {
                nums[k] = left[i++];
            } else {
                nums[k] = right[j--];
            }
            k++;
        }
        
        // Finally, reverse the array to make it wiggly
        int leftBound = (n + 1) / 2 - 1;
        int rightBound = n - 1;
        while (leftBound >= 0 && rightBound >= leftBound) {
            swap(nums, leftBound, rightBound);
            leftBound--;
            rightBound--;
        }
        
        // Helper function to swap two elements in the array
        void swap(int[] nums, int i, int j) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }
}