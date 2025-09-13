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
    if (num === 0) return "Zero";
    const ones = ["", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"];
    const tens = ["", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"];
    const thousands = ["", "Thousand", "Million", "Billion"];
    let result = "";
    for (let i = 0; i < thousands.length; i++) {
        if (num === 0) break;
        let temp = num % 1000;
        if (temp !== 0) {
            let tempResult = "";
            if (temp >= 100) {
                tempResult += ones[Math.floor(temp / 100)] + " Hundred ";
                temp %= 100;
            }
            if (temp >= 20) {
                tempResult += tens[Math.floor(temp / 10)] + " ";
                temp %= 10;
            }
            if (temp >= 1) {
                tempResult += ones[temp] + " ";
            }
            result = tempResult.trim() + " " + thousands[i] + " " + result;
        }
        num = Math.floor(num / 1000);
    }
    return result.trim();
};