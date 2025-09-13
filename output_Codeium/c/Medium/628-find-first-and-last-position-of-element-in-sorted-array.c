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
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int* result = (int*)malloc(2 * sizeof(int));
    int left = 0;
    int right = numsSize - 1;
    int found = 0;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            found = 1;
            break;
        }
        else if (nums[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    
    if (found == 0) {
        *returnSize = 2;
        result[0] = -1;
        result[1] = -1;
        return result;
    }
    
    int first = left;
    int last = right;
    
    while (first > 0 && nums[first - 1] == target) {
        first--;
    }
    
    while (last < numsSize - 1 && nums[last + 1] == target) {
        last++;
    }
    
    *returnSize = 2;
    result[0] = first;
    result[1] = last;
    return result;
}
