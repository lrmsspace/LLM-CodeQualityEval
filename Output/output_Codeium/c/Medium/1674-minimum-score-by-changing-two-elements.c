/**https://leetcode.com/problems/minimum-score-by-changing-two-elements/ */
//You are given an integer array nums.
//	The low score of nums is the minimum absolute difference between any two integers.
//	The high score of nums is the maximum absolute difference between any two integers.
//	The score of nums is the sum of the high and low scores.
//Return the minimum score after changing two elements of nums.
// 
//Example 1:
//Input: nums = [1,4,7,8,5]
//Output: 3
//Explanation:
//	Change nums[0] and nums[1] to be 6 so that nums becomes [6,6,7,8,5].
//	The low score is the minimum absolute difference: |6 - 6| = 0.
//	The high score is the maximum absolute difference: |8 - 5| = 3.
//	The sum of high and low score is 3.
//Example 2:
//Input: nums = [1,4,3]
//Output: 0
//Explanation:
//	Change nums[1] and nums[2] to 1 so that nums becomes [1,1,1].
//	The sum of maximum absolute difference and minimum absolute difference is 0.
// 
//Constraints:
//	3 <= nums.length <= 105
//	1 <= nums[i] <= 109
int minimizeSum(int* nums, int numsSize) {
    int min1 = INT_MAX, min2 = INT_MAX, max1 = INT_MIN, max2 = INT_MIN;
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] < min1) {
            min2 = min1;
            min1 = nums[i];
        }
        else if (nums[i] < min2) {
            min2 = nums[i];
        }
        if (nums[i] > max1) {
            max2 = max1;
            max1 = nums[i];
        }
        else if (nums[i] > max2) {
            max2 = nums[i];
        }
    }
    return fmin(max2 - min2, max1 - min1);
}