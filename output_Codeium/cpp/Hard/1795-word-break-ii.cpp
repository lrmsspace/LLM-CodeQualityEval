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
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        unordered_map<int, vector<string>> memo;
        
        function<vector<string>(int)> dfs = [&](int start) {
            if (memo.count(start)) return memo[start];
            vector<string> res;
            if (start == s.size()) {
                res.push_back("");
                return res;
            }
            for (int end = start + 1; end <= s.size(); ++end) {
                string word = s.substr(start, end - start);
                if (wordSet.count(word)) {
                    vector<string> sublist = dfs(end);
                    for (const string& sub : sublist) {
                        res.push_back(word + (sub.empty() ? "" : " ") + sub);
                    }
                }
            }
            return memo[start] = res;
        };
        
        return dfs(0);

    }
};