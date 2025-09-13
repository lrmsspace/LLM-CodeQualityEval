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
class Solution {
    public int maximumSum(int[] nums) {
        int maxSum = -1;
        int n = nums.length;
        
        // Count the frequency of digits in each number
        int[][] digitCount = new int[n][10];
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            while (num > 0) {
                digitCount[i][num % 10]++;
                num /= 10;
            }
        }
        
        // Iterate through all possible pairs of indices
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int sum1 = 0, sum2 = 0;
                // Calculate the sum of digits for both numbers
                for (int digit = 0; digit < 10; digit++) {
                    sum1 += digit * digitCount[i][digit];
                    sum2 += digit * digitCount[j][digit];
                }
                // Check if the sums of digits are equal
                if (sum1 == sum2) {
                    maxSum = Math.max(maxSum, nums[i] + nums[j]);
                }
            }
        }
        
        return maxSum;
        
    }
}