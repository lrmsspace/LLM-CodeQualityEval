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
    int n = strlen(password);
    int lower = 1, upper = 1, digit = 1, special = 1, repeat = 0;
    for (int i = 0; i < n; i++) {
        if (islower(password[i])) lower = 0;
        if (isupper(password[i])) upper = 0;
        if (isdigit(password[i])) digit = 0;
        if (strchr("!@#$%^&*()-+", password[i])) special = 0;
        if (i > 0 && password[i] == password[i - 1]) repeat = 1;
    }
    return n >= 8 && lower + upper + digit + special == 0 && repeat == 0;    
}