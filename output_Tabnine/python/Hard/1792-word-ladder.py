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
        # Initialize a queue to store the words and their corresponding lengths
        queue = [(beginWord, 1)]
        
        # Initialize a set to store the visited words
        visited = {beginWord}
        
        # Initialize a dictionary to store the neighboring words
        neighbors = self.get_neighbors(beginWord, wordList)
        
        # Breadth-first search
        while queue:
            current_word, current_length = queue.pop(0)
            
            # If the current word is the end word, return the current length
            if current_word == endWord:
                return current_length
            
            # Add the current word to the visited set
            visited.add(current_word)
            
            # Get the neighbors of the current word
            neighbors_current_word = neighbors[current_word]
            
            # Remove the neighbors that have already been visited
            neighbors_current_word = [neighbor for neighbor in neighbors_current_word if neighbor not in visited]
            
            # Add the neighbors to the queue
            queue.extend([(neighbor, current_length + 1) for neighbor in neighbors_current_word])
            
            # Update the neighbors dictionary
            neighbors[current_word] = neighbors_current_word
        
        # No valid transformation sequence exists
        return 0
        