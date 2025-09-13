/**https://leetcode.com/problems/numbers-with-repeated-digits/ */
//Given an integer n, return the number of positive integers in the range [1, n] that have at least one repeated digit.
// 
//Example 1:
//Input: n = 20
//Output: 1
//Explanation: The only positive number (<= 20) with at least 1 repeated digit is 11.
//Example 2:
//Input: n = 100
//Output: 10
//Explanation: The positive numbers (<= 100) with atleast 1 repeated digit are 11, 22, 33, 44, 55, 66, 77, 88, 99, and 100.
//Example 3:
//Input: n = 1000
//Output: 262
// 
//Constraints:
//	1 <= n <= 109
/**
 * @param {number} n
 * @return {number}
 */
var numDupDigitsAtMostN = function(n) {
    const digits = Array.from({length: 10}, (_, i) => i);
    const count = Array(10).fill(0);
    let maxCount = 0;
    let res = 0;
    
    // Count the frequency of digits
    for (let num = 1; num <= n; num++) {
        const strNum = num.toString();
        for (let i = 0; i < strNum.length; i++) {
            count[parseInt(strNum[i])]++;
        }
    }
    
    // Calculate the maximum count of repeated digits
    for (let i = 9; i >= 0; i--) {
        maxCount += count[i] * (9 - i);
        if (maxCount > n - num) {
            res += count[i] * (n - num + 1);
            break;
        }
    }
    
    // Calculate the number of valid numbers with repeated digits
    for (let i = 0; i < digits.length; i++) {
        if (count[i] > 0) {
            for (let j = 0; j < digits[i]; j++) {
                if (j === digits[i]) {
                    res += count[i] * (maxCount - n + num);
                } else {
                    res += count[i] * (9 - j);
                }
            }
        }
    }
    
    return res;
    
};