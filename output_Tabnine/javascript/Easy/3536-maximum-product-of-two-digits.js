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

/**
 * @param {number} n
 * @return {number}
 */
var maxProduct = function(n) {
    // Convert the number to a string for easier manipulation
    const numStr = n.toString();
    
    // Initialize variables to store the maximum and minimum products
    let maxProduct = Number.NEGATIVE_INFINITY;
    let minProduct = Number.POSITIVE_INFINITY;
    
    // Iterate through each digit in the number
    for (let i = 0; i < numStr.length; i++) {
        const digit = parseInt(numStr[i]);
        
        // Calculate the product of the current digit with the maximum and minimum products
        const productWithMax = maxProduct * digit;
        const productWithMin = minProduct * digit;
        
        // Update the maximum and minimum products
        maxProduct = Math.max(maxProduct, digit, productWithMax);
        minProduct = Math.min(minProduct, digit, productWithMin);
    }
    
    // Return the maximum product of any two digits
    return maxProduct;
    
};