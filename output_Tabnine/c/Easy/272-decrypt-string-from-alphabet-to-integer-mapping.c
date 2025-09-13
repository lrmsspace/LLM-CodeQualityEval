/**https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping/ */
//You are given a string s formed by digits and '#'. We want to map s to English lowercase characters as follows:
//	Characters ('a' to 'i') are represented by ('1' to '9') respectively.
//	Characters ('j' to 'z') are represented by ('10#' to '26#') respectively.
//Return the string formed after mapping.
//The test cases are generated so that a unique mapping will always exist.
// 
//Example 1:
//Input: s = "10#11#12"
//Output: "jkab"
//Explanation: "j" -> "10#" , "k" -> "11#" , "a" -> "1" , "b" -> "2".
//Example 2:
//Input: s = "1326#"
//Output: "acz"
// 
//Constraints:
//	1 <= s.length <= 1000
//	s consists of digits and the '#' letter.
//	s will be a valid string such that mapping is always possible.
char* freqAlphabets(char* s) {
    int freq[26] = {0};
    for(int i = 0; s[i]; i++) {
        if(s[i] >= 'a' && s[i] <= 'i')
            freq[s[i] - 'a']++;
        else if(s[i] >= 'j' && s[i] <= 'z')
            freq[s[i] - 'j' + 9]++;
    }
    
    char* res = (char*)malloc(sizeof(char) * (strlen(s) + 1));
    int j = 0;
    for(int i = 0; s[i]; i++) {
        if(s[i] >= 'a' && s[i] <= 'i') {
            res[j++] = 'a' + freq[s[i] - 'a'] - 1;
            freq[s[i] - 'a'] = 0;
        } else if(s[i] >= 'j' && s[i] <= 'z') {
            res[j++] = 'a' + freq[s[i] - 'j' + 9] - 1;
            freq[s[i] - 'j' + 9] = 0;
        }
    }
    res[j] = '\0';
    return res;
    
}