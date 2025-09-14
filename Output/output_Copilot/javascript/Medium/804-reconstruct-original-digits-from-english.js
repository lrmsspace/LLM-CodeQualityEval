/**https://leetcode.com/problems/reconstruct-original-digits-from-english/ */
//Given a string s containing an out-of-order English representation of digits 0-9, return the digits in ascending order.
// 
//Example 1:
//Input: s = "owoztneoer"
//Output: "012"
//Example 2:
//Input: s = "fviefuro"
//Output: "45"
// 
//Constraints:
//	1 <= s.length <= 105
//	s[i] is one of the characters ["e","g","f","i","h","o","n","s","r","u","t","w","v","x","z"].
//	s is guaranteed to be valid.
/**
 * @param {string} s
 * @return {string}
 */
var originalDigits = function(s) {
    const count = Array(26).fill(0);
    for (const char of s) {
        count[char.charCodeAt(0) - 'a'.charCodeAt(0)]++;
    }
    const digits = [];
    digits[0] = count['z'.charCodeAt(0) - 'a'.charCodeAt(0)];
    digits[2] = count['w'.charCodeAt(0) - 'a'.charCodeAt(0)];
    digits[4] = count['u'.charCodeAt(0) - 'a'.charCodeAt(0)];
    digits[6] = count['x'.charCodeAt(0) - 'a'.charCodeAt(0)];
    digits[8] = count['g'.charCodeAt(0) - 'a'.charCodeAt(0)];
    digits[3] = count['h'.charCodeAt(0) - 'a'.charCodeAt(0)] - digits[8];
    digits[5] = count['f'.charCodeAt(0) - 'a'.charCodeAt(0)] - digits[4];
    digits[7] = count['s'.charCodeAt(0) - 'a'.charCodeAt(0)] - digits[6];
    digits[1] = count['o'.charCodeAt(0) - 'a'.charCodeAt(0)] - digits[2] - digits[4] - digits[0];
    digits[9] = (count['i'.charCodeAt(0) - 'a'.charCodeAt(0)] - digits[5] - digits[6] - digits[8]) / 2;
    
    let result = '';
    for (let i = 0; i < 10; i++) {
        result += i.toString().repeat(digits[i]);
    }
    
    return result;    
};