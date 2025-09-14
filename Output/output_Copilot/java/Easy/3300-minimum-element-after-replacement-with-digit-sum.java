/*
 You are given an integer array nums.
 You replace each element in nums with the sum of its digits.
 Return the minimum element in nums after all replacements.
 Example 1:
 Input: nums = [10,12,13,14]
 Output: 1
 Explanation:
 nums becomes [1, 3, 4, 5] after all replacements, with minimum element 1.
 Example 2:
 Input: nums = [1,2,3,4]
 Output: 1
 Explanation:
 nums becomes [1, 2, 3, 4] after all replacements, with minimum element 1.
 Example 3:
 Input: nums = [999,19,199]
 Output: 10
 Explanation:
 nums becomes [27, 10, 19] after all replacements, with minimum element 10.
 Constraints:
 1 <= nums.length <= 100
 1 <= nums[i] <= 104
*/

class Solution {
    public int minElement(int[] nums) {
        int min = Integer.MAX_VALUE;

        // Iterate through each number in the array
        for (int num : nums) {
            int digitSum = 0;

            // Calculate the sum of digits of the current number
            while (num > 0) {
                digitSum += num % 10; // Add the last digit to the sum
                num /= 10; // Remove the last digit
            }

            // Update the minimum element if the current digit sum is smaller
            if (digitSum < min) {
                min = digitSum;
            }
        }

        return min; // Return the minimum element after replacements
        
    }
}