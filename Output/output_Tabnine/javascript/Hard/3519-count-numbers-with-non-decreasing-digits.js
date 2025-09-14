/*
 You are given two integers, l and r, represented as strings, and an integer b. Return the count of integers in the inclusive range [l, r] whose digits are in non-decreasing order when represented in base b.
 An integer is considered to have non-decreasing digits if, when read from left to right (from the most significant digit to the least significant digit), each digit is greater than or equal to the previous one.
 Since the answer may be too large, return it modulo 109 + 7.
 Example 1:
 Input: l = "23", r = "28", b = 8
 Output: 3
 Explanation:
 The numbers from 23 to 28 in base 8 are: 27, 30, 31, 32, 33, and 34.
 Out of these, 27, 33, and 34 have non-decreasing digits. Hence, the output is 3.
 Example 2:
 Input: l = "2", r = "7", b = 2
 Output: 2
 Explanation:
 The numbers from 2 to 7 in base 2 are: 10, 11, 100, 101, 110, and 111.
 Out of these, 11 and 111 have non-decreasing digits. Hence, the output is 2.
 Constraints:
 1 <= l.length <= r.length <= 100
 2 <= b <= 10
 l and r consist only of digits.
 The value represented by l is less than or equal to the value represented by r.
 l and r do not contain leading zeros.
*/

/**
 * @param {string} l
 * @param {string} r
 * @param {number} b
 * @return {number}
 */
var countNumbers = function(l, r, b) {
    const MOD = 10 ** 9 + 7;
    const dp = Array(b).fill(0).map(() => Array(10).fill(0));
    for (let i = 0; i < b; i++) {
        dp[i][0] = 1;
        for (let j = 1; j < 10; j++) {
            dp[i][j] = (dp[i][j - 1] + dp[i][j]) % MOD;
        }
    }
    
    const count = (num, base) => {
        let count = 0;
        for (let i = 0; i < base; i++) {
            count += dp[base - 1][i] * Math.pow(base, num.length - 1 - i);
            count %= MOD;
        }
        return count;
    };
    let left = count(l, b); 
    let right = count(r, b);    
    return (right - left + MOD) % MOD;  
    
};