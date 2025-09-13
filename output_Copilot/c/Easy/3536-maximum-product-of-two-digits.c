/*
 You are given a positive integer n.
 Return the maximum product of any two digits in n.
 Note: You may use the same digit twice if it appears more than once in n.
 Example 1:
 Input: n = 31
 Output: 3
 Explanation:
 The digits of n are [3, 1].
 The possible products of any two digits are: 3 * 1 = 3.
 The maximum product is 3.
 Example 2:
 Input: n = 22
 Output: 4
 Explanation:
 The digits of n are [2, 2].
 The possible products of any two digits are: 2 * 2 = 4.
 The maximum product is 4.
 Example 3:
 Input: n = 124
 Output: 8
 Explanation:
 The digits of n are [1, 2, 4].
 The possible products of any two digits are: 1 * 2 = 2, 1 * 4 = 4, 2 * 4 = 8.
 The maximum product is 8.
 Constraints:
 10 <= n <= 109
*/

int maxProduct(int n) {
    int max1 = 0, max2 = 0;

    // Find the two largest digits in n
    while (n > 0) {
        int digit = n % 10;
        if (digit > max1) {
            max2 = max1; // Update second largest
            max1 = digit; // Update largest
        } else if (digit > max2) {
            max2 = digit; // Update second largest
        }
        n /= 10; // Remove the last digit
    }

    return max1 * max2; // Return the product of the two largest digits
    
}