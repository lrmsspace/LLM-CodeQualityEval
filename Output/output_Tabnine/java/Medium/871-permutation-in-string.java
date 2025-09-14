/**https://leetcode.com/problems/permutation-in-string/ */
//Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
//In other words, return true if one of s1's permutations is the substring of s2.
// 
//Example 1:
//Input: s1 = "ab", s2 = "eidbaooo"
//Output: true
//Explanation: s2 contains one permutation of s1 ("ba").
//Example 2:
//Input: s1 = "ab", s2 = "eidboaoo"
//Output: false
// 
//Constraints:
//	1 <= s1.length, s2.length <= 104
//	s1 and s2 consist of lowercase English letters.
class Solution {
    public boolean checkInclusion(String s1, String s2) {
        int n = s2.length(), m = s1.length();
        if (n < m) return false;
        
        int[] freq1 = new int[26], freq2 = new int[26];
        for (int i = 0; i < m; i++) {
            freq1[s1.charAt(i) - 'a']++;
            freq2[s2.charAt(i) - 'a']++;
        }
        
        for (int i = m; i < n; i++) {
            if (isEqual(freq1, freq2)) return true;
            freq2[s2.charAt(i) - 'a']++;
            freq2[s2.charAt(i - m) - 'a']--;
        }
        
        return isEqual(freq1, freq2);
        
    }
}