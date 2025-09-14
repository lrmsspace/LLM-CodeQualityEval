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
int findUnsortedSubarray(int* nums, int numsSize) {
    int start = -1, end = -1;
    int max = nums[0], min = nums[numsSize - 1];
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < max) {
            end = i;
        } else {
            max = nums[i];
        }
        if (nums[numsSize - i - 1] > min) {
            start = numsSize - i - 1;
        } else {
            min = nums[numsSize - i - 1];
        }
    }
    return end == -1 ? 0 : end - start + 1;    
}