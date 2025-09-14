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
public:
    int strongPasswordChecker(string password) {
        int needLowercase = 1, needUppercase = 1, needDigit = 1, needRepeat = 3, needReplace = 0;
        int n = password.length();
        if (n < 6) return 6 - n;
        if (n > 20) return n - 20;
        
        for (int i = 0; i < n; ++i) {
            if (islower(password[i])) needLowercase--;
            else if (isupper(password[i])) needUppercase--;
            else if (isdigit(password[i])) needDigit--;
            else needReplace++;
            
            if (i > 0 && password[i] == password[i - 1]) {
                needRepeat--;
                if (i > 1 && password[i - 1] == password[i - 2]) needRepeat--;
            }
        }
        
        return max(0, needLowercase) + max(0, needUppercase) + max(0, needDigit) + needReplace + needRepeat;
        
    }
};