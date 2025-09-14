/**https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/ */
//Given an integer array nums and two integers firstLen and secondLen, return the maximum sum of elements in two non-overlapping subarrays with lengths firstLen and secondLen.
//The array with length firstLen could occur before or after the array with length secondLen, but they have to be non-overlapping.
//A subarray is a contiguous part of an array.
// 
//Example 1:
//Input: nums = [0,6,5,2,2,5,1,9,4], firstLen = 1, secondLen = 2
//Output: 20
//Explanation: One choice of subarrays is [9] with length 1, and [6,5] with length 2.
//Example 2:
//Input: nums = [3,8,1,3,2,1,8,9,0], firstLen = 3, secondLen = 2
//Output: 29
//Explanation: One choice of subarrays is [3,8,1] with length 3, and [8,9] with length 2.
//Example 3:
//Input: nums = [2,1,5,6,0,9,5,0,3,8], firstLen = 4, secondLen = 3
//Output: 31
//Explanation: One choice of subarrays is [5,6,0,9] with length 4, and [0,3,8] with length 3.
// 
//Constraints:
//	1 <= firstLen, secondLen <= 1000
//	2 <= firstLen + secondLen <= 1000
//	firstLen + secondLen <= nums.length <= 1000
//	0 <= nums[i] <= 1000
class Solution {
    public int maxSumTwoNoOverlap(int[] nums, int firstLen, int secondLen) {
        int n = nums.length;
        int[] prefixSum = new int[n + 1];
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        int firstMax = 0;
        int secondMax = 0;
        for (int i = 0; i < n - firstLen + 1; i++) {
            int sum = prefixSum[i + firstLen] - prefixSum[i];
            if (sum > firstMax) {
                firstMax = sum;
                int j = i + firstLen;
                while (j < n - secondLen + 1) {
                    int sum2 = prefixSum[j + secondLen] - prefixSum[j];
                    secondMax = Math.max(secondMax, sum2);
                    j++;
                }
            }
        }
        int max = 0;
        for (int i = 0; i < n - secondLen + 1; i++) {
            int sum = prefixSum[i + secondLen] - prefixSum[i];
            if (sum > secondMax) {
                secondMax = sum;
                int j = i + secondLen;
                while (j < n - firstLen + 1) {
                    int sum2 = prefixSum[j + firstLen] - prefixSum[j];
                    firstMax = Math.max(firstMax, sum2);
                    j++;
                }
            }
        }
        max = Math.max(max, firstMax + secondMax);
        return max;
    }
}