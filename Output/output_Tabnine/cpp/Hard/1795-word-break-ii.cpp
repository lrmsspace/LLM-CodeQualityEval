/**https://leetcode.com/problems/word-break-ii/ */
//Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.
//Note that the same word in the dictionary may be reused multiple times in the segmentation.
// 
//Example 1:
//Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
//Output: ["cats and dog","cat sand dog"]
//Example 2:
//Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
//Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
//Explanation: Note that you are allowed to reuse a dictionary word.
//Example 3:
//Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
//Output: []
// 
//Constraints:
//	1 <= s.length <= 20
//	1 <= wordDict.length <= 1000
//	1 <= wordDict[i].length <= 10
//	s and wordDict[i] consist of only lowercase English letters.
//	All the strings of wordDict are unique.
//	Input is generated in a way that the length of the answer doesn't exceed 105.
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<vector<string>> dp(n + 1);
        dp[0].push_back("");
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (dict.count(s.substr(j, i - j)) &&!dp[j].empty()) {
                    for (const auto& word : dp[j]) {
                        dp[i].push_back(word + (word.empty()? "" : " ") + s.substr(j, i - j));
                    }
                }
            }
        }
        
        return dp[n];
        
    }
};