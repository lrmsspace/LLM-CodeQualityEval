/**https://leetcode.com/problems/verbal-arithmetic-puzzle/ */
//Given an equation, represented by words on the left side and the result on the right side.
//You need to check if the equation is solvable under the following rules:
//	Each character is decoded as one digit (0 - 9).
//	No two characters can map to the same digit.
//	Each words[i] and result are decoded as one number without leading zeros.
//	Sum of numbers on the left side (words) will equal to the number on the right side (result).
//Return true if the equation is solvable, otherwise return false.
// 
//Example 1:
//Input: words = ["SEND","MORE"], result = "MONEY"
//Output: true
//Explanation: Map 'S'-> 9, 'E'->5, 'N'->6, 'D'->7, 'M'->1, 'O'->0, 'R'->8, 'Y'->'2'
//Such that: "SEND" + "MORE" = "MONEY" ,  9567 + 1085 = 10652
//Example 2:
//Input: words = ["SIX","SEVEN","SEVEN"], result = "TWENTY"
//Output: true
//Explanation: Map 'S'-> 6, 'I'->5, 'X'->0, 'E'->8, 'V'->7, 'N'->2, 'T'->1, 'W'->'3', 'Y'->4
//Such that: "SIX" + "SEVEN" + "SEVEN" = "TWENTY" ,  650 + 68782 + 68782 = 138214
//Example 3:
//Input: words = ["LEET","CODE"], result = "POINT"
//Output: false
//Explanation: There is no possible mapping to satisfy the equation, so we return false.
//Note that two different characters cannot map to the same digit.
// 
//Constraints:
//	2 <= words.length <= 5
//	1 <= words[i].length, result.length <= 7
//	words[i], result contain only uppercase English letters.
//	The number of different characters used in the expression is at most 10.
/**
 * @param {string[]} words
 * @param {string} result
 * @return {boolean}
 */
var isSolvable = function(words, result) {
    // Initialize a frequency array to count the occurrences of each digit
    let freq = Array(10).fill(0);
    // Initialize a map to store the mapping of characters to digits
    let map = new Map();
    // Initialize a set to store the digits that have been used
    let used = new Set();
    // Initialize a stack to store the digits that need to be filled
    let stack = [];
    // Initialize a variable to store the sum of the digits
    let sum = 0;
    // Initialize a variable to store the number of digits
    let numDigits = 0;
    
    // Count the occurrences of each digit in the words and result
    for (let word of words) {
        for (let char of word) {
            freq[char.charCodeAt(0) - 'A'.charCodeAt(0)]++;
        }
    }
    for (let char of result) {
        freq[char.charCodeAt(0) - 'A'.charCodeAt(0)]++;
    }
    
    // Find the digits that cannot be used
    for (let i = 0; i < 10; i++) {
        if (freq[i] > 0) {
            used.add(String(i));
        }
    }
    
    // Find the digits that need to be filled
    for (let i = 0; i < 10; i++) {
        if (freq[i] === 0 &&!used.has(String(i))) {
            stack.push(i);
            numDigits++;
        }
    }
    
    // Backtracking to find a valid mapping
    while (stack.length > 0) {
        let digit = stack.pop();
        
        // Try to fill the current digit
        for (let i = 9; i >= 0; i--) {
            if (freq[i] > 0 &&!used.has(String(i))) {
                map.set(String.fromCharCode(i + 'A'.charCodeAt(0)), digit);
                freq[i]--;
                used.add(String(i));
                stack.push(i);
                break;
            }
        }
        
        // If no valid digit is found, backtrack
        if (stack.length === 0) {
            freq[digit]++;
            used.delete(String(digit));
            map.delete(String.fromCharCode(digit + 'A'.charCodeAt(0)));
        }
    }
    
    // Calculate the sum of the digits
    for (let word of words) {
        let sumWord = 0;
        for (let char of word) {
            sumWord += map.get(char);
        }
        sum += sumWord;
    }
    
    // Check if the sum of the digits equals the result
    return sum === parseInt(result);
};