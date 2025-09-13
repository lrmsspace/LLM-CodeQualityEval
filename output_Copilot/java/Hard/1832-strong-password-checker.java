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
class Solution {
    public int strongPasswordChecker(String password) {
        int n = password.length();
        boolean hasLower = false, hasUpper = false, hasDigit = false;
        int repeatCount = 0, replaceCount = 0, insertCount = 0;

        for (int i = 0; i < n; i++) {
            char c = password.charAt(i);
            if (Character.isLowerCase(c)) hasLower = true;
            if (Character.isUpperCase(c)) hasUpper = true;
            if (Character.isDigit(c)) hasDigit = true;

            if (i > 1 && c == password.charAt(i - 1) && c == password.charAt(i - 2)) {
                repeatCount++;
                i++; // Skip the next character to avoid counting it again
            }
        }

        if (!hasLower) insertCount++;
        if (!hasUpper) insertCount++;
        if (!hasDigit) insertCount++;

        if (n < 6) {
            return Math.max(6 - n, insertCount);
        } else if (n <= 20) {
            return Math.max(replaceCount + repeatCount, insertCount);
        } else {
            int excessChars = n - 20;
            replaceCount += excessChars / 3;
            repeatCount -= Math.min(repeatCount, excessChars / 3);
            return excessChars + Math.max(replaceCount + repeatCount, insertCount);
        }        
    }
}