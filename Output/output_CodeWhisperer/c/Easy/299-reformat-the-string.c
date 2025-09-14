/**https://leetcode.com/problems/reformat-the-string/ */
//You are given an alphanumeric string s. (Alphanumeric string is a string consisting of lowercase English letters and digits).
//You have to find a permutation of the string where no letter is followed by another letter and no digit is followed by another digit. That is, no two adjacent characters have the same type.
//Return the reformatted string or return an empty string if it is impossible to reformat the string.
// 
//Example 1:
//Input: s = "a0b1c2"
//Output: "0a1b2c"
//Explanation: No two adjacent characters have the same type in "0a1b2c". "a0b1c2", "0a1b2c", "0c2a1b" are also valid permutations.
//Example 2:
//Input: s = "leetcode"
//Output: ""
//Explanation: "leetcode" has only characters so we cannot separate them by digits.
//Example 3:
//Input: s = "1229857369"
//Output: ""
//Explanation: "1229857369" has only digits so we cannot separate them by characters.
// 
//Constraints:
//	1 <= s.length <= 500
//	s consists of only lowercase English letters and/or digits.
char* reformat(char* s) {
    int len = strlen(s);
    char* result = (char*)malloc(sizeof(char) * (len + 1));
    int digitCount = 0;
    int letterCount = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            digitCount++;
        }
        else {
            letterCount++;
        }
    }
    if (abs(digitCount - letterCount) > 1) {
        return "";
    }
    int digitIndex = 0;
    int letterIndex = 0;
    if (digitCount > letterCount) {
        for (int i = 0; i < len; i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                result[i] = s[i];
                digitIndex++;
            }
            else {
                result[digitIndex + letterIndex * 2] = s[i];
                letterIndex++;
            }
        }
    }
    else {
        for (int i = 0; i < len; i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                result[letterIndex * 2 + digitIndex] = s[i];
                digitIndex++;
            }
            else {
                result[i] = s[i];
                letterIndex++;
            }
        }
    }
    result[len] = '\0';
    return result;
    
}