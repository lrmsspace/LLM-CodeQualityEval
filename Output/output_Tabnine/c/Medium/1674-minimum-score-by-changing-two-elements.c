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
    int minDiff = INT_MAX, minIdx1 = -1, minIdx2 = -1;
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            int diff = abs(nums[i] - nums[j]);
            if (diff < minDiff) {
                minDiff = diff;
                minIdx1 = i;
                minIdx2 = j;
            }
        }
    }
    
    if (minIdx1 == -1 || minIdx2 == -1) return 0;
    
    int newSum = nums[minIdx1] + nums[minIdx2];
    for (int i = 0; i < numsSize; i++) {
        if (i!= minIdx1 && i!= minIdx2) {
            newSum += nums[i];
        }
    }
    
    return newSum;
    
}