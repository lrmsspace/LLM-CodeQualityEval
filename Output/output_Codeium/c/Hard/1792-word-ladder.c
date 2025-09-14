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
    int res = 0;
    char* queue[5010];
    int head = 0, tail = 0;
    int visited[5010] = {0};

    queue[tail++] = beginWord;
    visited[0] = 1;
    while (head < tail) {
        char* word = queue[head++];
        for (int i = 0; i < wordListSize; i++) {
            if (visited[i]) continue;
            int diff = 0;
            for (int j = 0; j < strlen(word); j++) {
                if (word[j] != wordList[i][j]) diff++;
            }
            if (diff == 1) {
                if (strcmp(wordList[i], endWord) == 0) return res + 2;
                queue[tail++] = wordList[i];
                visited[i] = 1;
            }
        }
        res++;
    }
    return 0;
}