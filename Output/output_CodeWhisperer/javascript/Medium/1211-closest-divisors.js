/**https://leetcode.com/problems/closest-divisors/ */
//Given an integer num, find the closest two integers in absolute difference whose product equals num + 1 or num + 2.
//Return the two integers in any order.
// 
//Example 1:
//Input: num = 8
//Output: [3,3]
//Explanation: For num + 1 = 9, the closest divisors are 3 & 3, for num + 2 = 10, the closest divisors are 2 & 5, hence 3 & 3 is chosen.
//Example 2:
//Input: num = 123
//Output: [5,25]
//Example 3:
//Input: num = 999
//Output: [40,25]
// 
//Constraints:
//	1 <= num <= 10^9
/**
 * @param {number} num
 * @return {number[]}
 */
var closestDivisors = function(num) {
    let num1 = num + 1;
    let num2 = num + 2;
    let res1 = [1, num1];
    let res2 = [1, num2];
    for (let i = 2; i <= Math.floor(Math.sqrt(num2)); i++) {
        if (num1 % i === 0) {
            res1 = [i, num1 / i];
        }
        if (num2 % i === 0) {
            res2 = [i, num2 / i];
        }
    }
    return Math.abs(res1[0] - res1[1]) < Math.abs(res2[0] - res2[1]) ? res1 : res2; 
};