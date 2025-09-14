/**https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/ */
//Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
//If target is not found in the array, return [-1, -1].
//You must write an algorithm with O(log n) runtime complexity.
// 
//Example 1:
//Input: nums = [5,7,7,8,8,10], target = 8
//Output: [3,4]
//Example 2:
//Input: nums = [5,7,7,8,8,10], target = 6
//Output: [-1,-1]
//Example 3:
//Input: nums = [], target = 0
//Output: [-1,-1]
// 
//Constraints:
//	0 <= nums.length <= 105
//	-109 <= nums[i] <= 109
//	nums is a non-decreasing array.
//	-109 <= target <= 109
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    result[0] = -1;
    result[1] = -1;
    if (numsSize == 0) {
        return result;
    }
    int left = 0;
    int right = numsSize - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            int i = mid;
            while (i >= 0 && nums[i] == target) {
                i--;
            }
            result[0] = i + 1;
            i = mid;
            while (i < numsSize && nums[i] == target) {
                i++;
            }
            result[1] = i - 1;
            return result;
        }
        else if (nums[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return result;
    
}