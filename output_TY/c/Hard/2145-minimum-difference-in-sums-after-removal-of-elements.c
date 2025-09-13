/**https://leetcode.com/problems/minimum-difference-in-sums-after-removal-of-elements/ */
//You are given a 0-indexed integer array nums consisting of 3 * n elements.
//You are allowed to remove any subsequence of elements of size exactly n from nums. The remaining 2 * n elements will be divided into two equal parts:
//	The first n elements belonging to the first part and their sum is sumfirst.
//	The next n elements belonging to the second part and their sum is sumsecond.
//The difference in sums of the two parts is denoted as sumfirst - sumsecond.
//	For example, if sumfirst = 3 and sumsecond = 2, their difference is 1.
//	Similarly, if sumfirst = 2 and sumsecond = 3, their difference is -1.
//Return the minimum difference possible between the sums of the two parts after the removal of n elements.
// 
//Example 1:
//Input: nums = [3,1,2]
//Output: -1
//Explanation: Here, nums has 3 elements, so n = 1. 
//Thus we have to remove 1 element from nums and divide the array into two equal parts.
//- If we remove nums[0] = 3, the array will be [1,2]. The difference in sums of the two parts will be 1 - 2 = -1.
//- If we remove nums[1] = 1, the array will be [3,2]. The difference in sums of the two parts will be 3 - 2 = 1.
//- If we remove nums[2] = 2, the array will be [3,1]. The difference in sums of the two parts will be 3 - 1 = 2.
//The minimum difference between sums of the two parts is min(-1,1,2) = -1. 
//Example 2:
//Input: nums = [7,9,5,8,1,3]
//Output: 1
//Explanation: Here n = 2. So we must remove 2 elements and divide the remaining array into two parts containing two elements each.
//If we remove nums[2] = 5 and nums[3] = 8, the resultant array will be [7,9,1,3]. The difference in sums will be (7+9) - (1+3) = 12.
//To obtain the minimum difference, we should remove nums[1] = 9 and nums[4] = 1. The resultant array becomes [7,5,8,3]. The difference in sums of the two parts is (7+5) - (8+3) = 1.
//It can be shown that it is not possible to obtain a difference smaller than 1.
// 
//Constraints:
//	nums.length == 3 * n
//	1 <= n <= 105
//	1 <= nums[i] <= 105
long long minimumDifference(int* nums, int numsSize){
    int n = numsSize / 3;
    int i, j, k;
    int left[n], right[n];
    int leftSum[n], rightSum[n];
    int leftMin = 0, rightMin = 0;
    int leftMax = 0, rightMax = 0;
    int leftMinIdx = 0, rightMinIdx = 0;
    int leftMaxIdx = 0, rightMaxIdx = 0;
    int leftDiff = 0, rightDiff = 0;
    int leftDiffMin = 0, rightDiffMin = 0;
    for (i = 0; i < n; i++) {
        left[i] = nums[i];
        right[i] = nums[i + n];
    }
    for (i = 0; i < n; i++) {
        leftSum[i] = left[i];
        if (i > 0) {
            leftSum[i] += leftSum[i - 1];
        }
        if (leftSum[i] < leftMin) {
            leftMin = leftSum[i];
            leftMinIdx = i;
        }
        if (leftSum[i] > leftMax) {
            leftMax = leftSum[i];
}
rightSum[n - 1] = right[n - 1];
    }
    for (i = n - 2; i >= 0; i--) {
        rightSum[i] = rightSum[i + 1] + right[i];
        if (rightSum[i] < rightMin) {
            rightMin = rightSum[i];
            rightMinIdx = i;
        }
        if (rightSum[i] > rightMax) {
            rightMax = rightSum[i];
            rightMaxIdx =i;
        }
    }
    for (i = 0; i < n; i++) {
        leftDiff = leftSum[i] - leftMin;
        if (leftDiff < leftDiffMin) {
            leftDiffMin = leftDiff;
        }
        rightDiff = rightMax - rightSum[i];
        if (rightDiff < rightDiffMin) {
            rightDiffMin = rightDiff;
        }
    }
    return leftDiffMin + rightDiffMin;
}