/**https://leetcode.com/problems/integer-to-english-words/ */
//Convert a non-negative integer num to its English words representation.
// 
//Example 1:
//Input: num = 123
//Output: "One Hundred Twenty Three"
//Example 2:
//Input: num = 12345
//Output: "Twelve Thousand Three Hundred Forty Five"
//Example 3:
//Input: num = 1234567
//Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
// 
//Constraints:
//	0 <= num <= 231 - 1
/**
 * @param {number} num
 * @return {string}
 */
var numberToWords = function(num) {
    if (num === 0) return 'Zero';
    let result = '';
    const levels = ['', 'Thousand', 'Million', 'Billion'];
    let i = 0;
    while (num > 0) {
        if (num % 1000 !== 0) {
            result = helper(num % 1000) + (levels[i] ? ' ' + levels[i] : '') + (result ? ' ' : '') + result;
        }
        num = Math.floor(num / 1000);
        i++;
    }
    return result;
    function helper(num) {
        const ones = ['', 'One', 'Two', 'Three', 'Four', 'Five', 'Six', 'Seven', 'Eight', 'Nine'];
        const teens = ['Ten', 'Eleven', 'Twelve', 'Thirteen', 'Fourteen', 'Fifteen', 'Sixteen', 'Seventeen', 'Eighteen', 'Nineteen'];
        const tens = ['', '', 'Twenty', 'Thirty', 'Forty', 'Fifty', 'Sixty', 'Seventy', 'Eighty', 'Ninety'];
        const result = [];
        if (num >= 100) {
            result.push(ones[Math.floor(num / 100)]);
            result.push('Hundred');
            num %= 100;
        }
        if (num >= 20) {
            result.push(tens[Math.floor(num / 10)]);
            num %= 10;
        }
        if (num >= 10) {
            result.push(teens[num - 10]);
            num = 0;
        }
        if (num > 0) {
            result.push(ones[num]);
        }
        return result.join(' ');
    }
};