/*
 You are given an integer array nums that represents a circular array. Your task is to create a new array result of the same size, following these rules:
 For each index i (where 0 <= i < nums.length), perform the following independent actions:
 If nums[i] > 0: Start at index i and move nums[i] steps to the right in the circular array. Set result[i] to the value of the index where you land.
 If nums[i] < 0: Start at index i and move abs(nums[i]) steps to the left in the circular array. Set result[i] to the value of the index where you land.
 If nums[i] == 0: Set result[i] to nums[i].
 Return the new array result.
 Note: Since nums is circular, moving past the last element wraps around to the beginning, and moving before the first element wraps back to the end.
 Example 1:
 Input: nums = [3,-2,1,1]
 Output: [1,1,1,3]
 Explanation:
 For nums[0] that is equal to 3, If we move 3 steps to right, we reach nums[3]. So result[0] should be 1.
 For nums[1] that is equal to -2, If we move 2 steps to left, we reach nums[3]. So result[1] should be 1.
 For nums[2] that is equal to 1, If we move 1 step to right, we reach nums[3]. So result[2] should be 1.
 For nums[3] that is equal to 1, If we move 1 step to right, we reach nums[0]. So result[3] should be 3.
 Example 2:
 Input: nums = [-1,4,-1]
 Output: [-1,-1,4]
 Explanation:
 For nums[0] that is equal to -1, If we move 1 step to left, we reach nums[2]. So result[0] should be -1.
 For nums[1] that is equal to 4, If we move 4 steps to right, we reach nums[2]. So result[1] should be -1.
 For nums[2] that is equal to -1, If we move 1 step to left, we reach nums[1]. So result[2] should be 4.
 Constraints:
 1 <= nums.length <= 100
 -100 <= nums[i] <= 100
*/

class Solution {
    public int[] constructTransformedArray(int[] nums) {
        int[] result = new int[nums.length];
        int[] left = new int[nums.length];
        int[] right = new int[nums.length];
        
        left[0] = nums[0];
        for (int i = 1; i < nums.length; i++) {
            left[i] = Math.max(left[i - 1], nums[i]);
        }
        
        right[nums.length - 1] = nums[nums.length - 1];
        for (int i = nums.length - 2; i >= 0; i--) {
            right[i] = Math.min(right[i + 1], nums[i]);
            if (nums[i] > 0) {
                result[i] = (left[i - 1] == nums[i] - 1)? i - 1 : i;
            } else if (nums[i] < 0) {
                result[i] = (right[i + 1] == Math.abs(nums[i]) - 1)? i + 1 : i;
            } else {
                result[i] = nums[i];
            }
            nums[i] = result[i];
            left[i] = Math.max(left[i - 1], nums[i]);
            right[i] = Math.min(right[i + 1], nums[i]);
            result[i] = nums[i];

            if (nums[i] > 0) {
                result[i] = (left[i - 1] == nums[i] - 1)? i - 1 : i;
            } else if (nums[i] < 0) {
                result[i] = (right[i + 1] == Math.abs(nums[i]) - 1)? i + 1 : i;
            } else {
                result[i] = nums[i];
            }
        }   
        return result;
        
    }
}