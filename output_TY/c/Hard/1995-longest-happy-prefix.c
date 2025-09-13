/**https://leetcode.com/problems/longest-happy-prefix/ */
//A string is called a happy prefix if is a non-empty prefix which is also a suffix (excluding itself).
//Given a string s, return the longest happy prefix of s. Return an empty string "" if no such prefix exists.
// 
//Example 1:
//Input: s = "level"
//Output: "l"
//Explanation: s contains 4 prefix excluding itself ("l", "le", "lev", "leve"), and suffix ("l", "el", "vel", "evel"). The largest prefix which is also suffix is given by "l".
//Example 2:
//Input: s = "ababab"
//Output: "abab"
//Explanation: "abab" is the largest prefix which is also suffix. They can overlap in the original string.
// 
//Constraints:
//	1 <= s.length <= 105
//	s contains only lowercase English letters.
char * longestPrefix(char * s){
    int len = strlen(s);
    for(int i = 0; i < len - 1; i++){
        if(strncmp(s, s + len - i - 1, i + 1) == 0){
            return s + len - i - 1;
        }
    }
    return "";
}