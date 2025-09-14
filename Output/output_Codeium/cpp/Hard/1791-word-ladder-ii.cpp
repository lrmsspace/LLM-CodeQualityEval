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
        if (wordSet.find(endWord) == wordSet.end()) return {};

        queue<vector<string>> q;
        q.push({beginWord});
        vector<vector<string>> res;
        bool found = false;

        while (!q.empty() && !found) {
            int size = q.size();
            unordered_set<string> visited;
            for (int i = 0; i < size; ++i) {
                vector<string> cur = q.front();
                q.pop();
                string last = cur.back();
                if (last == endWord) {
                    found = true;
                    res.push_back(cur);
                }
                for (int j = 0; j < last.size(); ++j) {
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (c == last[j]) continue;
                        string next = last.substr(0, j) + c + last.substr(j + 1);
                        if (wordSet.find(next) != wordSet.end() && visited.find(next) == visited.end()) {
                            visited.insert(next);
                            vector<string> nextCur = cur;
                            nextCur.push_back(next);
                            q.push(nextCur);
                        }
                    }
                }
            }
        }
        return res;
    }
};