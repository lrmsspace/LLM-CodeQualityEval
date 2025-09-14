/**https://leetcode.com/problems/smallest-integer-divisible-by-k/ */
//Given a positive integer k, you need to find the length of the smallest positive integer n such that n is divisible by k, and n only contains the digit 1.
//Return the length of n. If there is no such n, return -1.
//Note: n may not fit in a 64-bit signed integer.
// 
//Example 1:
//Input: k = 1
//Output: 1
//Explanation: The smallest answer is n = 1, which has length 1.
//Example 2:
//Input: k = 2
//Output: -1
//Explanation: There is no such positive integer n divisible by 2.
//Example 3:
//Input: k = 3
//Output: 3
//Explanation: The smallest answer is n = 111, which has length 3.
// 
//Constraints:
//	1 <= k <= 105
/**
 * @param {number} k
 * @return {number}
 */
var smallestRepunitDivByK = function(k) {
    // Create a list to store the digits of the current number
    let digits = [];
    
    // Initialize the current number to 1
    let current = 1;
    
    // Loop until the current number is divisible by k
    while (current % k!== 0) {
        // Append the last digit of the current number to the list
        digits.push(current % 10);
        
        // Calculate the next number by appending the last digit and the sum of the digits
        current = (current % 10) * 10 + (digits.reduce((acc, curr) => acc + curr, 0) % k);
    }
    
    // If the current number is divisible by k, return the length of the digits
    return digits.length;
    
};