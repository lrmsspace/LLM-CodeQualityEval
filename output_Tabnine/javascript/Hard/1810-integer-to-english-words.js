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
    const units = ['', 'One', 'Two', 'Three', 'Four', 'Five', 'Six', 'Seven', 'Eight', 'Nine'];
    const teens = ['Ten', 'Eleven', 'Twelve', 'Thirteen', 'Fourteen', 'Fifteen', 'Sixteen', 'Seventeen', 'Eighteen', 'Nineteen'];
    const tens = ['', '', 'Twenty', 'Thirty', 'Forty', 'Fifty', 'Sixty', 'Seventy', 'Eighty', 'Ninety'];
    const thousands = ['', 'Thousand', 'Million', 'Billion'];
    
    let i = 0;
    let result = '';
    
    while (num > 0) {
        const chunk = Math.min(num % 1000, 999);
        num = Math.floor(num / 1000);
        
        if (chunk === 0) {
            continue;
        }
        
        if (i > 0) {
            result = `${thousands[i]} ${result}`;
        }
        
        if (chunk < 100) {
            if (chunk < 20) {
                result = `${teens[chunk - 10]} ${result}`;
            } else {
                result = `${tens[Math.floor(chunk / 10)]} ${units[chunk % 10]} ${result}`;
            }
        } else {
            result = `${units[Math.floor(chunk / 100)]} Hundred ${result}`;
        }
        
        i++;
    }
    
    return result.trim() || 'Zero';
    
};