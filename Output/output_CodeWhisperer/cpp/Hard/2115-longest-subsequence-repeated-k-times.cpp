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
class Solution {
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        int n = s.size();
        vector<int> cnt(26, 0);
        for (char c : s) {
            cnt[c - 'a']++;
        }
        string ans = "";
        for (int i = 0; i < 26; i++) {
            if (cnt[i] >= k) {
                ans += char(i + 'a');
            }
        }
        while (true) {
            string cur = "";
            for (int i = 0; i < ans.size(); i++) {
                for (int j = 0; j < k; j++) {
                    cur += ans[i];
                }
            }
            bool valid = true;
            int j = 0;
            for (int i = 0; i < n; i++) {
                if (s[i] == cur[j]) {
                    j++;
                }
                if (j == cur.size()) {
                    break;
                }
            }
            valid = (j == cur.size());
            if (valid) {
                return cur;
            }
            if (!next_permutation(ans.begin(), ans.end())) {
                break;
            }
        }
        return "";     
    }
};