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
        vector<int> s1map(26, 0);
        vector<int> s2map(26, 0);
        for (int i = 0; i < s1.size(); i++) {
            s1map[s1[i] - 'a']++;
            s2map[s2[i] - 'a']++;
        }
        if (s1map == s2map) {
            return true;
        }
        for (int i = s1.size(); i < s2.size(); i++) {
            s2map[s2[i] - 'a']++;
            s2map[s2[i - s1.size()] - 'a']--;
            if (s1map == s2map) {
                return true;
            }
        }
        return false        
    }
};