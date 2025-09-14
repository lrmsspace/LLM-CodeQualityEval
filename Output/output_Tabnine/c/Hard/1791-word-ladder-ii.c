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
    *returnColumnSizes = NULL;
    
    // Step 1: Create a graph using the wordList
    int graphSize = wordListSize + 2; // +2 for the start and end nodes
    int** graph = (int**)malloc(graphSize * sizeof(int*));
    for (int i = 0; i < graphSize; i++) {
        graph[i] = (int*)malloc(graphSize * sizeof(int));
        for (int j = 0; j < graphSize; j++) {
            graph[i][j] = 0;
        }
    }
    for (int i = 0; i < wordListSize; i++) {
        int len = strlen(wordList[i]);
        for (int j = 0; j < wordListSize; j++) {
            if (i == j) continue;
            int diffCount = 0;
            for (int k = 0; k < len; k++) {
                if (wordList[i][k]!= wordList[j][k]) diffCount++;
                if (diffCount > 1) break;
            }
            if (diffCount == 1) {
                graph[i + 1][j + 1] = 1;
                graph[j + 1][i + 1] = 1;
            }
        }
    }
    
    // Step 2: Perform breadth-first search to find the shortest transformation sequence
    int start = 0, end = 0;
    for (int i = 0; i < wordListSize; i++) {
        if (strcmp(wordList[i], beginWord) == 0) {
            start = i + 1;
        }
        if (strcmp(wordList[i], endWord) == 0) {
            end = i + 1;
        }
    }
    if (start == 0 || end == 0) {
        return NULL;
    }
    
    int* visited = (int*)malloc(graphSize * sizeof(int));
    for (int i = 0; i < graphSize; i++) {
        visited[i] = 0;
    }
    int* prev = (int*)malloc(graphSize * sizeof(int));
    for (int i = 0; i < graphSize; i++) {
        prev[i] = -1;
    }
    
    int queueSize = 2;
    int* queue = (int*)malloc(queueSize * sizeof(int));
    queue[0] = start;
    queue[1] = end;
    
    while (queueSize > 0) {
        int front = queue[0];
        queue = (int*)realloc(queue, (--queueSize) * sizeof(int));
        
        for (int i = 0; i < graphSize; i++) {
            if (graph[front][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                prev[i] = front;
                queue = (int*)realloc(queue, ++queueSize * sizeof(int));
                queue[queueSize - 1] = i;
            }
        }
    }
    
    if (prev[end] == -1) {
        free(visited);
        free(prev);
        free(graph);
        free(queue);
        return NULL;
    }
    
    // Step 3: Construct the shortest transformation sequence
    int pathSize = 0;
    int* path = (int*)malloc((graphSize - 1) * sizeof(int));
    int curr = end;
    while (curr!= start) {
        path[pathSize++] = curr;
        curr = prev[curr];
    }
    path[pathSize++] = start;
    
    char*** result = (char***)malloc(pathSize * sizeof(char**));
    *returnSize = pathSize;
    *returnColumnSizes = (int*)malloc(pathSize * sizeof(int));
    for (int i = 0; i < pathSize; i++) {
        (*returnColumnSizes)[i] = 1;
        result[i] = (char**)malloc(sizeof(char*));
        result[i][0] = wordList[path[pathSize - i - 1] - 1];
    }
    
    free(visited);
    free(prev);
    free(graph);
    free(queue);
    free(path);
    
    return result;
    
}