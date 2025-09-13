/**https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/ */
//You are given an integer array nums of 2 * n integers. You need to partition nums into two arrays of length n to minimize the absolute difference of the sums of the arrays. To partition nums, put each element of nums into one of the two arrays.
//Return the minimum possible absolute difference.
// 
//Example 1:
//Input: nums = [3,9,7,3]
//Output: 2
//Explanation: One optimal partition is: [3,9] and [7,3].
//The absolute difference between the sums of the arrays is abs((3 + 9) - (7 + 3)) = 2.
//Example 2:
//Input: nums = [-36,36]
//Output: 72
//Explanation: One optimal partition is: [-36] and [36].
//The absolute difference between the sums of the arrays is abs((-36) - (36)) = 72.
//Example 3:
//Input: nums = [2,-1,0,4,-2,-9]
//Output: 0
//Explanation: One optimal partition is: [2,4,-9] and [-1,0,-2].
//The absolute difference between the sums of the arrays is abs((2 + 4 + -9) - (-1 + 0 + -2)) = 0.
// 
//Constraints:
//	1 <= n <= 15
//	nums.length == 2 * n
//	-107 <= nums[i] <= 107
int minimumDifference(int* nums, int numsSize) {
    int n = numsSize / 2;
    int* left = (int*)malloc(sizeof(int) * (1 << n));
    int* right = (int*)malloc(sizeof(int) * (1 << n));
    int leftSize = 0, rightSize = 0;
    for (int i = 0; i < (1 << n); i++) {
        int leftSum = 0, rightSum = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                leftSum += nums[j];
                rightSum += nums[j + n];
            }
        }
        left[leftSize++] = leftSum;
        right[rightSize++] = rightSum;
    }
    int result = INT_MAX;
    for (int i = 0; i < (1 << n); i++) {
        int leftSum = left[i];
        int rightSum = right[i];
        int diff = abs(leftSum - rightSum);
        if (diff < result) {
            result = diff;
        }
        for (int j = i + 1; j < (1 << n); j++) {
            int leftSum2 = left[j];
            int rightSum2 = right[j];
            int diff2 = abs(leftSum2 - rightSum2);
            if (diff2 < result) {
                result = diff2;
            }
        }
    }
    free(left);
    free(right);
    return result;
}