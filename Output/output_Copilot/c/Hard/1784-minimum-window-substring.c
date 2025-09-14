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
    int tmap[128] = {0};
    int smap[128] = {0};
    int i, j, count = 0, min = INT_MAX, start = 0, end = 0, left = 0;
    char *res = "";
    for (i = 0; t[i]; i++) tmap[t[i]]++;
    for (i = 0, j = 0; s[j]; j++) {
        if (tmap[s[j]] == 0) continue;
        if (smap[s[j]] < tmap[s[j]]) count++;
        smap[s[j]]++;
        if (count == i) {
            while (tmap[s[i]] == 0 || smap[s[i]] > tmap[s[i]]) {
                if (smap[s[i]] > tmap[s[i]]) smap[s[i]]--;
                i++;
            }
            if (j - i < min) {
                min = j - i;
                start = i;
                end = j;
            }
            smap[s[i]]--;
            count--;
            i++;
        }
    }
    if (min == INT_MAX) return "";
    res = (char *)malloc(sizeof(char) * (min + 2));
    for (i = start; i <= end; i++) res[i - start] = s[i];
    res[i - start] = '\0';
    return res;    
}