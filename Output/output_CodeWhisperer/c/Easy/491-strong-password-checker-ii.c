/**https://leetcode.com/problems/strong-password-checker-ii/ */
//A password is said to be strong if it satisfies all the following criteria:
//	It has at least 8 characters.
//	It contains at least one lowercase letter.
//	It contains at least one uppercase letter.
//	It contains at least one digit.
//	It contains at least one special character. The special characters are the characters in the following string: "!@#$%^&*()-+".
//	It does not contain 2 of the same character in adjacent positions (i.e., "aab" violates this condition, but "aba" does not).
//Given a string password, return true if it is a strong password. Otherwise, return false.
// 
//Example 1:
//Input: password = "IloveLe3tcode!"
//Output: true
//Explanation: The password meets all the requirements. Therefore, we return true.
//Example 2:
//Input: password = "Me+You--IsMyDream"
//Output: false
//Explanation: The password does not contain a digit and also contains 2 of the same character in adjacent positions. Therefore, we return false.
//Example 3:
//Input: password = "1aB!"
//Output: false
//Explanation: The password does not meet the length requirement. Therefore, we return false.
// 
//Constraints:
//	1 <= password.length <= 100
//	password consists of letters, digits, and special characters: "!@#$%^&*()-+".
bool strongPasswordCheckerII(char* password) {
    int len = strlen(password);
    if (len < 8) return false;

    bool hasLower = false, hasUpper = false, hasDigit = false, hasSpecial = false;
    char* special = "!@#$%^&*()-+";
    for (int i = 0; i < len; i++) {
        if (i > 0 && password[i] == password[i - 1]) return false;
        if (islower(password[i])) hasLower = true;
        else if (isupper(password[i])) hasUpper = true;
        else if (isdigit(password[i])) hasDigit = true;
        else if (strchr(special, password[i])) hasSpecial = true;
    }

    return hasLower && hasUpper && hasDigit && hasSpecial;
    
}