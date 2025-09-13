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
    int max_len = 0, count = 0;
    int* count_map = (int*)malloc(sizeof(int) * (numsSize * 2 + 1));
    memset(count_map, -1, sizeof(int) * (numsSize * 2 + 1));

    count_map[numsSize] = -1;
    for (int i = 0; i < numsSize; ++i) {
        count += nums[i] ? 1 : -1;
        if (count_map[count + numsSize] == -1) {
            count_map[count + numsSize] = i;
        }
        max_len = fmax(max_len, i - count_map[count + numsSize]);
    }
    free(count_map);

    return max_len;
}