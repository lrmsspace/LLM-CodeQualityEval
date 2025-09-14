#https://leetcode.com/problems/word-ladder-ii/
#A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:
#	Every adjacent pair of words differs by a single letter.
#	Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
#	sk == endWord
#Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].
# 
#Example 1:
#Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
#Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
#Explanation: There are 2 shortest transformation sequences:
#"hit" -> "hot" -> "dot" -> "dog" -> "cog"
#"hit" -> "hot" -> "lot" -> "log" -> "cog"
#Example 2:
#Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
#Output: []
#Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
# 
#Constraints:
#	1 <= beginWord.length <= 5
#	endWord.length == beginWord.length
#	1 <= wordList.length <= 500
#	wordList[i].length == beginWord.length
#	beginWord, endWord, and wordList[i] consist of lowercase English letters.
#	beginWord != endWord
#	All the words in wordList are unique.
#	The sum of all shortest transformation sequences does not exceed 105.   
class Solution(object):
    def findLadders(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: List[str]
        :rtype: List[List[str]]
        """
        wordList = set(wordList)
        if endWord not in wordList:
            return []
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
        res = []
        def dfs(u, path):
            if u == start:
                res.append(path[::-1])
                return
            for v in graph[u]:
                if dist[v] == dist[u] - 1:
                    dfs(v, path + [wordList[v]])
        dfs(end, [endWord])
        return res