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

class Solution {
    public int maxProduct(int n) {
        // Convert the integer to a string to access individual digits
        String strN = String.valueOf(n);
        
        // Initialize variables to store the maximum and minimum product
        int maxProduct = 0;
        
        // Iterate through each digit in the string representation of n
        for (int i = 0; i < strN.length(); i++) {
            // Convert the current digit to an integer
            int digit = strN.charAt(i) - '0';
            
            // Calculate the product of the current digit with the maximum and minimum products
            int productWithMax = maxProduct * digit;
            int productWithMin = minProduct * digit;
            
            // Update the maximum and minimum products
            maxProduct = Math.max(productWithMax, productWithMin);
            minProduct = Math.min(productWithMax, productWithMin);
        }
        
        // Return the maximum product
        return maxProduct;
        
    }
}