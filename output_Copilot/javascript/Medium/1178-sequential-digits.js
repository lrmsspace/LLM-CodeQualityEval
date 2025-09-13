/**https://leetcode.com/problems/sequential-digits/ */
//An integer has sequential digits if and only if each digit in the number is one more than the previous digit.
//Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.
// 
//Example 1:
//Input: low = 100, high = 300
//Output: [123,234]
//Example 2:
//Input: low = 1000, high = 13000
//Output: [1234,2345,3456,4567,5678,6789,12345]
// 
//Constraints:
//	10 <= low <= high <= 10^9
/**
 * @param {number} low
 * @param {number} high
 * @return {number[]}
 */
var sequentialDigits = function(low, high) {
    const result = [];
    const start = 1;
    const end = 9;
    const queue = [];
    for (let i = start; i <= end; i++) {
        queue.push(i);
    }
    while (queue.length) {
        const num = queue.shift();
        if (num >= low && num <= high) {
            result.push(num);
        }
        if (num % 10 < 9) {
            queue.push(num * 10 + num % 10 + 1);
        }
    }
    return result.sort((a, b) => a - b);    
};