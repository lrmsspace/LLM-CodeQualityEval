/**https://leetcode.com/problems/monotone-increasing-digits/ */
//An integer has monotone increasing digits if and only if each pair of adjacent digits x and y satisfy x <= y.
//Given an integer n, return the largest number that is less than or equal to n with monotone increasing digits.
// 
//Example 1:
//Input: n = 10
//Output: 9
//Example 2:
//Input: n = 1234
//Output: 1234
//Example 3:
//Input: n = 332
//Output: 299
// 
//Constraints:
//	0 <= n <= 109
/**
 * @param {number} n
 * @return {number}
 */
var monotoneIncreasingDigits = function(n) {
    let num = Array.from(String(n), Number);
    let i = num.length - 1;
    
    // Find the first pair of adjacent digits that are in decreasing order
    while (i > 0 && num[i] <= num[i - 1]) {
        i--;
    }
    
    // If no such pair exists, return the original number
    if (i === 0) {
        return n;
    }
    
    // Decrease the rightmost digit of the pair
    num[i - 1]--;
    
    // Fill the rest of the digits with 9s
    for (let j = i; j < num.length; j++) {
        num[j] = 9;
    }
    
    // Convert the number back to a string and return it
    return Number(num.join(''));
    
};