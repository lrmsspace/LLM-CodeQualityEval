/**https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/ */
//You are given a 0-indexed array nums consisting of positive integers. You can choose two indices i and j, such that i != j, and the sum of digits of the number nums[i] is equal to that of nums[j].
//Return the maximum value of nums[i] + nums[j] that you can obtain over all possible indices i and j that satisfy the conditions.
// 
//Example 1:
//Input: nums = [18,43,36,13,7]
//Output: 54
//Explanation: The pairs (i, j) that satisfy the conditions are:
//- (0, 2), both numbers have a sum of digits equal to 9, and their sum is 18 + 36 = 54.
//- (1, 4), both numbers have a sum of digits equal to 7, and their sum is 43 + 7 = 50.
//So the maximum sum that we can obtain is 54.
//Example 2:
//Input: nums = [10,12,19,14]
//Output: -1
//Explanation: There are no two numbers that satisfy the conditions, so we return -1.
// 
//Constraints:
//	1 <= nums.length <= 105
//	1 <= nums[i] <= 109
int maximumSum(int* nums, int numsSize){
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, a, b, c, d, e, f,g, h, i, j, k, l, m, n,
         max_sum = 0;
         for (i = 0; i < numsSize; i++) {
             for (j = i + 1; j < numsSize; j++) {
                 int sum = nums[i] + nums[j];
                 int sum_digits = 0;
                 while (sum > 0) {
                     sum_digits += sum % 10;
                     sum /= 10;
                 }
                if (sum_digits == 7) {
                    max_sum = max(max_sum, nums[i] + nums[j]);
                }
             }
         }
         return max_sum;
}   