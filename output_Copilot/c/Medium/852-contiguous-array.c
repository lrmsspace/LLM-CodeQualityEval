/**https://leetcode.com/problems/contiguous-array/ */
//Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.
// 
//Example 1:
//Input: nums = [0,1]
//Output: 2
//Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
//Example 2:
//Input: nums = [0,1,0]
//Output: 2
//Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
// 
//Constraints:
//	1 <= nums.length <= 105
//	nums[i] is either 0 or 1.
int findMaxLength(int* nums, int numsSize) {
    int *sum = (int *)malloc(sizeof(int) * (2 * numsSize + 1));
    for (int i = 0; i < 2 * numsSize + 1; i++) {
        sum[i] = -2;
    }
    sum[numsSize] = -1;
    int count = 0, max = 0;
    for (int i = 0; i < numsSize; i++) {
        count += nums[i] == 0 ? -1 : 1;
        if (sum[count + numsSize] == -2) {
            sum[count + numsSize] = i;
        } else {
            max = max > i - sum[count + numsSize] ? max : i - sum[count + numsSize];
        }
    }
    return max;    
}