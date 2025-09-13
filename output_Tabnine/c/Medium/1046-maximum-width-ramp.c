/**https://leetcode.com/problems/maximum-width-ramp/ */
//A ramp in an integer array nums is a pair (i, j) for which i < j and nums[i] <= nums[j]. The width of such a ramp is j - i.
//Given an integer array nums, return the maximum width of a ramp in nums. If there is no ramp in nums, return 0.
// 
//Example 1:
//Input: nums = [6,0,8,2,1,5]
//Output: 4
//Explanation: The maximum width ramp is achieved at (i, j) = (1, 5): nums[1] = 0 and nums[5] = 5.
//Example 2:
//Input: nums = [9,8,1,0,1,9,4,0,4,1]
//Output: 7
//Explanation: The maximum width ramp is achieved at (i, j) = (2, 9): nums[2] = 1 and nums[9] = 1.
// 
//Constraints:
//	2 <= nums.length <= 5 * 104
//	0 <= nums[i] <= 5 * 104
int maxWidthRamp(int* nums, int numsSize) {
    int* right = (int*)malloc(numsSize * sizeof(int));
    int* left = (int*)malloc(numsSize * sizeof(int));
    int maxRamp = 0;
    
    // Find the rightmost smaller element on the right of each index
    right[numsSize - 1] = numsSize;
    for (int i = numsSize - 2; i >= 0; i--) {
        if (nums[i + 1] < nums[right[i + 1]]) {
            right[i] = i + 1;
        } else {
            right[i] = right[i + 1];
        }
    }
    
    // Find the leftmost smaller element on the left of each index
    left[0] = -1;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i - 1] < nums[left[i - 1]]) {
            left[i] = i - 1;
        } else {
            left[i] = left[i - 1];
        }
    }
    
    // Calculate the maximum width ramp
    for (int i = 0; i < numsSize; i++) {
        maxRamp = fmax(maxRamp, right[i] - left[i] - 1);
    }
    
    free(right);
    free(left);
    return maxRamp;
    
}