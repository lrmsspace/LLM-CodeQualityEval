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
    
    // Check if endWord is in wordList
    bool endWordExists = false;
    for (int i = 0; i < wordListSize; i++) {
        if (strcmp(wordList[i], endWord) == 0) {
            endWordExists = true;
            break;
        }
    }
    
    if (!endWordExists) {
        return NULL;
    }
    
    // Build the graph
    int graphSize;
    Node** graph = buildGraph(beginWord, wordList, wordListSize, &graphSize);
    
    // Find shortest paths using BFS
    Node* endNode = bfs(graph, graphSize, endWord);
    
    // If endWord is not reachable
    if (endNode == NULL) {
        // Clean up graph
        for (int i = 0; i < graphSize; i++) {
            free(graph[i]->word);
            free(graph[i]->neighbors);
            if (graph[i]->parents) free(graph[i]->parents);
            free(graph[i]);
        }
        free(graph);
        
        return NULL;
    }
    
    // Allocate memory for results
    // We don't know exactly how many paths there will be, so allocate a large number
    char*** paths = (char***)malloc(10000 * sizeof(char**));
    *returnColumnSizes = (int*)malloc(10000 * sizeof(int));
    
    // Construct all shortest paths using DFS
    char** currentPath = (char**)malloc(graphSize * sizeof(char*));
    dfs(endNode, graph[0], paths, returnColumnSizes, returnSize, currentPath, 0);
    free(currentPath);
    
    // Clean up graph
    for (int i = 0; i < graphSize; i++) {
        free(graph[i]->word);
        free(graph[i]->neighbors);
        if (graph[i]->parents) free(graph[i]->parents);
        free(graph[i]);
    }
    free(graph);
    
    return paths;   
}