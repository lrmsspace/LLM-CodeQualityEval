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
        int s1_size = s1.size();
        int s2_size = s2.size();

        if (s1_size > s2_size)
            return false;

        vector<int> s1_hash(26, 0);
        vector<int> s2_hash(26, 0);

        for (int i = 0; i < s1_size; i++)
        {
            s1_hash[s1[i] - 'a']++;
            s2_hash[s2[i] - 'a']++;
        }

        for (int i = 0; i < s2_size - s1_size; i++)
        {
            if (s1_hash == s2_hash)
                return true;

            s2_hash[s2[i] - 'a']--;
            s2_hash[s2[i + s1_size] - 'a']++;
        }
        return s1_hash == s2_hash;
    }
};