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
    int sPtr = strlen(s) - 1, tPtr = strlen(t) - 1;
    while (sPtr >= 0 || tPtr >= 0) {
        int sBackspaceCount = 0, tBackspaceCount = 0;
        while (sPtr >= 0 && (s[sPtr] == '#' || sBackspaceCount > 0)) {
            sBackspaceCount += s[sPtr] == '#'? 1 : -1;
            sPtr--;
        }
        while (tPtr >= 0 && (t[tPtr] == '#' || tBackspaceCount > 0)) {
            tBackspaceCount += t[tPtr] == '#'? 1 : -1;
            tPtr--;
        }
        if (sPtr >= 0 && tPtr >= 0 && s[sPtr]!= t[tPtr]) {
            return false;
        }
        sPtr--;
        tPtr--;
    }
    return sPtr == -1 && tPtr == -1;
}