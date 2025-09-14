/**https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/ */
//Given a string s, determine if it is valid.
//A string s is valid if, starting with an empty string t = "", you can transform t into s after performing the following operation any number of times:
//	Insert string "abc" into any position in t. More formally, t becomes tleft + "abc" + tright, where t == tleft + tright. Note that tleft and tright may be empty.
//Return true if s is a valid string, otherwise, return false.
// 
//Example 1:
//Input: s = "aabcbc"
//Output: true
//Explanation:
//"" -> "abc" -> "aabcbc"
//Thus, "aabcbc" is valid.
//Example 2:
//Input: s = "abcabcababcc"
//Output: true
//Explanation:
//"" -> "abc" -> "abcabc" -> "abcabcabc" -> "abcabcababcc"
//Thus, "abcabcababcc" is valid.
//Example 3:
//Input: s = "abccba"
//Output: false
//Explanation: It is impossible to get "abccba" using the operation.
// 
//Constraints:
//	1 <= s.length <= 2 * 104
//	s consists of letters 'a', 'b', and 'c'
bool isValid(char* s) {
    int len = strlen(s);
    if (len % 3 != 0) {
        return false;
    }
    char* stack = (char*)malloc(sizeof(char) * len);
    int top = 0;
    for (int i = 0; i < len; i++) {
        stack[top++] = s[i];
        if (top >= 3 && stack[top - 3] == 'a' && stack[top - 2] == 'b' && stack[top - 1] == 'c') {
            top -= 3;
        }
    }
    free(stack);
    return top == 0;    
}