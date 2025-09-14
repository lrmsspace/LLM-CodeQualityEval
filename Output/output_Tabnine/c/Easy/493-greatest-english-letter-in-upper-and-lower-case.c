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
    int lowerCount[26] = {0};
    int upperCount[26] = {0};
    
    for (int i = 0; s[i]; i++) {
        if (islower(s[i])) {
            lowerCount[s[i] - 'a']++;
        } else if (isupper(s[i])) {
            upperCount[s[i] - 'A']++;
        }
    }
    
    char* result = "";
    for (int i = 25; i >= 0; i--) {
        if (lowerCount[i] > 0 && upperCount[i] > 0) {
            result = malloc(2);
            result[0] = i + 'A';
            result[1] = '\0';
            break;
        }
    }
    
    return result;
    
}