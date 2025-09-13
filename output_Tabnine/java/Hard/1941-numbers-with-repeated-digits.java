/**https://leetcode.com/problems/numbers-with-repeated-digits/ */
//Given an integer n, return the number of positive integers in the range [1, n] that have at least one repeated digit.
// 
//Example 1:
//Input: n = 20
//Output: 1
//Explanation: The only positive number (<= 20) with at least 1 repeated digit is 11.
//Example 2:
//Input: n = 100
//Output: 10
//Explanation: The positive numbers (<= 100) with atleast 1 repeated digit are 11, 22, 33, 44, 55, 66, 77, 88, 99, and 100.
//Example 3:
//Input: n = 1000
//Output: 262
// 
//Constraints:
//	1 <= n <= 109
class Solution {
    public int numDupDigitsAtMostN(int n) {
        // Initialize count for numbers with at least one repeated digit
        int count = 0;
        
        // Convert n to string for easier manipulation
        String numStr = String.valueOf(n);
        
        // Iterate through each digit in the number
        for (int i = 0; i < numStr.length(); i++) {
            // Get the current digit
            int digit = numStr.charAt(i) - '0';
            
            // Count the number of numbers less than or equal to n with the current digit repeated
            int lessThanOrEqualToN = count + (i == 0? 0 : getCount(numStr, i - 1, digit));
            
            // Count the number of numbers greater than n with the current digit repeated
            int greaterThanN = getCount(numStr, i, digit);
            
            // Update the count for numbers with at least one repeated digit
            count += lessThanOrEqualToN + greaterThanN;
        }
        
        // Return the count of numbers with at least one repeated digit
        return count;
        
    }
}