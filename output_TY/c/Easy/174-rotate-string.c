/**https://leetcode.com/problems/rotate-string/ */
//Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.
//A shift on s consists of moving the leftmost character of s to the rightmost position.
//	For example, if s = "abcde", then it will be "bcdea" after one shift.
// 
//Example 1:
//Input: s = "abcde", goal = "cdeab"
//Output: true
//Example 2:
//Input: s = "abcde", goal = "abced"
//Output: false
// 
//Constraints:
//	1 <= s.length, goal.length <= 100
//	s and goal consist of lowercase English letters.
bool rotateString(char * s, char * goal){
    int len = strlen(s);
    if (len != strlen(goal)) return false;
    for (int i = 0; i < len; i++) {
        if (strncmp(s, goal, len) == 0) return true;
        char temp = s[0];
        for (int j = 0; j < len - 1; j++) {
            s[j] = s[j + 1];
        }
    }
    s[len - 1] = temp;
    return false;
}