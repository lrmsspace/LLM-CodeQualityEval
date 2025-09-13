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
        int missing = 3;
        int[] count = new int[3];
        for (int i = 0; i < n; i++) {
            char c = password.charAt(i);
            if (c >= 'a' && c <= 'z') {
                count[0] = 1;
            } else if (c >= 'A' && c <= 'Z') {
                count[1] = 1;
            } else if (c >= '0' && c <= '9') {
                count[2] = 1;
            }
        }
        for (int i = 0; i < 3; i++) {
            missing -= count[i];
        }
        int changes = 0;
        for (int i = 2; i < n; i++) {
            if (password.charAt(i) == password.charAt(i - 1) && password.charAt(i) == password.charAt(i - 2)) {
                int j = i + 1;
                while (j < n && password.charAt(j) == password.charAt(i)) {
                    j++;
                }
                int len = j - i;
                i = j - 1;
                changes += len / 3;
            }
        }
        if (n < 6) {
            return Math.max(6 - n, Math.max(missing, changes));
        } else if (n <= 20) {
            return Math.max(missing, changes);
        } else {
            int delete = n - 20;
            changes -= Math.min(delete, changes);
            delete -= Math.min(delete, changes);
            return delete + Math.max(missing, changes) + 20 - n;
        }   
    }
}