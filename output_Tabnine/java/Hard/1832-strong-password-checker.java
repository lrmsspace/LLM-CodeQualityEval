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
        int needChange = 0;
        int countLower = 0, countUpper = 0, countDigit = 0, countRepeat = 0;
        
        // Check length
        if (password.length() < 6 || password.length() > 20) needChange = Math.max(6 - password.length(), 0);
        
        // Check character types
        for (char c : password.toCharArray()) {
            if (Character.isLowerCase(c)) countLower++;
            else if (Character.isUpperCase(c)) countUpper++;
            else if (Character.isDigit(c)) countDigit++;
            else if (c == '.' || c == '!') {
                // Ignore '.' and '!'
            } else {
                return -1; // Invalid character
            }
        }
        
        // Check character repetition
        for (int i = 0; i < password.length() - 2; i++) {
            if (password.charAt(i) == password.charAt(i + 1) && password.charAt(i) == password.charAt(i + 2)) {
                countRepeat++;
                break;
            }
        }
        
        // Calculate steps to make password strong
        needChange += Math.max(3 - countLower, 0);
        needChange += Math.max(3 - countUpper, 0);
        needChange += Math.max(3 - countDigit, 0);
        needChange += countRepeat;
        
        return needChange;
        
    }
}