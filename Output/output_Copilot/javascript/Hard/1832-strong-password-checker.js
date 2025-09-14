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
    let n = password.length;
    let hasLower = false, hasUpper = false, hasDigit = false;
    let repeatCount = 0;
    let replaceCount = 0;

    for (let i = 0; i < n; i++) {
        if (password[i] >= 'a' && password[i] <= 'z') hasLower = true;
        if (password[i] >= 'A' && password[i] <= 'Z') hasUpper = true;
        if (password[i] >= '0' && password[i] <= '9') hasDigit = true;

        if (i > 1 && password[i] === password[i - 1] && password[i] === password[i - 2]) {
            repeatCount++;
            i += 2; // Skip the next two characters
        }
    }

    let missingTypes = !hasLower + !hasUpper + !hasDigit;

    if (n < 6) {
        return Math.max(6 - n, missingTypes);
    } else if (n <= 20) {
        return Math.max(repeatCount, missingTypes);
    } else {
        let excessLength = n - 20;
        replaceCount += Math.floor(excessLength / 3);
        repeatCount -= replaceCount;

        if (repeatCount > 0) {
            replaceCount += repeatCount;
        }

        return excessLength + Math.max(missingTypes, replaceCount);
    }    
};