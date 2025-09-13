/**https://leetcode.com/problems/longest-subsequence-repeated-k-times/ */
//You are given a string s of length n, and an integer k. You are tasked to find the longest subsequence repeated k times in string s.
//A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.
//A subsequence seq is repeated k times in the string s if seq * k is a subsequence of s, where seq * k represents a string constructed by concatenating seq k times.
//	For example, "bba" is repeated 2 times in the string "bababcba", because the string "bbabba", constructed by concatenating "bba" 2 times, is a subsequence of the string "bababcba".
//Return the longest subsequence repeated k times in string s. If multiple such subsequences are found, return the lexicographically largest one. If there is no such subsequence, return an empty string.
// 
//Example 1:
//Input: s = "letsleetcode", k = 2
//Output: "let"
//Explanation: There are two longest subsequences repeated 2 times: "let" and "ete".
//"let" is the lexicographically largest one.
//Example 2:
//Input: s = "bb", k = 2
//Output: "b"
//Explanation: The longest subsequence repeated 2 times is "b".
//Example 3:
//Input: s = "ab", k = 2
//Output: ""
//Explanation: There is no subsequence repeated 2 times. Empty string is returned.
// 
//Constraints:
//	n == s.length
//	2 <= n, k <= 2000
//	2 <= n < k * 8
//	s consists of lowercase English letters.
char * longestSubsequenceRepeatedK(char * s, int k){
    int n = strlen(s);
    int i, j, cnt[26] = {0}, max_cnt = 0, max_idx = -1;
    for (i = 0; i < n; i++) {
        cnt[s[i] - 'a']++;
    }
    for (i = 0; i < 26; i++) {
        if (cnt[i] >= k) {
            if (cnt[i] > max_cnt) {
                max_cnt = cnt[i];
                max_idx = i;
            }
        }
    }
    if (max_idx == -1) {
        return "";
    }
    char *res = (char *)malloc(max_cnt + 1);
    for (i = 0; i < max_cnt; i++) {
        res[i] = 'a' + max_idx;
    }
    res[i] = '\0';
    return res;

}