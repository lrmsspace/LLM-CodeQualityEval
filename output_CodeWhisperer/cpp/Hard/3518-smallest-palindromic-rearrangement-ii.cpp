/*
 You are given a palindromic string s and an integer k.
 Return the k-th lexicographically smallest palindromic permutation of s. If there are fewer than k distinct palindromic permutations, return an empty string.
 Note: Different rearrangements that yield the same palindromic string are considered identical and are counted once.
 Example 1:
 Input: s = "abba", k = 2
 Output: "baab"
 Explanation:
 The two distinct palindromic rearrangements of "abba" are "abba" and "baab".
 Lexicographically, "abba" comes before "baab". Since k = 2, the output is "baab".
 Example 2:
 Input: s = "aa", k = 2
 Output: ""
 Explanation:
 There is only one palindromic rearrangement: "aa".
 The output is an empty string since k = 2 exceeds the number of possible rearrangements.
 Example 3:
 Input: s = "bacab", k = 1
 Output: "abcba"
 Explanation:
 The two distinct palindromic rearrangements of "bacab" are "abcba" and "bacab".
 Lexicographically, "abcba" comes before "bacab". Since k = 1, the output is "abcba".
 Constraints:
 1 <= s.length <= 104
 s consists of lowercase English letters.
 s is guaranteed to be palindromic.
 1 <= k <= 106
*/

class Solution {
public:
    string smallestPalindrome(string s, int k) {
        int n = s.size();
        if (k > 26) return "";
        vector<int> cnt(26);
        for (char c : s) cnt[c - 'a']++;
        int p = 0;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2 == 1) p++;
            if (p > 1) return "";
        }
        string t = s;
        for (int i = 0; i < n / 2; i++) {
            int j = n - 1 - i;
            if (s[i] != s[j]) {
                for (int c = 0; c < 26; c++) {
                    int l = cnt[c] / 2;
                    if (l < k) continue;
                    t[i] = t[j] = 'a' + c;
                    k--;
                    break;
                }
            }
        }
        if (k > 0) return "";
        for (int i = 0; i < n / 2; i++) {
            int j = n - 1 - i;
            if (t[i] != t[j]) return "";
        }
        return t;
    }
};