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
    for (let digits = 1; digits <= 9; digits++) {
        let num = 0;
        for (let i = 0; i < digits; i++) {
            num = num * 10 + (i + 1);
        }
        while (num <= high) {
            if (num >= low) {
                result.push(num);
            }
            num = num * 10 + (num % 10 + 1);
        }
    }
    return result;
};