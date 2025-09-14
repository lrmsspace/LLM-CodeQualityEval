/**https://leetcode.com/problems/ugly-number-ii/ */
//An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.
//Given an integer n, return the nth ugly number.
// 
//Example 1:
//Input: n = 10
//Output: 12
//Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.
//Example 2:
//Input: n = 1
//Output: 1
//Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.
// 
//Constraints:
//	1 <= n <= 1690
/**
 * @param {number} n
 * @return {number}
 */
var nthUglyNumber = function(n) {
    let uglyNumbers = [1];
    let index2 = 0;
    let index3 = 0;
    let index5 = 0;
    for(let i=1;i<n;i++){
        let next2 = uglyNumbers[index2]*2;
        let next3 = uglyNumbers[index3]*3;
        let next5 = uglyNumbers[index5]*5;
        let nextUglyNumber = Math.min(next2,next3,next5);
        uglyNumbers.push(nextUglyNumber);
        if(nextUglyNumber===next2) index2++;
        if(nextUglyNumber===next3) index3++;
        if(nextUglyNumber===next5) index5++;
    }
    return uglyNumbers[n-1];
};