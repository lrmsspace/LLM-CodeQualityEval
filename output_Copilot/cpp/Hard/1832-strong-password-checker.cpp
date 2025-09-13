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
        int lower = 1, upper = 1, digit = 1;
        vector<int> repeat(n, 0);
        for (int i = 0; i < n; ++i) {
            if (islower(password[i])) lower = 0;
            if (isupper(password[i])) upper = 0;
            if (isdigit(password[i])) digit = 0;
            int j = i;
            while (i < n && password[i] == password[j]) ++i;
            repeat[j] = i - j;
        }
        int missing = lower + upper + digit;
        if (n < 6) return max(missing, 6 - n);
        int over = max(n - 20, 0), left = 0, right = 0;
        int replace = 0, insert = 0, del = 0;
        for (int k = 1; k < n; ++k) {
            if (repeat[k] < 3) continue;
            if (repeat[k] % 3 == 0) ++replace;
            else if (repeat[k] % 3 == 1) ++insert;
            else ++del;
        }
        if (n <= 20) return max(missing, replace);
        int len = n - 20;
        if (len <= replace) return len + missing;
        len -= replace;
        if (len <= insert * 2) return len / 2 + len % 2 + max(missing, replace);
        len -= insert * 2;
        return len / 3 + len % 3 + max(missing, replace);        
    }
};