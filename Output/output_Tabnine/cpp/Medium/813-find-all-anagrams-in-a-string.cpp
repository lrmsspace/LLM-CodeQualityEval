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
        if (s.length() < p.length()) return result;
        
        unordered_map<char, int> need, window;
        for (char c : p) need[c]++;
        
        int left = 0, right = 0, count = 0;
        
        while (right < s.length()) {
            char c = s[right];
            right++;
            
            if (need.find(c)!= need.end()) {
                window[c]++;
                if (window[c] == need[c]) count++;
            }
            
            while (right - left >= p.length()) {
                if (count == need.size()) result.push_back(left);
                
                char d = s[left];
                left++;
                
                if (need.find(d)!= need.end()) {
                    if (window[d] == need[d]) count--;
                    window[d]--;
                }
            }
        }
        
        return result;
        
    }
};