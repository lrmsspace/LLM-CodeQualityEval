/**https://leetcode.com/problems/maximum-subarray-min-product/ */
//The min-product of an array is equal to the minimum value in the array multiplied by the array's sum.
//	For example, the array [3,2,5] (minimum value is 2) has a min-product of 2 * (3+2+5) = 2 * 10 = 20.
//Given an array of integers nums, return the maximum min-product of any non-empty subarray of nums. Since the answer may be large, return it modulo 109 + 7.
//Note that the min-product should be maximized before performing the modulo operation. Testcases are generated such that the maximum min-product without modulo will fit in a 64-bit signed integer.
//A subarray is a contiguous part of an array.
// 
//Example 1:
//Input: nums = [1,2,3,2]
//Output: 14
//Explanation: The maximum min-product is achieved with the subarray [2,3,2] (minimum value is 2).
//2 * (2+3+2) = 2 * 7 = 14.
//Example 2:
//Input: nums = [2,3,3,1,2]
//Output: 18
//Explanation: The maximum min-product is achieved with the subarray [3,3] (minimum value is 3).
//3 * (3+3) = 3 * 6 = 18.
//Example 3:
//Input: nums = [3,1,5,6,4,2]
//Output: 60
//Explanation: The maximum min-product is achieved with the subarray [5,6,4] (minimum value is 4).
//4 * (5+6+4) = 4 * 15 = 60.
// 
//Constraints:
//	1 <= nums.length <= 105
//	1 <= nums[i] <= 107
int maxSumMinProduct(int* nums, int numsSize) {
    long long int mod = 1000000007;
    long long int sum[numsSize+1];
    long long int left[numsSize+1];
    long long int right[numsSize+1];
    long long int stack[numsSize+1];
    long long int top = -1;
    long long int ans = 0;
    sum[0] = 0;
    for (int i = 1; i <= numsSize; i++) {
        sum[i] = sum[i-1] + nums[i-1];
    }
    for (int i = 1; i <= numsSize; i++) {
        left[i] = i;
        while (top != -1 && nums[stack[top]] >= nums[i-1]) {
            left[i] = left[stack[top]];
            top--;
        }
        stack[++top] = i-1;
    }
    top = -1;
    for (int i = numsSize; i >= 1; i--) {
        right[i] = numsSize - i + 1;
        while (top != -1 && nums[stack[top]] >= nums[i-1]) {
            right[i] = right[stack[top]];
            top--;
        }
        stack[++top] = i-1;
    }
    for (int i = 1; i <= numsSize; i++) {
        ans = fmax(ans, nums[i-1] * (sum[right[i]] - sum[left[i]-1]));
    }
    return ans % mod;    
}