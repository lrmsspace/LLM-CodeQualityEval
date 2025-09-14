/**https://leetcode.com/problems/consecutive-characters/ */
//The power of the string is the maximum length of a non-empty substring that contains only one unique character.
//Given a string s, return the power of s.
// 
//Example 1:
//Input: s = "leetcode"
//Output: 2
//Explanation: The substring "ee" is of length 2 with the character 'e' only.
//Example 2:
//Input: s = "abbcccddddeeeeedcba"
//Output: 5
//Explanation: The substring "eeeee" is of length 5 with the character 'e' only.
// 
//Constraints:
//	1 <= s.length <= 500
//	s consists of only lowercase English letters.
int maxPower(char* s) {
    int max = 0, current = 1;
    for (int i = 1; s[i]; i++) {
        if (s[i] == s[i-1])
            current++;
        else {
            max = fmax(max, current);
            current = 1;
        }
    }
    return fmax(max, current);
}