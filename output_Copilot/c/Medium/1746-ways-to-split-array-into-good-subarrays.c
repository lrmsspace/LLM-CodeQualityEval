/**https://leetcode.com/problems/ways-to-split-array-into-good-subarrays/ */
//You are given a binary array nums.
//A subarray of an array is good if it contains exactly one element with the value 1.
//Return an integer denoting the number of ways to split the array nums into good subarrays. As the number may be too large, return it modulo 109 + 7.
//A subarray is a contiguous non-empty sequence of elements within an array.
// 
//Example 1:
//Input: nums = [0,1,0,0,1]
//Output: 3
//Explanation: There are 3 ways to split nums into good subarrays:
//- [0,1] [0,0,1]
//- [0,1,0] [0,1]
//- [0,1,0,0] [1]
//Example 2:
//Input: nums = [0,1,0]
//Output: 1
//Explanation: There is 1 way to split nums into good subarrays:
//- [0,1,0]
// 
//Constraints:
//	1 <= nums.length <= 105
//	0 <= nums[i] <= 1
int numberOfGoodSubarraySplits(int* nums, int numsSize) {
    int i, j, k, count, sum, mod = 1000000007;
    int *left = (int *)malloc(sizeof(int) * numsSize);
    int *right = (int *)malloc(sizeof(int) * numsSize);
    for (i = 0; i < numsSize; i++) {
        left[i] = 0;
        right[i] = 0;
    }
    count = 0;
    sum = 0;
    for (i = 0; i < numsSize; i++) {
        if (nums[i] == 1) {
            count++;
        }
        left[i] = count;
    }
    count = 0;
    for (i = numsSize - 1; i >= 0; i--) {
        if (nums[i] == 1) {
            count++;
        }
        right[i] = count;
    }
    for (i = 0; i < numsSize - 1; i++) {
        if (left[i] == 0) {
            continue;
        }
        for (j = i + 1; j < numsSize; j++) {
            if (right[j] == 0) {
                continue;
            }
            if (left[i] <= right[j]) {
                sum = (sum + 1) % mod;
            } else {
                break;
            }
        }
    }
    free(left);
    free(right);
    return sum;    
}