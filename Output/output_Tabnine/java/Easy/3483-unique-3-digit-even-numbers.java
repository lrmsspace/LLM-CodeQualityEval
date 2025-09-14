/*
 You are given an array of digits called digits. Your task is to determine the number of distinct three-digit even numbers that can be formed using these digits.
 Note: Each copy of a digit can only be used once per number, and there may not be leading zeros.
 Example 1:
 Input: digits = [1,2,3,4]
 Output: 12
 Explanation: The 12 distinct 3-digit even numbers that can be formed are 124, 132, 134, 142, 214, 234, 312, 314, 324, 342, 412, and 432. Note that 222 cannot be formed because there is only 1 copy of the digit 2.
 Example 2:
 Input: digits = [0,2,2]
 Output: 2
 Explanation: The only 3-digit even numbers that can be formed are 202 and 220. Note that the digit 2 can be used twice because it appears twice in the array.
 Example 3:
 Input: digits = [6,6,6]
 Output: 1
 Explanation: Only 666 can be formed.
 Example 4:
 Input: digits = [1,3,5]
 Output: 0
 Explanation: No even 3-digit numbers can be formed.
 Constraints:
 3 <= digits.length <= 10
 0 <= digits[i] <= 9
*/

class Solution {
    public int totalNumbers(int[] digits) {

        // Sort the digits array in ascending order
        Arrays.sort(digits);
        
        // Initialize variables
        int count = 0;
        int n = digits.length;
        int prev = -1;
        int curr = 0;
        int next = 0;

        // Iterate through the digits array
        for (int i = 0; i < n; i++) {
            curr = digits[i];
            // Skip duplicates
            if (curr == prev) {
                continue;
            }
            // Check if the current digit is even
            if (curr % 2 == 0) {
                // Check if the next digit is also even
                if (i + 1 < n && digits[i + 1] % 2 == 0) {
                    // Check if the next digit is greater than the current digit
                    if (digits[i + 1] > curr) {
                        count++;
                    }
                }
                // Check if the previous digit is also even
                if (i - 1 >= 0 && digits[i - 1] % 2 == 0) {
                    // Check if the previous digit is less than the current digit
                    if (digits[i - 1] < curr) {
                        count++;
                    }
                }
            }
            prev = curr;
    
            // Check if the current digit is greater than the previous digit
            if (i + 1 < n && digits[i + 1] > curr) {
                count++;
            }
        }
        return count;
        
    }
}