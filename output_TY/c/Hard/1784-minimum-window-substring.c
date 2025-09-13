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
char * minWindow(char * s, char * t){
    int s_len = strlen(s);
    int t_len = strlen(t);
    int *t_hash = (int *)malloc(sizeof(int) * 128);
    int *s_hash = (int *)malloc(sizeof(int) * 128);
    int *s_hash_temp = (int *)malloc(sizeof(int) * 128);
    int *t_hash_temp = (int *)malloc(sizeof(int) * 128);
    memset(t_hash, 0, sizeof(int) * 128);
    memset(s_hash, 0, sizeof(int) * 128);
    memset(s_hash_temp, 0, sizeof(int) * 128);
    memset(t_hash_temp, 0, sizeof(int) * 128);
    for (int i = 0; i < t_len; i++) {
        t_hash[t[i]]++;
    }
    for (int i = 0; i < t_len; i++) {
        s_hash_temp[s[i]]++;
    }
    for (int i = 0; i < t_len; i++) {
        t_hash_temp[t[i]]++;
    }
    for (int i = 0; i < s_len; i++) {
        if (i >= t_len - 1) {
            if (memcmp(t_hash, t_hash_temp, sizeof(int) * 128) == 0) {
                return s + i - t_len + 1;
            }
            s_hash_temp[s[i - (t_len - 1)]]--;
            s_hash_temp[s[i]]++;
        }
    }
    return NULL;
}