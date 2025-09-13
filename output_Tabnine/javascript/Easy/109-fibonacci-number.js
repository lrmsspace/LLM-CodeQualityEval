/**https://leetcode.com/problems/fibonacci-number/ */
//The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,
//F(0) = 0, F(1) = 1
//F(n) = F(n - 1) + F(n - 2), for n > 1.
//Given n, calculate F(n).
// 
//Example 1:
//Input: n = 2
//Output: 1
//Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
//Example 2:
//Input: n = 3
//Output: 2
//Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.
//Example 3:
//Input: n = 4
//Output: 3
//Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
// 
//Constraints:
//	0 <= n <= 30
/**
 * @param {number} n
 * @return {number}
 */
var fib = function(n) {
    // If n is 0, return 0
    if (n === 0) return 0;
    
    // If n is 1, return 1
    if (n === 1) return 1;
    
    // Initialize the first two Fibonacci numbers
    let fib0 = 0;
    let fib1 = 1;
    
    // Calculate the nth Fibonacci number by iterating from 2 to n
    for (let i = 2; i <= n; i++) {
        // Update the current Fibonacci number by adding the previous two
        let fibCurrent = fib0 + fib1;
        
        // Update fib0 and fib1 for the next iteration
        fib0 = fib1;
        fib1 = fibCurrent;
    }
    
    // Return the nth Fibonacci number
    return fib1;
    
};