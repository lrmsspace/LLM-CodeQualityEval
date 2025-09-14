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
        vector<vector<string>> ans;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return ans;
        dict.erase(beginWord);
        dict.erase(endWord);
        unordered_map<string, int> steps{{beginWord, 1}};
        unordered_map<string, vector<string>> from{{beginWord, {}}};
        queue<string> q{{beginWord}};
        vector<string> ladder;
        bool found = false;
        while (!q.empty() && !found) {
            for (int i = q.size(); i > 0; --i) {
                string word = q.front(); q.pop();
                string next = word;
                for (int j = 0; j < word.size(); ++j) {
                    char old = next[j];
                    for (char ch = 'a'; ch <= 'z'; ++ch) {
                        next[j] = ch;
                        if (next == endWord) {
                            from[next].push_back(word);
                            found = true;
                        } else {
                            if (steps.count(next) && steps[next] == steps[word] + 1) {
                                from[next].push_back(word);
                            }
                        }
                        if (!dict.count(next)) continue;
                        dict.erase(next);
                        q.push(next);
                        steps[next] = steps[word] + 1;
                        from[next].push_back(word);
                    }
                    next[j] = old;
                }
            }
        }
        if (found) {
            ladder.push_back(endWord);
            dfs(from, ladder, beginWord, endWord, ans);
        }
        return ans;        
    }
};