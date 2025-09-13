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
int findUnsortedSubarray(int* nums, int numsSize){
    int i, j, min, max;
    for (i = 0; i < numsSize - 1; i++) {
        if (nums[i] > nums[i + 1]) {
            break;
        }
    }
    if (i == numsSize - 1) {
        return 0;
    }
    for (j = numsSize - 1; j > 0; j--) {
        if (nums[j] < nums[j - 1]) {
            break;
        }
    }
    min = nums[i];
    max = nums[i];
    for (i; i <= j; i++) {
        if (nums[i] < min) {
            min = nums[i];
        }
        if (nums[i] > max) {
            max = nums[i];
        }
    }
    for (i = 0; i < numsSize; i++) {
        if (nums[i] > min) {
            break;
        }
    }
    for (j = numsSize - 1; j >= 0; j--) {
        if (nums[j] < max) {
            break;
        }
    }
    return j - i + 1;
}