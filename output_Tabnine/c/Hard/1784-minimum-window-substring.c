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
    int len_s = strlen(s);
    int len_t = strlen(t);
    int count[256] = {0};
    int min_len = INT_MAX;
    int left = 0, right = 0;
    int min_start = 0;
    int unique_count = 0;
    
    for (int i = 0; i < len_t; i++) {
        count[t[i]]++;
    }
    
    while (right < len_s) {
        if (count[s[right]] > 0) {
            unique_count++;
        }
        count[s[right]]--;
        right++;
        
        while (unique_count == len_t) {
            if (right - left < min_len) {
                min_len = right - left;
                min_start = left;
            }
            
            if (count[s[left]] == 0) {
                unique_count--;
            }
            count[s[left]]++;
            left++;
        }
    }
    
    if (min_len == INT_MAX) {
        return "";
    }
    
    char* result = (char*)malloc((min_len + 1) * sizeof(char));
    strncpy(result, s + min_start, min_len);
    result[min_len] = '\0';
    return result;
}