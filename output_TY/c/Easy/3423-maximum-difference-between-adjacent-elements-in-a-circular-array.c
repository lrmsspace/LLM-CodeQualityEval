/*
 Given a circular array nums, find the maximum absolute difference between adjacent elements.
 Note: In a circular array, the first and last elements are adjacent.
 Example 1:
 Input: nums = [1,2,4]
 Output: 3
 Explanation:
 Because nums is circular, nums[0] and nums[2] are adjacent. They have the maximum absolute difference of |4 - 1| = 3.
 Example 2:
 Input: nums = [-5,-10,-5]
 Output: 5
 Explanation:
 The adjacent elements nums[0] and nums[1] have the maximum absolute difference of |-5 - (-10)| = 5.
 Constraints:
 2 <= nums.length <= 100
 -100 <= nums[i] <= 100
*/

int maxAdjacentDistance(int* nums, int numsSize) {
    int i, max = 0;

    for (i = 0; i < numsSize - 1; i++) {
        if (abs(nums[i] - nums[i + 1]) > max) {
            max = abs(nums[i] - nums[i + 1]);
        }
    }

    if (abs(nums[0] - nums[numsSize - 1]) > max) {
        max = abs(nums[0] - nums[numsSize - 1]);
    }

    return max;
    
}