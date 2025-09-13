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
    let missing = 3;
    if (password.match(/[a-z]/)) missing--;
    if (password.match(/[A-Z]/)) missing--;
    if (password.match(/[0-9]/)) missing--;
    
    let changes = 0;
    let one = 0;
    let two = 0;
    
    for (let i = 2; i < password.length; i++) {
        if (password[i] === password[i - 1] && password[i] === password[i - 2]) {
            let length = 2;
            while (i + 1 < password.length && password[i + 1] === password[i]) {
                i++;
                length++;
            }
            changes += length / 3;
            if (length % 3 === 0) one++;
            else if (length % 3 === 1) two++;
        }
    }
    
    if (password.length < 6) {
        return Math.max(6 - password.length, missing);
    } else if (password.length <= 20) {
        return Math.max(changes, missing);
    } else {
        let deleteCount = password.length - 20;
        
        changes -= Math.min(one, deleteCount);
        deleteCount -= Math.min(one, deleteCount);
        changes -= Math.min(two, deleteCount) * 2;
        deleteCount -= Math.min(two, deleteCount);
        changes -= deleteCount * 3 / 3;
        
        return deleteCount + Math.max(changes, missing);
    }
};