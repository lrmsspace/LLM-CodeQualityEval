/**https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings/ */
//Given a string s of lowercase letters, you need to find the maximum number of non-empty substrings of s that meet the following conditions:
//	The substrings do not overlap, that is for any two substrings s[i..j] and s[x..y], either j < x or i > y is true.
//	A substring that contains a certain character c must also contain all occurrences of c.
//Find the maximum number of substrings that meet the above conditions. If there are multiple solutions with the same number of substrings, return the one with minimum total length. It can be shown that there exists a unique solution of minimum total length.
//Notice that you can return the substrings in any order.
// 
//Example 1:
//Input: s = "adefaddaccc"
//Output: ["e","f","ccc"]
//Explanation: The following are all the possible substrings that meet the conditions:
//[
//  "adefaddaccc"
//  "adefadda",
//  "ef",
//  "e",
//  "f",
//  "ccc",
//]
//If we choose the first string, we cannot choose anything else and we'd get only 1. If we choose "adefadda", we are left with "ccc" which is the only one that doesn't overlap, thus obtaining 2 substrings. Notice also, that it's not optimal to choose "ef" since it can be split into two. Therefore, the optimal way is to choose ["e","f","ccc"] which gives us 3 substrings. No other solution of the same number of substrings exist.
//Example 2:
//Input: s = "abbaccd"
//Output: ["d","bb","cc"]
//Explanation: Notice that while the set of substrings ["d","abba","cc"] also has length 3, it's considered incorrect since it has larger total length.
// 
//Constraints:
//	1 <= s.length <= 105
//	s contains only lowercase English letters.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** maxNumOfSubstrings(char* s, int* returnSize) {

    int len = strlen(s);
    
    // Find the first and last occurrence of each character
    int first[26];
    int last[26];
    
    // Initialize with invalid values
    for (int i = 0; i < 26; i++) {
        first[i] = len;
        last[i] = -1;
    }
    
    // Find first and last occurrences
    for (int i = 0; i < len; i++) {
        int charIndex = s[i] - 'a';
        first[charIndex] = first[charIndex] < i ? first[charIndex] : i;
        last[charIndex] = i;
    }
    
    // Create array to store valid substrings
    Substring* validSubstrings = (Substring*)malloc(len * sizeof(Substring));
    int validCount = 0;
    
    // Find all valid substrings
    for (int i = 0; i < len; i++) {
        // Only process if this is the first occurrence of the character
        if (i == first[s[i] - 'a']) {
            int end = findValidRange(s, i, first, last);
            if (end != -1) {
                validSubstrings[validCount].start = i;
                validSubstrings[validCount].end = end;
                validSubstrings[validCount].length = end - i + 1;
                validCount++;
            }
        }
    }
    
    // Sort valid substrings by end position for greedy selection
    for (int i = 0; i < validCount; i++) {
        for (int j = i + 1; j < validCount; j++) {
            if (validSubstrings[i].end > validSubstrings[j].end) {
                Substring temp = validSubstrings[i];
                validSubstrings[i] = validSubstrings[j];
                validSubstrings[j] = temp;
            }
        }
    }
    
    // Greedily select non-overlapping substrings
    Substring* selectedSubstrings = (Substring*)malloc(validCount * sizeof(Substring));
    int selectedCount = 0;
    int lastEnd = -1;
    
    for (int i = 0; i < validCount; i++) {
        if (validSubstrings[i].start > lastEnd) {
            selectedSubstrings[selectedCount++] = validSubstrings[i];
            lastEnd = validSubstrings[i].end;
        }
    }
    
    // Create the result array
    char** result = (char**)malloc(selectedCount * sizeof(char*));
    *returnSize = selectedCount;
    
    for (int i = 0; i < selectedCount; i++) {
        int substringLength = selectedSubstrings[i].length;
        result[i] = (char*)malloc((substringLength + 1) * sizeof(char));
        
        // Copy the substring
        strncpy(result[i], s + selectedSubstrings[i].start, substringLength);
        result[i][substringLength] = '\0';
    }
    
    // Free allocated memory
    free(validSubstrings);
    free(selectedSubstrings);
    
    return result;  



}