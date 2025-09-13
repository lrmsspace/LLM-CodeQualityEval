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
    let count = Array(10).fill(0);
    let result = Array(10).fill(0);
    
    for(let i=0; i<s.length; i++) {
        let digit = s[i].charCodeAt(0) - 97;
        count[digit]++;
    }
    
    result[0] = count[2] + count[3] + count[5];
    result[2] = count[0] - result[0] - count[6] - count[8];
    result[4] = count[1] - count[0] - count[2] - count[4];
    result[6] = count[9] - count[5] - count[6] - count[8];
    result[8] = count[7] - count[6];
    result[3] = count[7] - result[8] - count[2];
    result[5] = count[4] - result[3] - count[9];
    result[7] = count[8] - result[6] - count[9];
    result[1] = count[9] - result[0] - result[2] - result[4] - result[5] - result[6] - result[8] - result[7];
    
    return result.map(num => Array(num).fill(String.fromCharCode(num + 97))).flat().join('');
    
};