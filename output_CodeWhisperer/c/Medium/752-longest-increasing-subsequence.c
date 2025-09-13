/**https://leetcode.com/problems/longest-increasing-subsequence/ */
//Given an integer array nums, return the length of the longest strictly increasing subsequence.
// 
//Example 1:
//Input: nums = [10,9,2,5,3,7,101,18]
//Output: 4
//Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
//Example 2:
//Input: nums = [0,1,0,3,2,3]
//Output: 4
//Example 3:
//Input: nums = [7,7,7,7,7,7,7]
//Output: 1
// 
//Constraints:
//	1 <= nums.length <= 2500
//	-104 <= nums[i] <= 104
// 
//Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?
int lengthOfLIS(int* nums, int numsSize) {
    int* dp = (int*)malloc(sizeof(int) * numsSize);
    int len = 0;
    for (int i = 0; i < numsSize; i++) {
        int left = 0, right = len;
        while (left < right) {
            int mid = (left + right) / 2;
            if (dp[mid] < nums[i]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        dp[left] = nums[i];
        if (left == len) {
            len++;
        }
    }
    return len;
}