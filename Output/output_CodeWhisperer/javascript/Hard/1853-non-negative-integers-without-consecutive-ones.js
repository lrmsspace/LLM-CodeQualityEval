/**https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/ */
//Given a positive integer n, return the number of the integers in the range [0, n] whose binary representations do not contain consecutive ones.
// 
//Example 1:
//Input: n = 5
//Output: 5
//Explanation:
//Here are the non-negative integers <= 5 with their corresponding binary representations:
//0 : 0
//1 : 1
//2 : 10
//3 : 11
//4 : 100
//5 : 101
//Among them, only integer 3 disobeys the rule (two consecutive ones) and the other 5 satisfy the rule. 
//Example 2:
//Input: n = 1
//Output: 2
//Example 3:
//Input: n = 2
//Output: 3
// 
//Constraints:
//	1 <= n <= 109
/**
 * @param {number} n
 * @return {number}
 */
var findIntegers = function(n) {
    let fib = [1, 2];
    for (let i = 2; i < 31; i++) {
        fib.push(fib[i - 1] + fib[i - 2]);
    }
    let res = 0;
    let prevBit = 0;
    for (let i = 30; i >= 0; i--) {
        if ((n & (1 << i)) !== 0) {
            res += fib[i + 1];
            if (prevBit === 1) {
                res--;
                break;
            }
            prevBit = 1;
        } else {
            prevBit = 0;
        }
    }
    return res + 1;
};