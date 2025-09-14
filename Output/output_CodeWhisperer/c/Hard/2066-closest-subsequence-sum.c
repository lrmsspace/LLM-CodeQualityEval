/**https://leetcode.com/problems/closest-subsequence-sum/ */
//You are given an integer array nums and an integer goal.
//You want to choose a subsequence of nums such that the sum of its elements is the closest possible to goal. That is, if the sum of the subsequence's elements is sum, then you want to minimize the absolute difference abs(sum - goal).
//Return the minimum possible value of abs(sum - goal).
//Note that a subsequence of an array is an array formed by removing some elements (possibly all or none) of the original array.
// 
//Example 1:
//Input: nums = [5,-7,3,5], goal = 6
//Output: 0
//Explanation: Choose the whole array as a subsequence, with a sum of 6.
//This is equal to the goal, so the absolute difference is 0.
//Example 2:
//Input: nums = [7,-9,15,-2], goal = -5
//Output: 1
//Explanation: Choose the subsequence [7,-9,-2], with a sum of -4.
//The absolute difference is abs(-4 - (-5)) = abs(1) = 1, which is the minimum.
//Example 3:
//Input: nums = [1,2,3], goal = -7
//Output: 7
// 
//Constraints:
//	1 <= nums.length <= 40
//	-107 <= nums[i] <= 107
//	-109 <= goal <= 109
int minAbsDifference(int* nums, int numsSize, int goal) {

    int n = numsSize;
    int* sum1 = (int*)malloc(sizeof(int) * (1 << (n / 2)));
    int* sum2 = (int*)malloc(sizeof(int) * (1 << (n - n / 2)));
    int sum1Size = 0;
    int sum2Size = 0;
    for (int i = 0; i < (1 << (n / 2)); i++) {
        int sum = 0;
        for (int j = 0; j < n / 2; j++) {
            if (i & (1 << j)) {
                sum += nums[j];
            }
        }
        sum1[sum1Size++] = sum;
    }
    for (int i = 0; i < (1 << (n - n / 2)); i++) {
        int sum = 0;
        for (int j = 0; j < n - n / 2; j++) {
            if (i & (1 << j)) {
                sum += nums[n / 2 + j];
            }
        }
        sum2[sum2Size++] = sum;
    }
    int minDiff = INT_MAX;
    for (int i = 0; i < sum1Size; i++) {
        int left = 0, right = sum2Size - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int sum = sum1[i] + sum2[mid];
            if (sum == goal) {
                return 0;
            }
            if (sum < goal) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        int diff1 = INT_MAX, diff2 = INT_MAX;
        if (left < sum2Size) {
            diff1 = abs(sum1[i] + sum2[left] - goal);
        }
        if (right >= 0) {
            diff2 = abs(sum1[i] + sum2[right] - goal);
        }
        minDiff = fmin(minDiff, fmin(diff1, diff2));
    }
    return minDiff;
}