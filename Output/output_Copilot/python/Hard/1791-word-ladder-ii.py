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
        from collections import defaultdict, deque

        wordSet = set(wordList)
        if endWord not in wordSet:
            return []

        # Step 1: Build the graph using BFS
        graph = defaultdict(list)
        queue = deque([beginWord])
        visited = {beginWord: 0}
        found = False

        while queue and not found:
            for _ in range(len(queue)):
                word = queue.popleft()
                for i in range(len(word)):
                    for c in 'abcdefghijklmnopqrstuvwxyz':
                        new_word = word[:i] + c + word[i + 1:]
                        if new_word in wordSet:
                            if new_word not in visited:
                                visited[new_word] = visited[word] + 1
                                queue.append(new_word)
                            graph[word].append(new_word)
                            if new_word == endWord:
                                found = True

        # Step 2: Backtrack to find all paths
        def backtrack(word):
            if word == beginWord:
                return [[beginWord]]
            paths = []
            for prev in graph[word]:
                for path in backtrack(prev):
                    paths.append(path + [word])
            return paths

        return backtrack(endWord) if found else []        