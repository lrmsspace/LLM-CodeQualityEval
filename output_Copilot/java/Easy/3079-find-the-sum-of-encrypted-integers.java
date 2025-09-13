/*
 You are given an integer array nums containing positive integers. We define a function encrypt such that encrypt(x) replaces every digit in x with the largest digit in x. For example, encrypt(523) = 555 and encrypt(213) = 333.
 Return the sum of encrypted elements.
 Example 1:
 Input: nums = [1,2,3]
 Output: 6
 Explanation: The encrypted elements are [1,2,3]. The sum of encrypted elements is 1 + 2 + 3 == 6.
 Example 2:
 Input: nums = [10,21,31]
 Output: 66
 Explanation: The encrypted elements are [11,22,33]. The sum of encrypted elements is 11 + 22 + 33 == 66.
 Constraints:
 1 <= nums.length <= 50
 1 <= nums[i] <= 1000
*/

class Solution {
    public int sumOfEncryptedInt(int[] nums) {
        int sum = 0;

        for (int num : nums) {
            int maxDigit = 0;
            int temp = num;

            // Find the maximum digit in the number
            while (temp > 0) {
                maxDigit = Math.max(maxDigit, temp % 10);
                temp /= 10;
            }

            // Create the encrypted number by repeating the max digit
            int encryptedNum = 0;
            int multiplier = 1;
            temp = num;

            while (temp > 0) {
                encryptedNum += maxDigit * multiplier;
                multiplier *= 10;
                temp /= 10;
            }

            sum += encryptedNum;
        }

        return sum;
        
    }
}