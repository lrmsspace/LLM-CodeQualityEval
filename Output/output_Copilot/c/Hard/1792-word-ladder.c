/**https://leetcode.com/problems/word-ladder/ */
//A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:
//	Every adjacent pair of words differs by a single letter.
//	Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
//	sk == endWord
//Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.
// 
//Example 1:
//Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
//Output: 5
//Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
//Example 2:
//Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
//Output: 0
//Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
// 
//Constraints:
//	1 <= beginWord.length <= 10
//	endWord.length == beginWord.length
//	1 <= wordList.length <= 5000
//	wordList[i].length == beginWord.length
//	beginWord, endWord, and wordList[i] consist of lowercase English letters.
//	beginWord != endWord
//	All the words in wordList are unique.
int ladderLength(char* beginWord, char* endWord, char** wordList, int wordListSize) {
        int endWordIndex = -1;
        for (int i = 0; i < wordListSize; i++) {
            if (strcmp(endWord, wordList[i]) == 0) {
                endWordIndex = i;
                break;
            }
        }
        if (endWordIndex == -1) {
            return 0;
        }
        int* visited = (int*)malloc(wordListSize * sizeof(int));
        for (int i = 0; i < wordListSize; i++) {
            visited[i] = 0;
        }
        int* queue = (int*)malloc(wordListSize * sizeof(int));
        int queueStart = 0, queueEnd = 0;
        int** adjacencyList = (int**)malloc(wordListSize * sizeof(int*));
        for (int i = 0; i < wordListSize; i++) {
            adjacencyList[i] = (int*)malloc(wordListSize * sizeof(int));
            for (int j = 0; j < wordListSize; j++) {
                adjacencyList[i][j] = 0;
                for (int k = 0; k < strlen(wordList[i]); k++) {
                    if (wordList[i][k] != wordList[j][k]) {
                        adjacencyList[i][j]++;
                    }
                }
            }
        }
        for (int i = 0; i < wordListSize; i++) {
            if (strcmp(beginWord, wordList[i]) == 0) {
                queue[queueEnd++] = i;
                visited[i] = 1;
                break;
            }
        }
        int level = 1;
        while (queueStart < queueEnd) {
            int queueSize = queueEnd - queueStart;
            for (int i = 0; i < queueSize; i++) {
                int current = queue[queueStart++];
                if (current == endWordIndex) {
                    return level;
                }
                for (int j = 0; j < wordListSize; j++) {
                    if (visited[j] == 0 && adjacencyList[current][j] == 1) {
                        queue[queueEnd++] = j;
                        visited[j] = 1;
                    }
                }
            }
            level++;
        }
        return 0;
    }      
}