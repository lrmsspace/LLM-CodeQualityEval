/**https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/ */
//You may recall that an array arr is a mountain array if and only if:
//	arr.length >= 3
//	There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
//	
//		arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
//		arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
//	
//	
//Given an integer array nums​​​, return the minimum number of elements to remove to make nums​​​ a mountain array.
// 
//Example 1:
//Input: nums = [1,3,1]
//Output: 0
//Explanation: The array itself is a mountain array so we do not need to remove any elements.
//Example 2:
//Input: nums = [2,1,1,5,6,2,3,1]
//Output: 3
//Explanation: One solution is to remove the elements at indices 0, 1, and 5, making the array nums = [1,5,6,3,1].
// 
//Constraints:
//	3 <= nums.length <= 1000
//	1 <= nums[i] <= 109
//	It is guaranteed that you can make a mountain array out of nums.
int minimumMountainRemovals(int* nums, int numsSize) {

    int* dp = (int*)malloc(sizeof(int) * numsSize);
    int* dp2 = (int*)malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        dp[i] = 1;
        dp2[i] = 1;
    }
    for (int i = 1; i < numsSize; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = fmax(dp[i], dp[j] + 1);
            }
        }
    }
    for (int i = numsSize - 2; i >= 0; i--) {
        for (int j = numsSize - 1; j > i; j--) {
            if (nums[i] > nums[j]) {
                dp2[i] = fmax(dp2[i], dp2[j] + 1);
            }
        }
    }
    int max = 0;
    for (int i = 1; i < numsSize - 1; i++) {
        if (dp[i] > 1 && dp2[i] > 1) {
            max = fmax(max, dp[i] + dp2[i] - 1);
        }
    }
    free(dp);
    free(dp2);
    return numsSize - max;
}