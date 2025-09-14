/**https://leetcode.com/problems/longest-duplicate-substring/ */
//Given a string s, consider all duplicated substrings: (contiguous) substrings of s that occur 2 or more times. The occurrences may overlap.
//Return any duplicated substring that has the longest possible length. If s does not have a duplicated substring, the answer is "".
// 
//Example 1:
//Input: s = "banana"
//Output: "ana"
//Example 2:
//Input: s = "abcd"
//Output: ""
// 
//Constraints:
//	2 <= s.length <= 3 * 104
//	s consists of lowercase English letters.
class Solution {
    public String longestDupSubstring(String s) {
        int n = s.length();
        int[] lcp = new int[n];
        int[] sa = new int[n];
        int[] ra = new int[n];
        int i, j, k = 0, h;
        for (i = 0; i < n - 1; i++) {
            if (k > 0) {
                k--;
            }
            j = sa[k - 1];
            if (s.charAt(i) == s.charAt(j)) {
                lcp[++k] = lcp[k - 1] + 1;
                sa[k] = j + 1;
            } else {
                lcp[0] = 0;
                k = 0;
                sa[0] = i;
            }
            ra[sa[k]] = k;
        }
        lcp[0] = 0;
        int maxLen = 0;
        int maxPos = 0;
        for (k = 0; k < n; k++) {
            if (lcp[k] > maxLen) {
                maxLen = lcp[k];
                maxPos = k;
            }
        }
        return s.substring(sa[maxPos], sa[maxPos] + maxLen);
    }
}