/**https://leetcode.com/problems/k-similar-strings/ */
//Strings s1 and s2 are k-similar (for some non-negative integer k) if we can swap the positions of two letters in s1 exactly k times so that the resulting string equals s2.
//Given two anagrams s1 and s2, return the smallest k for which s1 and s2 are k-similar.
// 
//Example 1:
//Input: s1 = "ab", s2 = "ba"
//Output: 1
//Explanation: The two string are 1-similar because we can use one swap to change s1 to s2: "ab" --> "ba".
//Example 2:
//Input: s1 = "abc", s2 = "bca"
//Output: 2
//Explanation: The two strings are 2-similar because we can use two swaps to change s1 to s2: "abc" --> "bac" --> "bca".
// 
//Constraints:
//	1 <= s1.length <= 20
//	s2.length == s1.length
//	s1 and s2 contain only lowercase letters from the set {'a', 'b', 'c', 'd', 'e', 'f'}.
//	s2 is an anagram of s1.
class Solution {
    public int kSimilarity(String s1, String s2) {
        int n = s1.length();
        int[] f = new int[n];
        int[] g = new int[n];
        for (int i = 0; i < n; ++i) {
            f[i] = i;
            g[i] = i;
        }
        int ans = 0;
        while (!f[0].equals(g[0])) {
            int[] u = f;
            f = g;
            g = u;
            for (int i = 0; i < n; ++i) {
                if (s1.charAt(i) == s2.charAt(i)) {
                    g[i] = f[i];
                }
            }
        }  
        return g[0];
    }
}