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
/**
 * @param {string} beginWord
 * @param {string} endWord
 * @param {string[]} wordList
 * @return {string[][]}
 */
var findLadders = function(beginWord, endWord, wordList) {
    var result = [];
    var queue = [];
    var visited = new Set();
    var map = new Map();
    queue.push(beginWord);
    visited.add(beginWord);
    var found = false;
    while(queue.length > 0){
        var size = queue.length;
        for(var i = 0; i < size; i++){
            var word = queue.shift();
            for(var j = 0; j < wordList.length; j++){
                var newWord = wordList[j];
                if(visited.has(newWord)) continue;
                if(isValid(word, newWord)){
                    if(newWord === endWord){
                        found = true;
                        map.set(newWord, [word]);
                        break;
                    }else{
                        queue.push(newWord);
                        map.set(newWord, [word]);
                        visited.add(newWord);
                    }
                }
            }
        }
    }
    if(found){
        var path = map.get(endWord);
        result.push(path);
    }
    return result;
};