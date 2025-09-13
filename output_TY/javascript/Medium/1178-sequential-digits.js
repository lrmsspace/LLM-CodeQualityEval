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
    let result = [];
    let start = low.toString().length;
    let end = high.toString().length;
    let startNum = low;
    let endNum = high;
    for (let i = start; i <= end; i++) {
        let startDigit = 1;
        let endDigit = 9;
        if (i > start) {
            startDigit = parseInt(startNum.toString()[0]);
            endDigit = parseInt(endNum.toString()[0]) + 1;
        }
        for (let j = startDigit; j < endDigit; j++) {
            let num = j;
            for (let k = 1; k < i; k++) {
                num = num * 10 + (j + k);
                if (num >= low && num <= high) {
                    result.push(num);
                }
            }
        }
    }
    return result;
};