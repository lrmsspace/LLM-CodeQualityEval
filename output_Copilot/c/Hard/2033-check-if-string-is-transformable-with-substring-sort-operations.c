/**https://leetcode.com/problems/check-if-string-is-transformable-with-substring-sort-operations/ */
//Given two strings s and t, transform string s into string t using the following operation any number of times:
//	Choose a non-empty substring in s and sort it in place so the characters are in ascending order.
//	
//		For example, applying the operation on the underlined substring in "14234" results in "12344".
//	
//	
//Return true if it is possible to transform s into t. Otherwise, return false.
//A substring is a contiguous sequence of characters within a string.
// 
//Example 1:
//Input: s = "84532", t = "34852"
//Output: true
//Explanation: You can transform s into t using the following sort operations:
//"84532" (from index 2 to 3) -> "84352"
//"84352" (from index 0 to 2) -> "34852"
//Example 2:
//Input: s = "34521", t = "23415"
//Output: true
//Explanation: You can transform s into t using the following sort operations:
//"34521" -> "23451"
//"23451" -> "23415"
//Example 3:
//Input: s = "12345", t = "12435"
//Output: false
// 
//Constraints:
//	s.length == t.length
//	1 <= s.length <= 105
//	s and t consist of only digits.
bool isTransformable(char* s, char* t) {
    int len = strlen(s);
    int pos[10][len];
    int count[10];
    memset(count, 0, sizeof(count));
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < len; j++) {
            pos[i][j] = -1;
        }
    }
    for (int i = 0; i < len; i++) {
        int d = s[i] - '0';
        pos[d][count[d]++] = i;
    }
    for (int i = 0; i < len; i++) {
        int d = t[i] - '0';
        if (count[d] == 0) {
            return false;
        }
        for (int j = 0; j < d; j++) {
            if (count[j] > 0 && pos[j][count[j] - 1] < pos[d][count[d] - 1]) {
                return false;
            }
        }
        count[d]--;
    }
    return true;    
}