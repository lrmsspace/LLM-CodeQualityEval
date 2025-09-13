/**https://leetcode.com/problems/consecutive-numbers-sum/ */
//Given an integer n, return the number of ways you can write n as the sum of consecutive positive integers.
// 
//Example 1:
//Input: n = 5
//Output: 2
//Explanation: 5 = 2 + 3
//Example 2:
//Input: n = 9
//Output: 3
//Explanation: 9 = 4 + 5 = 2 + 3 + 4
//Example 3:
//Input: n = 15
//Output: 4
//Explanation: 15 = 8 + 7 = 4 + 5 + 6 = 1 + 2 + 3 + 4 + 5
// 
//Constraints:
//	1 <= n <= 109
/**
 * @param {number} n
 * @return {number}
 */
var consecutiveNumbersSum = function(n) {
    // Base case: if n is less than 4, there are no valid combinations
    if (n < 4) return 0;
    
    // Initialize the count of valid combinations
    let count = 0;
    
    // Iterate through all possible lengths for the first number
    for (let i = 1; i <= Math.floor(Math.sqrt(n)); i++) {
        // Calculate the remaining sum after subtracting the first number
        let remainingSum = n - i * (i + 1) / 2;
        
        // If the remaining sum is a perfect square, increment the count
        if (remainingSum >= 0 && Math.sqrt(remainingSum) % 1 === 0) {
            count++;
        }
    }
    
    return count;
    
};