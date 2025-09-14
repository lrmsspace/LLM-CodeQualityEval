/*
 You are given a positive number n.
 Return the smallest number x greater than or equal to n, such that the binary representation of x contains only set bits
 Example 1:
 Input: n = 5
 Output: 7
 Explanation:
 The binary representation of 7 is "111".
 Example 2:
 Input: n = 10
 Output: 15
 Explanation:
 The binary representation of 15 is "1111".
 Example 3:
 Input: n = 3
 Output: 3
 Explanation:
 The binary representation of 3 is "11".
 Constraints:
 1 <= n <= 1000
*/

/**
 * @param {number} n
 * @return {number}
 */
var smallestNumber = function(n) {
    let ans = 0;
    for (let i = 9; i >= 1; i--) {
        while (n % i === 0) {
            ans = ans * 10 + i;
            n /= i;
        }
    }
    return n === 1 ? ans : -1;
    
};