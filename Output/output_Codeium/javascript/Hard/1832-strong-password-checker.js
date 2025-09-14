/**https://leetcode.com/problems/strong-password-checker/ */
//A password is considered strong if the below conditions are all met:
//	It has at least 6 characters and at most 20 characters.
//	It contains at least one lowercase letter, at least one uppercase letter, and at least one digit.
//	It does not contain three repeating characters in a row (i.e., "Baaabb0" is weak, but "Baaba0" is strong).
//Given a string password, return the minimum number of steps required to make password strong. if password is already strong, return 0.
//In one step, you can:
//	Insert one character to password,
//	Delete one character from password, or
//	Replace one character of password with another character.
// 
//Example 1:
//Input: password = "a"
//Output: 5
//Example 2:
//Input: password = "aA1"
//Output: 3
//Example 3:
//Input: password = "1337C0d3"
//Output: 0
// 
//Constraints:
//	1 <= password.length <= 50
//	password consists of letters, digits, dot '.' or exclamation mark '!'.
/**
 * @param {string} password
 * @return {number}
 */
var strongPasswordChecker = function(password) {
    let needLower = !/[a-z]/.test(password);
    let needUpper = !/[A-Z]/.test(password);
    let needDigit = !/\d/.test(password);
    let needReplace = 0;
    let i = 0;
    while (i < password.length - 2) {
        if (password[i] === password[i+1] && password[i] === password[i+2]) {
            needReplace++;
            i++;
        }
        i++;
    }
    let needAdd = Math.max(6 - password.length, 0);
    let needDelete = Math.max(password.length - 20, 0);
    return Math.max(needAdd, needDelete, needUpper + needLower + needDigit + needReplace);
};