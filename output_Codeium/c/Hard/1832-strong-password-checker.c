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
    int hasLower = 0, hasUpper = 0, hasDigit = 0, hasSpecial = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (islower(password[i])) hasLower = 1;
        if (isupper(password[i])) hasUpper = 1;
        if (isdigit(password[i])) hasDigit = 1;
        if (strchr(".!", password[i])) hasSpecial = 1;
        if (i && password[i] == password[i - 1]) count++;
    }
    int res = 0;
    if (n < 6) res = 6 - n;
    if (!hasLower) res++;
    if (!hasUpper) res++;
    if (!hasDigit) res++;
    if (!hasSpecial) res++;
    if (count > 0) res += (count + 2) / 3;
    return res; 
}