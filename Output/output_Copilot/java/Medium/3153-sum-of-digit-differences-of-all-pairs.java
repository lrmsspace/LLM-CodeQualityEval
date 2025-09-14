/*
 You are given an array nums consisting of positive integers where all integers have the same number of digits.
 The digit difference between two integers is the count of different digits that are in the same position in the two integers.
 Return the sum of the digit differences between all pairs of integers in nums.
 Example 1:
 Input: nums = [13,23,12]
 Output: 4
 Explanation:
 We have the following:
 - The digit difference between 13 and 23 is 1.
 - The digit difference between 13 and 12 is 1.
 - The digit difference between 23 and 12 is 2.
 So the total sum of digit differences between all pairs of integers is 1 + 1 + 2 = 4.
 Example 2:
 Input: nums = [10,10,10,10]
 Output: 0
 Explanation:
 All the integers in the array are the same. So the total sum of digit differences between all pairs of integers will be 0.
 Constraints:
 2 <= nums.length <= 105
 1 <= nums[i] < 109
 All integers in nums have the same number of digits.
*/

class Solution {
    public long sumDigitDifferences(int[] nums) {
        long totalDifference = 0;
        int n = nums.length;
        int digitCount = String.valueOf(nums[0]).length();

        for (int i = 0; i < digitCount; i++) {
            int[] digitCountArray = new int[10];
            for (int num : nums) {
                int digit = (num / (int) Math.pow(10, digitCount - i - 1)) % 10;
                digitCountArray[digit]++;
            }

            for (int j = 0; j < 10; j++) {
                for (int k = j + 1; k < 10; k++) {
                    totalDifference += digitCountArray[j] * digitCountArray[k];
                }
            }
        }

        return totalDifference * 2;        
    }
}