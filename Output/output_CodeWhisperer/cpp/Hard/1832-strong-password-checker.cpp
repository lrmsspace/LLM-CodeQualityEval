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
        int n = password.length();
        bool hasLower = false, hasUpper = false, hasDigit = false;
        for (char c : password) {
            if (islower(c)) hasLower = true;
            if (isupper(c)) hasUpper = true;
            if (isdigit(c)) hasDigit = true;
        }
        int missing = 3 - (hasLower + hasUpper + hasDigit);
        if (n < 6) {
            return max(missing, 6 - n);
        } else {
            int replace = 0, one = 0, two = 0;
            for (int i = 0; i < n;) {
                int j = i;
                while (j < n && password[j] == password[i]) j++;
                int len = j - i;
                if (len >= 3) {
                    replace += len / 3;
                    if (len % 3 == 0) one++;
                    if (len % 3 == 1) two++;
                }
                i = j;
            }
            if (n <= 20) return max(missing, replace);
            int deleteCount = n - 20;
            replace -= min(deleteCount, one);
            replace -= min(max(deleteCount - one, 0), two * 2) / 2;
            replace -= max(deleteCount - one - 2 * two, 0) / 3;
            return deleteCount + max(missing, replace);
        }       
    }
};