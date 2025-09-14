/**https://leetcode.com/problems/subarray-with-elements-greater-than-varying-threshold/ */
//You are given an integer array nums and an integer threshold.
//Find any subarray of nums of length k such that every element in the subarray is greater than threshold / k.
//Return the size of any such subarray. If there is no such subarray, return -1.
//A subarray is a contiguous non-empty sequence of elements within an array.
// 
//Example 1:
//Input: nums = [1,3,4,3,1], threshold = 6
//Output: 3
//Explanation: The subarray [3,4,3] has a size of 3, and every element is greater than 6 / 3 = 2.
//Note that this is the only valid subarray.
//Example 2:
//Input: nums = [6,5,6,5,8], threshold = 7
//Output: 1
//Explanation: The subarray [8] has a size of 1, and 8 > 7 / 1 = 7. So 1 is returned.
//Note that the subarray [6,5] has a size of 2, and every element is greater than 7 / 2 = 3.5. 
//Similarly, the subarrays [6,5,6], [6,5,6,5], [6,5,6,5,8] also satisfy the given conditions.
//Therefore, 2, 3, 4, or 5 may also be returned.
// 
//Constraints:
//	1 <= nums.length <= 105
//	1 <= nums[i], threshold <= 109
int validSubarraySize(int* nums, int numsSize, int threshold) {
    int* stack = (int*)malloc(sizeof(int) * numsSize);
    int stackSize = 0;
    int* left = (int*)malloc(sizeof(int) * numsSize);
    int* right = (int*)malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        while (stackSize > 0 && nums[stack[stackSize - 1]] >= nums[i]) {
            stackSize--;
        }
        left[i] = stackSize > 0 ? stack[stackSize - 1] : -1;
        stack[stackSize++] = i;
    }
    stackSize = 0;
    for (int i = numsSize - 1; i >= 0; i--) {
        while (stackSize > 0 && nums[stack[stackSize - 1]] >= nums[i]) {
            stackSize--;
        }
        right[i] = stackSize > 0 ? stack[stackSize - 1] : numsSize;
        stack[stackSize++] = i;
    }
    for (int i = 0; i < numsSize; i++) {
        int k = right[i] - left[i] - 1;
        if (nums[i] > threshold / k) {
            return k;
        }
    }
    return -1;
}