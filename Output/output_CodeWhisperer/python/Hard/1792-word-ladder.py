#https://leetcode.com/problems/word-ladder/
#A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:
#	Every adjacent pair of words differs by a single letter.
#	Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
#	sk == endWord
#Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.
# 
#Example 1:
#Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
#Output: 5
#Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
#Example 2:
#Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
#Output: 0
#Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
# 
#Constraints:
#	1 <= beginWord.length <= 10
#	endWord.length == beginWord.length
#	1 <= wordList.length <= 5000
#	wordList[i].length == beginWord.length
#	beginWord, endWord, and wordList[i] consist of lowercase English letters.
#	beginWord != endWord
#	All the words in wordList are unique.
class Solution(object):
    def ladderLength(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: List[str]
        :rtype: int
        """
        wordList = set(wordList)
        if endWord not in wordList:
            return 0
        wordList.add(beginWord)
        wordList.add(endWord)
        wordList = list(wordList)
        n = len(wordList)
        start = wordList.index(beginWord)
        end = wordList.index(endWord)
        graph = [[] for _ in range(n)]
        for i in range(n):
            for j in range(i+1, n):
                if sum(c1 != c2 for c1, c2 in zip(wordList[i], wordList[j])) == 1:
                    graph[i].append(j)
                    graph[j].append(i)
        dist = [float('inf')] * n
        dist[start] = 0
        queue = [start]
        while queue:
            u = queue.pop(0)
            for v in graph[u]:
                if dist[v] == float('inf'):
                    dist[v] = dist[u] + 1
                    queue.append(v)
        return dist[end] + 1 if dist[end] != float('inf') else 0
        