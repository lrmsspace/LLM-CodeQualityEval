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
        int ans = 0;
        vector<vector<pair<int, int>>> pos(26);
        for (int i = 0; i < s.size(); i++) {
            pos[s[i] - 'a'].push_back({i, 0});
        }
        for (string& word : words) {
            int i = 0;
            bool flag = true;
            for (char c : word) {
                auto it = lower_bound(pos[c - 'a'].begin(), pos[c - 'a'].end(), make_pair(i, 0));
                if (it == pos[c - 'a'].end()) {
                    flag = false;
                    break;
                }
                i = it->first + 1;
            }
            if (flag) {
                ans++;
            }
        }
        return ans;        
    }
};