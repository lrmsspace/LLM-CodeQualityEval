/**https://leetcode.com/problems/reverse-only-letters/ */
//Given a string s, reverse the string according to the following rules:
//	All the characters that are not English letters remain in the same position.
//	All the English letters (lowercase or uppercase) should be reversed.
//Return s after reversing it.
// 
//Example 1:
//Input: s = "ab-cd"
//Output: "dc-ba"
//Example 2:
//Input: s = "a-bC-dEf-ghIj"
//Output: "j-Ih-gfE-dCba"
//Example 3:
//Input: s = "Test1ng-Leet=code-Q!"
//Output: "Qedo1ct-eeLg=ntse-T!"
// 
//Constraints:
//	1 <= s.length <= 100
//	s consists of characters with ASCII values in the range [33, 122].
//	s does not contain '\"' or '\\'.
/**
 * @param {string} s
 * @return {string}
 */
var reverseOnlyLetters = function(s) {
    const alphabets = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ';
    const letters = [];
    const result = [];
    
    // Separate alphabets and non-alphabets
    for (let char of s) {
        if (alphabets.includes(char)) {
            letters.push(char);
        } else {
            result.push(char);
        }
    }
    
    // Reverse alphabets
    for (let i = letters.length - 1; i >= 0; i--) {
        result.push(letters[i]);
    }
    
    return result.join('');
    
};