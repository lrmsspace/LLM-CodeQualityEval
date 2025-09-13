/**https://leetcode.com/problems/minimum-window-substring/ */
//Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".
//The testcases will be generated such that the answer is unique.
// 
//Example 1:
//Input: s = "ADOBECODEBANC", t = "ABC"
//Output: "BANC"
//Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
//Example 2:
//Input: s = "a", t = "a"
//Output: "a"
//Explanation: The entire string s is the minimum window.
//Example 3:
//Input: s = "a", t = "aa"
//Output: ""
//Explanation: Both 'a's from t must be included in the window.
//Since the largest window of s only has one 'a', return empty string.
// 
//Constraints:
//	m == s.length
//	n == t.length
//	1 <= m, n <= 105
//	s and t consist of uppercase and lowercase English letters.
// 
//Follow up: Could you find an algorithm that runs in O(m + n) time?
char* minWindow(char* s, char* t) {
    int sLen = strlen(s);
    int tLen = strlen(t);
    if (sLen < tLen) {
        return "";
    }

    int tCount[128] = {0};
    int sCount[128] = {0};
    for (int i = 0; i < tLen; i++) {
        tCount[t[i]]++;
    }

    int start = 0;
    int end = 0;
    int minStart = 0;
    int minLen = INT_MAX;
    int count = 0;

    while (end < sLen) {
        sCount[s[end]]++;
        if (sCount[s[end]] <= tCount[s[end]]) {
            count++;
        }

        while (count == tLen) {
            if (end - start + 1 < minLen) {
                minLen = end - start + 1;
                minStart = start;
            }

            sCount[s[start]]--;
            if (sCount[s[start]] < tCount[s[start]]) {
                count--;
            }

            start++;
        }

        end++;
    }

    if (minLen == INT_MAX) {
        return "";
    } else {
        char* result = (char*)malloc((minLen + 1) * sizeof(char));
        strncpy(result, s + minStart, minLen);
        result[minLen] = '\0';
        return result;
    }
    
}