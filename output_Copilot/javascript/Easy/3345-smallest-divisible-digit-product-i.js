/*
 You are given two integers n and t. Return the smallest number greater than or equal to n such that the product of its digits is divisible by t.
 Example 1:
 Input: n = 10, t = 2
 Output: 10
 Explanation:
 The digit product of 10 is 0, which is divisible by 2, making it the smallest number greater than or equal to 10 that satisfies the condition.
 Example 2:
 Input: n = 15, t = 3
 Output: 16
 Explanation:
 The digit product of 16 is 6, which is divisible by 3, making it the smallest number greater than or equal to 15 that satisfies the condition.
 Constraints:
 1 <= n <= 100
 1 <= t <= 10
*/

/**
 * @param {number} n
 * @param {number} t
 * @return {number}
 */
var smallestNumber = function(n, t) {
    if (t === 0) {
        return n <= 10 ? 10 : -1; // If t is 0, the smallest number is 10 or -1 if n > 10
    }
    
    while (true) {
        let product = 1;
        let num = n;
        
        // Calculate the product of digits of n
        while (num > 0) {
            product *= num % 10;
            num = Math.floor(num / 10);
        }
        
        // Check if the product is divisible by t
        if (product % t === 0) {
            return n; // Return the current number if condition is satisfied
        }
        
        n++; // Increment n to check the next number
    }
    
};