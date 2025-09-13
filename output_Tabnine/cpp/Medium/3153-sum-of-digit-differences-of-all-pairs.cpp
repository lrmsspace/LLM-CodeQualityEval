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
public:
    long long sumDigitDifferences(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int diff = 0;
                int num1 = nums[i];
                int num2 = nums[j];
                while (num1 > 0 || num2 > 0) {
                    int digit1 = num1 % 10;
                    int digit2 = num2 % 10;
                    diff += abs(digit1 - digit2);
                    num1 /= 10;
                    num2 /= 10;
                }
                sum += diff;
            }
        }
        return sum;
        
    }
};