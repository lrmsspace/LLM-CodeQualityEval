/*
 Given a string s of length n and an integer k, determine whether it is possible to select k disjoint special substrings.
 A special substring is a substring where:
 Any character present inside the substring should not appear outside it in the string.
 The substring is not the entire string s.
 Note that all k substrings must be disjoint, meaning they cannot overlap.
 Return true if it is possible to select k such disjoint special substrings; otherwise, return false.
 Example 1:
 Input: s = "abcdbaefab", k = 2
 Output: true
 Explanation:
 We can select two disjoint special substrings: "cd" and "ef".
 "cd" contains the characters 'c' and 'd', which do not appear elsewhere in s.
 "ef" contains the characters 'e' and 'f', which do not appear elsewhere in s.
 Example 2:
 Input: s = "cdefdc", k = 3
 Output: false
 Explanation:
 There can be at most 2 disjoint special substrings: "e" and "f". Since k = 3, the output is false.
 Example 3:
 Input: s = "abeabe", k = 0
 Output: true
 Constraints:
 2 <= n == s.length <= 5 * 104
 0 <= k <= 26
 s consists only of lowercase English letters.
*/

class Solution {
    public boolean maxSubstringLength(String s, int k) {
        int n = s.length();
        int[][] charCount = new int[n + 1][26];
        for (int i = 0; i < n; i++) {
            charCount[i + 1] = charCount[i].clone();
            charCount[i + 1][s.charAt(i) - 'a']++;
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int[] left = charCount[i];
                int[] right = charCount[j + 1];
                int distinct = 0;
                for (int c = 0; c < 26; c++) {
                    if (right[c] - left[c] > 0) {
                        distinct++;
                    }
                }
                if (distinct <= k) {
                    return true;
                }
            }
        }
        
        return false;        
    }
}