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
if (n < 6) return 6 - n;

boolean hasLower = false, hasUpper = false, hasDigit = false;
int replace = 0, one = 0, two = 0;

for (int i = 0; i < n; ) {
    if (Character.isLowerCase(password.charAt(i))) hasLower = true;
    if (Character.isUpperCase(password.charAt(i))) hasUpper = true;
    if (Character.isDigit(password.charAt(i))) hasDigit = true;

    int j = i;
    while (i < n && password.charAt(i) == password.charAt(j)) i++;
    int len = i - j;
    if (len >= 3) {
        replace += len / 3;
        if (len % 3 == 0) one++;
        else if (len % 3 == 1) two++;
    }
}

int missingTypes = (hasLower ? 0 : 1) + (hasUpper ? 0 : 1) + (hasDigit ? 0 : 1);

if (n <= 20) {
    return Math.max(missingTypes, replace);
} else {
    int delete = n - 20;
    replace -= Math.min(delete, one);
    replace -= Math.min(Math.max(delete - one, 0), two * 2) / 2;
    replace -= Math.max(delete - one - 2 * two, 0) / 3;
    return delete + Math.max(missingTypes, replace);
}
    }
}