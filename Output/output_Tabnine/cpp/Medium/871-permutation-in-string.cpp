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
public:
    bool checkInclusion(string s1, string s2) {

        int n = s1.size(), m = s2.size();
        if (n > m) return false;
        
        vector<int> count(26, 0);
        for (char c : s1) ++count[c - 'a'];
        
        int left = 0, right = 0;
        while (right < m) {
            --count[s2[right] - 'a'];
            if (count[s2[right] - 'a'] >= 0) {
                ++right;
                if (right - left == n) {
                    return true;
                }
            } else {
                ++count[s2[left] - 'a'];
                ++left;
            }
        }
        
        return false;
        
    }
};