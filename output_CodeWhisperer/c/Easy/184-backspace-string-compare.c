/**https://leetcode.com/problems/backspace-string-compare/ */
//Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.
//Note that after backspacing an empty text, the text will continue empty.
// 
//Example 1:
//Input: s = "ab#c", t = "ad#c"
//Output: true
//Explanation: Both s and t become "ac".
//Example 2:
//Input: s = "ab##", t = "c#d#"
//Output: true
//Explanation: Both s and t become "".
//Example 3:
//Input: s = "a#c", t = "b"
//Output: false
//Explanation: s becomes "c" while t becomes "b".
// 
//Constraints:
//	1 <= s.length, t.length <= 200
//	s and t only contain lowercase letters and '#' characters.
// 
//Follow up: Can you solve it in O(n) time and O(1) space?
bool backspaceCompare(char* s, char* t) {
    int i = strlen(s) - 1, j = strlen(t) - 1, back;
    while (true) {
        back = 0;
        while (i >= 0 && (back > 0 || s[i] == '#')) {
            back += s[i] == '#' ? 1 : -1;
            i--;
        }
        back = 0;
        while (j >= 0 && (back > 0 || t[j] == '#')) {
            back += t[j] == '#' ? 1 : -1;
            j--;
        }
        if (i >= 0 && j >= 0 && s[i] == t[j]) {
            i--;
            j--;
        } else {
            break;
        }
    }
    return i == -1 && j == -1;
    
}