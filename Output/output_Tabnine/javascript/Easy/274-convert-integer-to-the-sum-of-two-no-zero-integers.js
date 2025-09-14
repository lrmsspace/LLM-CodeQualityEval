/**https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/ */
//No-Zero integer is a positive integer that does not contain any 0 in its decimal representation.
//Given an integer n, return a list of two integers [a, b] where:
//	a and b are No-Zero integers.
//	a + b = n
//The test cases are generated so that there is at least one valid solution. If there are many valid solutions, you can return any of them.
// 
//Example 1:
//Input: n = 2
//Output: [1,1]
//Explanation: Let a = 1 and b = 1.
//Both a and b are no-zero integers, and a + b = 2 = n.
//Example 2:
//Input: n = 11
//Output: [2,9]
//Explanation: Let a = 2 and b = 9.
//Both a and b are no-zero integers, and a + b = 11 = n.
//Note that there are other valid answers as [8, 3] that can be accepted.
// 
//Constraints:
//	2 <= n <= 104
/**
 * @param {number} n
 * @return {number[]}
 */
var getNoZeroIntegers = function(n) {
    // Start with the smallest possible value for 'a'
    for (let a = 1; a < n; a++) {
        // Calculate the possible value for 'b'
        let b = n - a;
        
        // Check if 'a' and 'b' are both no-zero integers and their sum equals 'n'
        if (a.toString().split('0').length === 1 && b.toString().split('0').length === 1 && a + b === n) {
            return [a, b];
        }
    }
    
    // Return an empty array if no valid solution is found
    return [];
    
};