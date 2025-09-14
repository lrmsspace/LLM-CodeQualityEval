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
        vector<int> res;
        int n = s.size(), m = p.size();
        if (n < m) return res;
        vector<int> scnt(26, 0), pcnt(26, 0);
        for (int i = 0; i < m; ++i) {
            ++scnt[s[i] - 'a'];
            ++pcnt[p[i] - 'a'];
        }
        if (scnt == pcnt) res.push_back(0);
        for (int i = m; i < n; ++i) {
            ++scnt[s[i] - 'a'];
            --scnt[s[i - m] - 'a'];
            if (scnt == pcnt) res.push_back(i - m + 1);
        }
        return res;        
    }
};