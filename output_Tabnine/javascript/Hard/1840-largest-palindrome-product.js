/**https://leetcode.com/problems/largest-palindrome-product/ */
//Given an integer n, return the largest palindromic integer that can be represented as the product of two n-digits integers. Since the answer can be very large, return it modulo 1337.
// 
//Example 1:
//Input: n = 2
//Output: 987
//Explanation: 99 x 91 = 9009, 9009 % 1337 = 987
//Example 2:
//Input: n = 1
//Output: 9
// 
//Constraints:
//	1 <= n <= 8
/**
 * @param {number} n
 * @return {number}
 */
var largestPalindrome = function(n) {
    let max = Math.pow(10, n) - 1;
    let min = Math.pow(10, n - 1);
    let maxPalindrome = 0;
    
    for (let i = max; i >= min; i--) {
        let j = i;
        let palindrome = 0;
        
        while (j > 0) {
            let digit = j % 10;
            palindrome = palindrome * 10 + digit;
            j = Math.floor(j / 10);
        }
        
        if (palindrome > maxPalindrome && palindrome < max) {
            maxPalindrome = palindrome;
        }
    }
    
    return maxPalindrome % 1337;
    
};