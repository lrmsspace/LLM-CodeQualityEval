/**https://leetcode.com/problems/find-all-anagrams-in-a-string/ */
//Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.
// 
//Example 1:
//Input: s = "cbaebabacd", p = "abc"
//Output: [0,6]
//Explanation:
//The substring with start index = 0 is "cba", which is an anagram of "abc".
//The substring with start index = 6 is "bac", which is an anagram of "abc".
//Example 2:
//Input: s = "abab", p = "ab"
//Output: [0,1,2]
//Explanation:
//The substring with start index = 0 is "ab", which is an anagram of "ab".
//The substring with start index = 1 is "ba", which is an anagram of "ab".
//The substring with start index = 2 is "ab", which is an anagram of "ab".
// 
//Constraints:
//	1 <= s.length, p.length <= 3 * 104
//	s and p consist of lowercase English letters.
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        vector<int> p_count(26, 0);
        for (auto c : p) ++p_count[c - 'a'];

        vector<int> s_count(26, 0);
        int left = 0, right = 0, formed = 0;
        while (right < s.length()) {
            ++s_count[s[right] - 'a'];
            if (s_count[s[right] - 'a'] == p_count[s[right] - 'a']) ++formed;
            while (left <= right && formed == p.length()) {
                if (right - left + 1 == p.length()) result.push_back(left);
                --s_count[s[left] - 'a'];
                if (s_count[s[left] - 'a'] < p_count[s[left] - 'a']) --formed;
                ++left;
            }
            ++right;
        }
        return result;
    }
};