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
    int m = 1 << n;
    int sum1[m];
    int sum2[m];
    for (int i = 0; i < m; i++) {
        sum1[i] = 0;
        sum2[i] = 0;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1) {
                sum1[i] += nums[j];
                sum2[i] += nums[j + n];
            } else {
                sum1[i] += nums[j + n];
                sum2[i] += nums[j];
            }
        }
    }
    int s = 0;
    for (int i = 0; i < n; i++) {
        s += nums[i];
    }
    int res = INT_MAX;
    for (int i = 0; i < m; i++) {
        res = fmin(res, fabs(sum1[i] - s));
    }
    return res;    
}