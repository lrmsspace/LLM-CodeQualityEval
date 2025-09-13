/**https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/ */
//Given an integer n, return any array containing n unique integers such that they add up to 0.
// 
//Example 1:
//Input: n = 5
//Output: [-7,-1,1,3,4]
//Explanation: These arrays also are accepted [-5,-1,1,2,3] , [-3,-1,2,-2,4].
//Example 2:
//Input: n = 3
//Output: [-1,0,1]
//Example 3:
//Input: n = 1
//Output: [0]
// 
//Constraints:
//	1 <= n <= 1000
/**
 * @param {number} n
 * @return {number[]}
 */
var sumZero = function(n) {
    let result = [];
    let sum = 0;
    
    for (let i = 1; i <= n / 2; i++) {
        result.push(-i);
        result.push(i);
        sum += i;
        sum -= i;
    }
    
    if (n % 2 === 1) {
        result.push(sum);
    }
    
    return result;
    
};