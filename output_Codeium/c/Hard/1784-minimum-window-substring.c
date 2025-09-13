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
    int m = strlen(s);
    int n = strlen(t);
    int i = 0, j = 0, k = 0;
    int minLen = INT_MAX, minStart = 0, minEnd = 0;
    char *ans = (char*)malloc((m + 1) * sizeof(char));
    int count[256] = {0};
    for (i = 0; i < n; i++) {
        count[t[i]]++;
    }
    while (j < m) {
        if (count[s[j]] > 0) {
            count[s[j]]--;
            k++;
        }
        while (k == n) {
            if (j - i + 1 < minLen) {
                minLen = j - i + 1;
                minStart = i;
                minEnd = j;
            }
            if (count[s[i]] >= 0) {
                count[s[i]]++;
                k--;
            }
            i++;
        }
        j++;
    }
    if (minLen != INT_MAX) {
        strncpy(ans, s + minStart, minEnd - minStart + 1);
        ans[minEnd - minStart + 1] = '\0';
    }
    return ans;
}