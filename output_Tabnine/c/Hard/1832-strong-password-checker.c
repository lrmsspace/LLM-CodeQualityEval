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
int strongPasswordChecker(char* password) {
    int n = strlen(password);
    int lower = 0, upper = 0, digit = 0, special = 0;
    int i, j, k;
    int minSteps = 0;
    int repeatCount = 0;
    for (i = 0; i < n; ++i) {
        if (islower(password[i])) ++lower;
        else if (isupper(password[i])) ++upper;
        else if (isdigit(password[i])) ++digit;
        else ++special;
    }
    if (lower == 0 || upper == 0 || digit == 0 || special == 0) {
        return n + 4 - lower - upper - digit - special;
    }
    for (i = 0; i < n - 2; ++i) {
        if (password[i] == password[i + 1] && password[i + 1] == password[i + 2]) {
            repeatCount++;
            j = i + 2;
            while (j < n && password[j] == password[i + 2]) j++;
            minSteps += j - i - 2;
            i = j - 1;
        }
    }
    minSteps += n - repeatCount * 3;
    return minSteps < 6? 6 - minSteps : 0;
}