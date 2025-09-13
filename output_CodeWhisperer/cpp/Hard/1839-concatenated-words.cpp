/**https://leetcode.com/problems/concatenated-words/ */
//Given an array of strings words (without duplicates), return all the concatenated words in the given list of words.
//A concatenated word is defined as a string that is comprised entirely of at least two shorter words (not necessarily distinct) in the given array.
// 
//Example 1:
//Input: words = ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
//Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]
//Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats"; 
//"dogcatsdog" can be concatenated by "dog", "cats" and "dog"; 
//"ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".
//Example 2:
//Input: words = ["cat","dog","catdog"]
//Output: ["catdog"]
// 
//Constraints:
//	1 <= words.length <= 104
//	1 <= words[i].length <= 30
//	words[i] consists of only lowercase English letters.
//	All the strings of words are unique.
//	1 <= sum(words[i].length) <= 105
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) 
    {
        unordered_set<string> wordSet(words.begin(), words.end());
        vector<string> result;
        
        for (const string& word : words) {
            int n = word.length();
            vector<bool> dp(n + 1, false);
            dp[0] = true;
            
            for (int i = 0; i < n; i++) {
                if (!dp[i]) continue;
                
                for (int j = i + 1; j <= n; j++) {
                    if (j - i < n && wordSet.count(word.substr(i, j - i))) {
                        dp[j] = true;
                    }
                }
                
                if (dp[n]) {
                    result.push_back(word);
                    break;
                }
            }
        }
        
        return result;
        
    }
};