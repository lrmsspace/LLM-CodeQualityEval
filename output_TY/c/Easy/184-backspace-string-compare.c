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
bool backspaceCompare(char * s, char * t){
    int i = 0, j = 0;
    int k = 0, l = 0;
    while (s[i] != '\0') {
        if (s[i] == '#') {
            if (i == 0) {
                i++;
                continue;
            }
            else {
                i--;
                while (s[i] == '#') {
                    i--;
                   if (i == 0) {
                      i++;
                      break;
                   }
                }
            }
        }
    }
    while (t[j] != '\0') {
        if (t[j] == '#') {
            if (j == 0) {
                j++;
                continue;
            }
            else {
                j--;
                while (t[j] == '#') {
                    j--;
                   if (j == 0) {
                      j++;
                      break;
                  }
                }
            }
        }
    }
    while (s[k] != '\0') {
        k++;
    }
    while (t[l] != '\0') {
        l++;
    }
    if (k != l) {
        return false;
    }
    else {
        for (int m = 0; m < k; m++) {
            if (s[m] != t[m]) {
                return false;
            }
        }
    }
    return true;
}