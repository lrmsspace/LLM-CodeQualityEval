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
    int start = -1, end = -1, min_val = INT_MAX, max_val = INT_MIN;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < min_val) {
            min_val = nums[i];
            if (start == -1) start = i;
        }
        if (nums[i] > max_val) {
            max_val = nums[i];
            end = i;
        }
    }
    if (start == -1) return 0;
    int left = start, right = end;
    for (int i = 0; i < start; i++) {
        if (nums[i] > min_val) {
            left = i;
            break;
        }
    }
    for (int i = end; i < numsSize; i++) {
        if (nums[i] < max_val) {
            right = i;
            break;
        }
    }
    return right - left + 1;
}