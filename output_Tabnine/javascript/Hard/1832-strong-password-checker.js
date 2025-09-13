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
    const lowercase = /[a-z]/;
    const uppercase = /[A-Z]/;
    const digit = /[0-9]/;
    const specialChar = /[!@#$%^&*(),.?":{}|<>]/;
    const repeatPattern = /(.)\1{2,}/;
    
    let steps = 0;
    
    //
    // Check if password has at least 6 and at most 20 characters
    if (password.length < 6 || password.length > 20) {
        steps += Math.max(6 - password.length, 0);
    }
    
    // Check if password contains at least one lowercase letter, one uppercase letter, and one digit
    if (!lowercase.test(password) ||!uppercase.test(password) ||!digit.test(password)) {
        steps += Math.max(
            3 - (lowercase.test(password)? 0 : 1),
            Math.max(3 - (uppercase.test(password)? 0 : 1), 3 - (digit.test(password)? 0 : 1))
        );
    }
    
    // Check if password contains three repeating characters in a row
    if (repeatPattern.test(password)) {
        const matches = password.match(repeatPattern);
        steps += matches[0].length - 3;
    }
    
    // Check if password contains special characters
    if (!specialChar.test(password)) {
        steps += 3 - (specialChar.test(password)? 0 : 1);
    }
    
    return steps;
    
};