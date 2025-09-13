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
long long maxProduct(char* s) {
    int n = strlen(s);
    int m = 2 * n - 1;
    int *len = (int *)malloc(m * sizeof(int));
    int *p = (int *)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        len[i] = 0;
        p[i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int l = i / 2;
        int r = i / 2 + i % 2;
        while (l >= 0 && r < n && s[l] == s[r]) {
            len[i]++;
            l--;
            r++;
        }
    }
    for (int i = 0; i < m; i++) {
        int l = i / 2 - 1;
        int r = i / 2 + i % 2;
        while (l >= 0 && r < n && s[l] == s[r]) {
            p[i]++;
            l--;
            r++;
        }
    }
    int *left = (int *)malloc(m * sizeof(int));
    int *right = (int *)malloc(m * sizeof(int));
    left[0] = len[0];
    right[m - 1] = len[m - 1];
    for (int i = 1; i < m; i++) {
        left[i] = fmax(left[i - 1], len[i]);
    }
    for (int i = m - 2; i >= 0; i--) {
        right[i] = fmax(right[i + 1], len[i]);
    }
    long long ans = 0;
    for (int i = 0; i < m - 1; i++) {
        ans = fmax(ans, (long long)left[i] * right[i + 1]);
    }
    for (int i = 0; i < m - 2; i++) {
        ans = fmax(ans, (long long)len[i] * p[i + 1]);
    }
    free(len);
    free(p);
    free(left);
    free(right);
    return ans;    
}