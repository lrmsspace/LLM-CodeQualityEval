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
    var words = [];
    var ones = ['', 'One', 'Two', 'Three', 'Four', 'Five', 'Six', 'Seven', 'Eight', 'Nine'];
    var teens = ['Ten', 'Eleven', 'Twelve', 'Thirteen', 'Fourteen', 'Fifteen', 'Sixteen', 'Seventeen', 'Eighteen', 'Nineteen'];
    var tens = ['', 'Ten', 'Twenty', 'Thirty', 'Forty', 'Fifty', 'Sixty', 'Seventy', 'Eighty', 'Ninety'];
    var suffix = ['', 'Thousand', 'Million','Billion'];
    var i = 0;
    while(num > 0){
        var digit = num % 1000;
        if(digit !== 0){
            var word = '';
            if(digit < 10){
                word = ones[digit];
            }else if(digit < 20){
                word = teens[digit - 10];
            }else{
                word = tens[Math.floor(digit / 10)] + ' ' + ones[digit % 10];
            }
            words.unshift(word + ' ' + suffix[i]);
        }
        num = Math.floor(num / 1000);
        i++;
    }
    return words.join(' ').trim();

};