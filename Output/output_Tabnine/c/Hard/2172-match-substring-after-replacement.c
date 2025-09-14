/**https://leetcode.com/problems/match-substring-after-replacement/ */
//You are given two strings s and sub. You are also given a 2D character array mappings where mappings[i] = [oldi, newi] indicates that you may perform the following operation any number of times:
//	Replace a character oldi of sub with newi.
//Each character in sub cannot be replaced more than once.
//Return true if it is possible to make sub a substring of s by replacing zero or more characters according to mappings. Otherwise, return false.
//A substring is a contiguous non-empty sequence of characters within a string.
// 
//Example 1:
//Input: s = "fool3e7bar", sub = "leet", mappings = [["e","3"],["t","7"],["t","8"]]
//Output: true
//Explanation: Replace the first 'e' in sub with '3' and 't' in sub with '7'.
//Now sub = "l3e7" is a substring of s, so we return true.
//Example 2:
//Input: s = "fooleetbar", sub = "f00l", mappings = [["o","0"]]
//Output: false
//Explanation: The string "f00l" is not a substring of s and no replacements can be made.
//Note that we cannot replace '0' with 'o'.
//Example 3:
//Input: s = "Fool33tbaR", sub = "leetd", mappings = [["e","3"],["t","7"],["t","8"],["d","b"],["p","b"]]
//Output: true
//Explanation: Replace the first and second 'e' in sub with '3' and 'd' in sub with 'b'.
//Now sub = "l33tb" is a substring of s, so we return true.
// 
//Constraints:
//	1 <= sub.length <= s.length <= 5000
//	0 <= mappings.length <= 1000
//	mappings[i].length == 2
//	oldi != newi
//	s and sub consist of uppercase and lowercase English letters and digits.
//	oldi and newi are either uppercase or lowercase English letters or digits.
bool matchReplacement(char* s, char* sub, char** mappings, int mappingsSize, int* mappingsColSize) {
    int sLen = strlen(s);
    int subLen = strlen(sub);
    
    if (subLen > sLen) return false;
    
    // Create a 2D array to store the indices of sub in s for each character
    int** subIndices = (int**)malloc(sizeof(int*) * 26);
    for (int i = 0; i < 26; i++) {
        subIndices[i] = (int*)malloc(sizeof(int) * subLen);
        memset(subIndices[i], -1, sizeof(int) * subLen);
    }
    
    // Populate the subIndices array
    for (int i = 0; i < sLen; i++) {
        char c = s[i] - 'a';
        subIndices[c][subIndices[c][subLen - 1]++] = i;
    }
    
    // Create a boolean array to store whether we can match sub with s at a certain index
    bool* canMatch = (bool*)malloc(sizeof(bool) * sLen);
    memset(canMatch, false, sizeof(bool) * sLen);
    
    // Iterate through the sub string
    for (int i = 0; i <= sLen - subLen; i++) {
        bool match = true;
        
        // Check if the current substring matches sub
        for (int j = 0; j < subLen; j++) {
            char c = sub[j];
            int index = subIndices[c - 'a'][j];
            
            if (index == -1 || (i > 0 && s[i - 1]!= mappings[index][0])) {
                match = false;
                break;
            }
        }
        
        // If the current substring matches sub, update canMatch
        if (match) {
            canMatch[i + subLen - 1] = true;
        }
    }
    
    // Check if canMatch[sLen - 1] is true
    return canMatch[sLen - 1];
    
}