/**https://leetcode.com/problems/longest-harmonious-subsequence/ */
//We define a harmonious array as an array where the difference between its maximum value and its minimum value is exactly 1.
//Given an integer array nums, return the length of its longest harmonious subsequence among all its possible subsequences.
// 
//Example 1:
//Input: nums = [1,3,2,2,5,2,3,7]
//Output: 5
//Explanation:
//The longest harmonious subsequence is [3,2,2,2,3].
//Example 2:
//Input: nums = [1,2,3,4]
//Output: 2
//Explanation:
//The longest harmonious subsequences are [1,2], [2,3], and [3,4], all of which have a length of 2.
//Example 3:
//Input: nums = [1,1,1,1]
//Output: 0
//Explanation:
//No harmonic subsequence exists.
// 
//Constraints:
//	1 <= nums.length <= 2 * 104
//	-109 <= nums[i] <= 109
int findLHS(int* nums, int numsSize) {
    int count[20001] = {0};
    int maxCount = 0;
    for (int i = 0; i < numsSize; i++) {
        count[nums[i] + 10000]++;
        maxCount = fmax(maxCount, count[nums[i] + 10000]);
    }
    int longestHarmoniousSubsequence = 0;
    for (int i = 0; i < 20001; i++) {
        if (count[i] > 0 && count[i + 1] > 0) {
            longestHarmoniousSubsequence = fmax(longestHarmoniousSubsequence, count[i] + count[i + 1]);
        }
    }
    return longestHarmoniousSubsequence;
}