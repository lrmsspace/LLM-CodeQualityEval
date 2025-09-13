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
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char*** findLadders(char* beginWord, char* endWord, char** wordList, int wordListSize, int* returnSize, int** returnColumnSizes) {
       *returnSize = 0;
        char*** result = (char***)malloc(10000 * sizeof(char**));
        *returnColumnSizes = (int*)malloc(10000 * sizeof(int));
        int* wordListLengths = (int*)malloc(wordListSize * sizeof(int));
        for (int i = 0; i < wordListSize; i++) {
            wordListLengths[i] = strlen(wordList[i]);
        }
        int beginWordLength = strlen(beginWord);
        int endWordLength = strlen(endWord);
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
                for (int k = 0; k < wordListLengths[i]; k++) {
                    if (wordList[i][k] != wordList[j][k]) {
                        adjacencyList[i][j]++;
                    }
                }
            }
        }
        int* distances = (int*)malloc(wordListSize * sizeof(int));
        for (int i = 0; i < wordListSize; i++) {
            distances[i] = INT_MAX;
        }
        int endWordIndex = -1;
        for (int i = 0; i < wordListSize; i++) {
            if (strcmp(wordList[i], endWord) == 0) {
                endWordIndex = i;
                break;
            }
        }
        if (endWordIndex == -1) {
            return result;
        }
        distances[endWordIndex] = 0;
        queue[queueEnd++] = endWordIndex;
        while (queueStart < queueEnd) {
            int current = queue[queueStart++];
            for (int i = 0; i < wordListSize; i++) {
                if (adjacencyList[current][i] == 1) {
                    if (distances[current] + 1 < distances[i]) {
                        distances[i] = distances[current] + 1;
                        queue[queueEnd++] = i;
                    }
                }
            }
                }
                int beginWordIndex = -1;
                for (int i = 0; i < wordListSize; i++) {
                    if (strcmp(wordList[i], beginWord) == 0) {
                    beginWordIndex = i;
                    break;
                    }
                }
                if (beginWordIndex == -1) {
                    wordList[wordListSize] = beginWord;
                    wordListLengths[wordListSize] = beginWordLength;
                    beginWordIndex = wordListSize++;
                }
                queueStart = 0;
                queueEnd = 0;
                queue[queueEnd++] = beginWordIndex;
                visited[beginWordIndex] = 1;
                int found = 0;
                while (queueStart < queueEnd && !found) {
                    int levelSize = queueEnd - queueStart;
                    for (int i = 0; i < levelSize; i++) {
                    int current = queue[queueStart++];
                    for (int j = 0; j < wordListSize; j++) {
                        if (!visited[j] && adjacencyList[current][j] == 1) {
                        visited[j] = 1;
                        queue[queueEnd++] = j;
                        if (j == endWordIndex) {
                            found = 1;
                        }
                        }
                    }
                    }
                }
                if (!found) {
                    return result;
                }
                int* path = (int*)malloc(wordListSize * sizeof(int));
                int pathLength = 0;
                void dfs(int current, int depth) {
                    path[depth] = current;
                    if (current == endWordIndex) {
                    result[*returnSize] = (char**)malloc((depth + 1) * sizeof(char*));
                    for (int i = 0; i <= depth; i++) {
                        result[*returnSize][i] = wordList[path[i]];
                    }
                    (*returnColumnSizes)[*returnSize] = depth + 1;
                    (*returnSize)++;
                    return;
                    }
                    for (int i = 0; i < wordListSize; i++) {
                    if (adjacencyList[current][i] == 1 && distances[current] == distances[i] + 1) {
                        dfs(i, depth + 1);
                    }
                    }
                }
                dfs(beginWordIndex, 0);
                free(path);
                return result;  
}