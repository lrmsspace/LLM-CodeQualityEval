/**https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/ */
//You are given two strings s1 and s2 of equal length. A string swap is an operation where you choose two indices in a string (not necessarily different) and swap the characters at these indices.
//Return true if it is possible to make both strings equal by performing at most one string swap on exactly one of the strings. Otherwise, return false.
// 
//Example 1:
//Input: s1 = "bank", s2 = "kanb"
//Output: true
//Explanation: For example, swap the first character with the last character of s2 to make "bank".
//Example 2:
//Input: s1 = "attack", s2 = "defend"
//Output: false
//Explanation: It is impossible to make them equal with one string swap.
//Example 3:
//Input: s1 = "kelb", s2 = "kelb"
//Output: true
//Explanation: The two strings are already equal, so no string swap operation is required.
// 
//Constraints:
//	1 <= s1.length, s2.length <= 100
//	s1.length == s2.length
//	s1 and s2 consist of only lowercase English letters.
bool areAlmostEqual(char* s1, char* s2) {
    int len = strlen(s1);
    int diff = 0;
    int diff1 = -1, diff2 = -1;
    for (int i = 0; i < len; i++) {
        if (s1[i] != s2[i]) {
            diff++;
            if (diff1 == -1) {
                diff1 = i;
            } else if (diff2 == -1) {
                diff2 = i;
            } else {
                return false;
            }
        }
    }
    if (diff == 0) {
        return true;
    } else if (diff == 2) {
        return s1[diff1] == s2[diff2] && s1[diff2] == s2[diff1];
    } else {
        return false;
    }

    return true;
    
}