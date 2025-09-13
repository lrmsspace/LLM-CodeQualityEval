/**https://leetcode.com/problems/greatest-english-letter-in-upper-and-lower-case/ */
//Given a string of English letters s, return the greatest English letter which occurs as both a lowercase and uppercase letter in s. The returned letter should be in uppercase. If no such letter exists, return an empty string.
//An English letter b is greater than another letter a if b appears after a in the English alphabet.
// 
//Example 1:
//Input: s = "lEeTcOdE"
//Output: "E"
//Explanation:
//The letter 'E' is the only letter to appear in both lower and upper case.
//Example 2:
//Input: s = "arRAzFif"
//Output: "R"
//Explanation:
//The letter 'R' is the greatest letter to appear in both lower and upper case.
//Note that 'A' and 'F' also appear in both lower and upper case, but 'R' is greater than 'F' or 'A'.
//Example 3:
//Input: s = "AbCdEfGhIjK"
//Output: ""
//Explanation:
//There is no letter that appears in both lower and upper case.
// 
//Constraints:
//	1 <= s.length <= 1000
//	s consists of lowercase and uppercase English letters.
char* greatestLetter(char* s) {
    
    int lower[26] = {0};
    int upper[26] = {0};
    int i = 0;
    while (s[i] != '\0') {
        if (s[i] >= 'a' && s[i] <= 'z') {
            lower[s[i] - 'a'] = 1;
        } else if (s[i] >= 'A' && s[i] <= 'Z') {
            upper[s[i] - 'A'] = 1;
        }
        i++;
    }
    for (i = 25; i >= 0; i--) {
        if (lower[i] == 1 && upper[i] == 1) {
            char* result = (char*)malloc(2);
            result[0] = 'A' + i;
            result[1] = '\0';
            return result;
        }
    }
    char* result = (char*)malloc(1);
    result[0] = '\0';
    return result;
}