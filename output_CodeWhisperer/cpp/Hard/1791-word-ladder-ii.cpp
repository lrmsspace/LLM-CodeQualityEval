/**https://leetcode.com/problems/word-ladder-ii/ */
//A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:
//	Every adjacent pair of words differs by a single letter.
//	Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
//	sk == endWord
//Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].
// 
//Example 1:
//Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
//Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
//Explanation: There are 2 shortest transformation sequences:
//"hit" -> "hot" -> "dot" -> "dog" -> "cog"
//"hit" -> "hot" -> "lot" -> "log" -> "cog"
//Example 2:
//Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
//Output: []
//Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
// 
//Constraints:
//	1 <= beginWord.length <= 5
//	endWord.length == beginWord.length
//	1 <= wordList.length <= 500
//	wordList[i].length == beginWord.length
//	beginWord, endWord, and wordList[i] consist of lowercase English letters.
//	beginWord != endWord
//	All the words in wordList are unique.
//	The sum of all shortest transformation sequences does not exceed 105.
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord)) {
            return {};
        }
        
        unordered_map<string, int> steps{{beginWord, 1}};
        unordered_map<string, vector<string>> parents;
        vector<vector<string>> ans;
        queue<string> q{{beginWord}};
        const int l = beginWord.length();
        int step = 0;
        vector<string> foundPath{endWord};
        
        while (!q.empty() && foundPath.empty()) {
            ++step;
            for (int k = q.size(); k > 0; --k) {
                const string w = q.front(); q.pop();
                string x = w;
                for (int j = 0; j < l; ++j) {
                    const char y = x[j];
                    for (int i = 'a'; i <= 'z'; ++i) {
                        if (i == y) continue;
                        x[j] = i;
                        if (x == endWord) {
                            foundPath = vector<string>{w, x};
                        }
                        if (wordSet.count(x) && steps.count(x) == 0) {
                            q.push(x);
                            steps[x] = step + 1;
                            parents[x].push_back(w);
                        } else if (steps.count(x) == step + 1) {
                            parents[x].push_back(w);
                        }
                    }
                    x[j] = y;
                }
            }
        }
        
        if (foundPath.empty()) return {};
        
        function<void(string)> dfs = [&](string x) {
            if (x == beginWord) {
                ans.push_back(vector<string>(foundPath.rbegin(), foundPath.rend()));
                return;
            }
            for (const string& p : parents[x]) {
                foundPath.push_back(p);
                dfs(p);
                foundPath.pop_back();
            }
        };
        
        dfs(endWord);
        return ans;    
    }
};