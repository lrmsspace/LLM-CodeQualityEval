/**https://leetcode.com/problems/reverse-subarray-to-maximize-array-value/ */
//You are given an integer array nums. The value of this array is defined as the sum of |nums[i] - nums[i + 1]| for all 0 <= i < nums.length - 1.
//You are allowed to select any subarray of the given array and reverse it. You can perform this operation only once.
//Find maximum possible value of the final array.
// 
//Example 1:
//Input: nums = [2,3,1,5,4]
//Output: 10
//Explanation: By reversing the subarray [3,1,5] the array becomes [2,5,1,3,4] whose value is 10.
//Example 2:
//Input: nums = [2,4,9,24,2,1,10]
//Output: 68
// 
//Constraints:
//	2 <= nums.length <= 3 * 104
//	-105 <= nums[i] <= 105
//	The answer is guaranteed to fit in a 32-bit integer.
int maxValueAfterReverse(int* nums, int numsSize) {
    int sum = 0;
    for (int i = 0; i < numsSize - 1; i++) {
        sum += abs(nums[i] - nums[i + 1]);
    }
    int result = sum;
    int max1 = INT_MIN, min1 = INT_MAX, max2 = INT_MIN, min2 = INT_MAX;
    for (int i = 0; i < numsSize - 1; i++) {
        max1 = fmax(max1, fmin(nums[i], nums[i + 1]));
        min1 = fmin(min1, fmax(nums[i], nums[i + 1]));
    }
    for (int i = 0; i < numsSize - 1; i++) {
        max2 = fmax(max2, fmax(nums[i], nums[i + 1]));
        min2 = fmin(min2, fmin(nums[i], nums[i + 1]));
    }
    result = fmax(result, 2 * (fmax(max1, max2) - fmin(min1, min2)));
    for (int i = 1; i < numsSize - 1; i++) {
        result = fmax(result, abs(nums[0] - nums[i + 1]) - abs(nums[i] - nums[i + 1]));
        result = fmax(result, abs(nums[numsSize - 1] - nums[i - 1]) - abs(nums[i] - nums[i - 1]));
    }
    return result;    
}