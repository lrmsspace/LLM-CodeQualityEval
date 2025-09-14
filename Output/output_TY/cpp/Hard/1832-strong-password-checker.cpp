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
        int n = password.size();
        int res = 0;
        bool hasLower = false, hasUpper = false, hasDigit = false;
        for (char ch : password) {
            if (isdigit(ch)) hasDigit = true;
            else if (islower(ch)) hasLower = true;
            else if (isupper(ch)) hasUpper = true;
        }
        int miss = (hasLower + hasUpper + hasDigit);
        if (n < 6) res = max(miss, 6 - n);
        else if (n <= 20) res = max(miss, 0);
        else {
            int del = n - 20;
            res += del;
            for (int i = 1; i <= 3 && del > 0; i++) {
                int d = min(del, i);
            }
        }
        return res;
    }
};