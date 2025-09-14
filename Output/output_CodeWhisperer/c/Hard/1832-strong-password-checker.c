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
    int missing = 3;
    int hasLower = 0, hasUpper = 0, hasDigit = 0;
    int i = 0;
    while (i < n) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            hasLower = 1;
        } else if (password[i] >= 'A' && password[i] <= 'Z') {
            hasUpper = 1;
        } else if (password[i] >= '0' && password[i] <= '9') {
            hasDigit = 1;
        }
        i++;
    }
    missing -= (hasLower + hasUpper + hasDigit);
    if (n < 6) {
        return fmax(6 - n, missing);
    }
    int change = 0;

    int one = 0, two = 0;

    i = 0;

    while (i < n) {
        int len = 1;
        while (i + 1 < n && password[i] == password[i + 1]) {
            len++;
            i++;
        }
        if (len >= 3) {
            change += len / 3;
            if (len % 3 == 0) {
                one++;
            } else if (len % 3 == 1) {
                two++;
            }
        }
        i++;
    }
    if (n <= 20) {
        return fmax(change, missing);
    }

    int delete = n - 20;
    change -= fmin(delete, one);
    change -= fmin(fmax(delete - one, 0), two * 2) / 2;
    change -= fmax(delete - one - 2 * two, 0) / 3;
    return delete + fmax(change, missing);
    
}