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
        int n = s.size();
        vector<int> left(n), right(n);
        vector<int> odd(n);
        int l = 0, r = -1;
        for (int i = 0; i < n; i++) {
            int k = i > r ? 1 : min(right[l + r - i], r - i + 1);
            while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
                k++;
            }
            left[i] = k--;
            if (i + k > r) {
                l = i - k;
                r = i + k;
            }
        }
        l = 0, r = -1;
        for (int i = 0; i < n; i++) {
            int k = i > r ? 0 : min(right[l + r - i + 1], r - i + 1);
            while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
                k++;
            }
            right[i] = k--;
            if (i + k > r) {
                l = i - k - 1;
                r = i + k;
            }
        }
        for (int i = 0; i < n; i++) {
            odd[i] = 2 * min(left[i], right[i]) - 1;
        }
        for (int i = 1; i < n; i++) {
            left[i] = max(left[i], left[i - 1] - 2);
        }
        for (int i = n - 2; i >= 0; i--) {
            right[i] = max(right[i], right[i + 1] - 2);
        }
        long long ans = 0;
        for (int i = 0; i < n - 1; i++) {
            ans = max(ans, (long long)left[i] * right[i + 1]);
        }
        return ans;        
    }
};