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
    int n = strlen(beginWord);
    int count[n];
    memset(count, 0, sizeof(count));
    
    // Count the number of characters that differ in both words
    for (int i = 0; i < n; i++) {
        count[i] = (beginWord[i] == endWord[i])? 0 : 1;
    }
    
    // BFS
    int visited[wordListSize];
    memset(visited, 0, sizeof(visited));
    visited[0] = 1;
    
    int queue[wordListSize];
    int front = 0, rear = 1;
    queue[front++] = 0;
    
    while (front!= rear) {
    int u = queue[front++];
    
    // If the current word is the end word, return the length of the path
    if (strcmp(wordList[u], endWord) == 0) {
        return front - 1;
    }
    
    // Find all words that differ by a single character from the current word
    for (int i = 0; i < wordListSize; i++) {
        if (visited[i]) continue;
        
        int diff = 0;
        for (int j = 0; j < n; j++) {
            if (wordList[i][j]!= wordList[u][j]) {
                diff++;
                if (diff > 1) break;
            }
        }
        
        if (diff == 1) {
            visited[i] = 1;
            queue[rear++] = i;
        }
    }
    }
    
    return 0; // No valid transformation sequence exists
    
}