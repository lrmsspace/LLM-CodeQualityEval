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
    let res = 0;
    let hasLower = false;
    let hasUpper = false;
    let hasDigit = false;
    let hasSpecial = false;
    for (let i = 0; i < n; i++) {
        let ch = password[i];
        if (ch >= 'a' && ch <= 'z') hasLower = true;
        else if (ch >= 'A' && ch <= 'Z') hasUpper = true;
        else if (ch >= '0' && ch <= '9') hasDigit = true;
        else hasSpecial = true;
    }
    let types = hasLower + hasUpper + hasDigit + hasSpecial;
    if (n < 6) {
        res =Math.max(6 - n, 3 - types);
    }
    else if (n <= 20) {
        let change = 0;
        let i = 0;
        while (i < n) {
            let j = i;
            while (j < n && password[j] == password[i]) j++;
            let len = j - i;
            if (len < 3) change += 3 - len;
            i = j;
        }
        res = Math.max(change, 3 - types);
    }
    else {
        let remove = n - 20;
        let i = 0;
        while (remove > 0 && i < n) {
            let j = i;
            while (j < n && password[j] == password[i]) j++;
        }
    }
    return res;
};