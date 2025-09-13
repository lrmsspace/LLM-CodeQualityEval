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
        if (!wordSet.count(endWord)) return {};
        
        queue<pair<string, vector<string>>> q;
        q.push({beginWord, {beginWord}});
        
        unordered_map<string, vector<string>> parent;
        
        while (!q.empty()) {

            auto [word, path] = q.front();
            q.pop();
            
            if (word == endWord) break;
            
            for (int i = 0; i < word.size(); ++i) {
                char original = word[i];
                
                for (char c = 'a'; c <= 'z'; ++c) {
                    word[i] = c;
                    
                    if (wordSet.count(word)) {
                        parent[word].push_back(word);
                        q.push({word, path});
                    }
                }
                
                word[i] = original;
            }
        }
        
        vector<vector<string>> result;
        
        for (const auto& [word, parentWord] : parent) {
            vector<string> path = {word, endWord};
            
            while (parentWord!= beginWord) {
                path.insert(path.begin(), parentWord);
                parentWord = parent[parentWord];
            }
            
            path.insert(path.begin(), beginWord);
            result.push_back(path);
        }
        
        return result;
        
    }
};