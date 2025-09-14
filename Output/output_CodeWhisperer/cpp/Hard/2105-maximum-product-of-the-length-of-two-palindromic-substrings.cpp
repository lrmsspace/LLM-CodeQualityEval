/**https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-substrings/ */
//You are given a 0-indexed string s and are tasked with finding two non-intersecting palindromic substrings of odd length such that the product of their lengths is maximized.
//More formally, you want to choose four integers i, j, k, l such that 0 <= i <= j < k <= l < s.length and both the substrings s[i...j] and s[k...l] are palindromes and have odd lengths. s[i...j] denotes a substring from index i to index j inclusive.
//Return the maximum possible product of the lengths of the two non-intersecting palindromic substrings.
//A palindrome is a string that is the same forward and backward. A substring is a contiguous sequence of characters in a string.
// 
//Example 1:
//Input: s = "ababbb"
//Output: 9
//Explanation: Substrings "aba" and "bbb" are palindromes with odd length. product = 3 * 3 = 9.
//Example 2:
//Input: s = "zaaaxbbby"
//Output: 9
//Explanation: Substrings "aaa" and "bbb" are palindromes with odd length. product = 3 * 3 = 9.
// 
//Constraints:
//	2 <= s.length <= 105
//	s consists of lowercase English letters.
class Solution {
public:
    long long maxProduct(string s) {
        int n = s.length();
        vector<int> d1(n), d2(n);
        int l = 0, r = -1;
        for (int i = 0; i < n; i++) {
            int k = i > r ? 1 : min(d1[l + r - i], r - i + 1);
            while (i + k < n && i - k >= 0 && s[i + k] == s[i - k]) k++;
            d1[i] = k--;
            if (i + k > r) {
                l = i - k;
                r = i + k;
            }
        }
        l = 0, r = -1;
        for (int i = 0; i < n; i++) {
            int k = i > r ? 0 : min(d2[l + r - i + 1], r - i + 1);
            while (i + k < n && i - k - 1 >= 0 && s[i + k] == s[i - k - 1]) k++;
            d2[i] = k--;
            if (i + k > r) {
                l = i - k - 1;
                r = i + k;
            }
        }
        long long res = 0;
        for (int i = 0; i < n - 1; i++) {
            int j = n - 1 - d1[i];
            res = max(res, (long long)(2 * d1[i] - 1) * (2 * d2[j] - 1));
            j = n - 1 - d2[i];
            res = max(res, (long long)(2 * d1[j] - 1) * (2 * d2[i] - 1));
        }
        return res;     
    }
};