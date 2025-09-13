/**https://leetcode.com/problems/maximum-difference-by-remapping-a-digit/ */
//You are given an integer num. You know that Bob will sneakily remap one of the 10 possible digits (0 to 9) to another digit.
//Return the difference between the maximum and minimum values Bob can make by remapping exactly one digit in num.
//Notes:
//	When Bob remaps a digit d1 to another digit d2, Bob replaces all occurrences of d1 in num with d2.
//	Bob can remap a digit to itself, in which case num does not change.
//	Bob can remap different digits for obtaining minimum and maximum values respectively.
//	The resulting number after remapping can contain leading zeroes.
// 
//Example 1:
//Input: num = 11891
//Output: 99009
//Explanation: 
//To achieve the maximum value, Bob can remap the digit 1 to the digit 9 to yield 99899.
//To achieve the minimum value, Bob can remap the digit 1 to the digit 0, yielding 890.
//The difference between these two numbers is 99009.
//Example 2:
//Input: num = 90
//Output: 99
//Explanation:
//The maximum value that can be returned by the function is 99 (if 0 is replaced by 9) and the minimum value that can be returned by the function is 0 (if 9 is replaced by 0).
//Thus, we return 99.
// 
//Constraints:
//	1 <= num <= 108
int minMaxDifference(int num) {
    int max_val = 0;
    int min_val = 0;
    int num_digits = 0;
    
    // Count the number of digits in num
    while (num > 0) {
        num_digits++;
        num /= 10;
    }
    
    // Initialize max_val and min_val with the first digit of num
    max_val = min_val = num % 10;
    
    // Iterate over the digits of num
    for (int i = 1; i < num_digits; i++) {
        num /= 10;
        int digit = num % 10;
        
        // Update max_val and min_val if necessary
        max_val = max(max_val, digit);
        min_val = min(min_val, digit);
    }
    
    // Calculate the difference between max_val and min_val
    return max_val * 10 + min_val - num;
    
}