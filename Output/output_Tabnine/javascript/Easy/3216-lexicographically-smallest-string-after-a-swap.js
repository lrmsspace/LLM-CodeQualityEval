/*
 Given a string s containing only digits, return the lexicographically smallest string that can be obtained after swapping adjacent digits in s with the same parity at most once.
 Digits have the same parity if both are odd or both are even. For example, 5 and 9, as well as 2 and 4, have the same parity, while 6 and 9 do not.
 Example 1:
 Input: s = "45320"
 Output: "43520"
 Explanation: 
 s[1] == '5' and s[2] == '3' both have the same parity, and swapping them results in the lexicographically smallest string.
 Example 2:
 Input: s = "001"
 Output: "001"
 Explanation:
 There is no need to perform a swap because s is already the lexicographically smallest.
 Constraints:
 2 <= s.length <= 100
 s consists only of digits.
*/

/**
 * @param {string} s
 * @return {string}
 */
var getSmallestString = function(s) {
    // Convert the string to an array of digits
    const digits = Array.from(s, Number);
    
    // Find the index of the first digit with an odd parity
    let oddIndex = -1;
    for (let i = 0; i < digits.length; i++) {
        if (digits[i] % 2 === 1) {
            oddIndex = i;
            break;
        }
    }
    
    // If no odd digit is found, return the original string
    if (oddIndex === -1) {
        return s;
    }
    
    // Find the index of the next digit with the same parity
    let sameIndex = -1;
    for (let i = oddIndex + 1; i < digits.length; i++) {
        if (digits[i] % 2 === digits[oddIndex] % 2) {
            sameIndex = i;
            break;
        }
    }
    // If no same-parity digit is found, return the original string 
    if (sameIndex === -1) {
        return s;
    }
    
    // Swap the odd digit with the next same-parity digit
    [digits[oddIndex], digits[sameIndex]] = [digits[sameIndex], digits[oddIndex]];
    
    // Convert the array back to a string and return
    return digits.join('');
    
};