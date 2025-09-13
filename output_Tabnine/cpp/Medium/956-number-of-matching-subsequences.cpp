/**https://leetcode.com/problems/number-of-matching-subsequences/ */
//Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.
//A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
//	For example, "ace" is a subsequence of "abcde".
// 
//Example 1:
//Input: s = "abcde", words = ["a","bb","acd","ace"]
//Output: 3
//Explanation: There are three strings in words that are a subsequence of s: "a", "acd", "ace".
//Example 2:
//Input: s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
//Output: 2
// 
//Constraints:
//	1 <= s.length <= 5 * 104
//	1 <= words.length <= 5000
//	1 <= words[i].length <= 50
//	s and words[i] consist of only lowercase English letters.
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int m = s.length(), n = words.size();
        vector<vector<int>> next(26);
        for (int i = 0; i < m; ++i) {
            next[s[i] - 'a'].push_back(i);
        }
        
        int res = 0;
        for (string& word : words) {
            bool match = true;
            int pos = -1;
            for (char c : word) {
                auto it = lower_bound(next[c - 'a'].begin(), next[c - 'a'].end(), pos + 1);
                if (it == next[c - 'a'].end()) {
                    match = false;
                    break;
                }
                pos = *it;
            }
            if (match) ++res;
        }
        
        return res;
        
    }
};