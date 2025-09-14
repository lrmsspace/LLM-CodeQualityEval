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
vector<int> maxLengthPrefix(n), maxLengthSuffix(n);

// Function to expand around center and calculate maximum odd-length palindromes
auto expandAroundCenter = [&](int left, int right, vector<int>& maxLength) {
    while (left >= 0 && right < n && s[left] == s[right]) {
        int length = right - left + 1;
        if (length % 2 == 1) {  // must be of odd length
            maxLength[right] = max(maxLength[right], length);
        }
        left--;
        right++;
    }
};

// Calculate max odd-length palindromes ending at each index
for (int center = 0; center < n; ++center) {
    expandAroundCenter(center, center, maxLengthPrefix); // odd-length palindromes
}

// Calculate max odd-length palindromes starting at each index
for (int center = 0; center < n; ++center) {
    expandAroundCenter(center, center, maxLengthSuffix); // odd-length palindromes
}

// Calculate the maximum product of lengths
long long maxProduct = 0;
for (int i = 1; i < n; ++i) {
    maxLengthPrefix[i] = max(maxLengthPrefix[i], maxLengthPrefix[i - 1]);
}
for (int i = n - 2; i >= 0; --i) {
    maxLengthSuffix[i] = max(maxLengthSuffix[i], maxLengthSuffix[i + 1]);
}

for (int i = 0; i < n - 1; ++i) {
    maxProduct = max(maxProduct, (long long)maxLengthPrefix[i] * maxLengthSuffix[i + 1]);
}

return maxProduct;
    }
};