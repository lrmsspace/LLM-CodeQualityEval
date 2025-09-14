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
class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        // Step 1: Create a set of all words in wordList
        Set<String> wordSet = new HashSet<>(wordList);
        
        // Step 2: Create a queue to store the words and their transformations
        Queue<String> queue = new LinkedList<>();
        queue.offer(beginWord);
        
        // Step 3: Create a map to store the transformations of words
        Map<String, Integer> transformations = new HashMap<>();
        transformations.put(beginWord, 1);
        
        // Step 4: Create a set to store the visited words
        Set<String> visited = new HashSet<>();
        visited.add(beginWord);
        
        // Step 5: Perform Breadth-First Search
        while (!queue.isEmpty()) {

            String currentWord = queue.poll();
            int currentLength = transformations.get(currentWord);
            
            // Step 5.1: Check if the currentWord is the endWord
            if (currentWord.equals(endWord)) {
                return currentLength;
            }
            
            // Step 5.2: Generate all possible transformations of the currentWord
            char[] currentChars = currentWord.toCharArray();
            for (int i = 0; i < currentChars.length; i++) {
                char originalChar = currentChars[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    currentChars[i] = c;
                    String transformedWord = new String(currentChars);
                    
                    // Step 5.2.1: Check if the transformed word is in the wordSet and not visited
                    if (wordSet.contains(transformedWord) &&!visited.contains(transformedWord)) {
                        queue.offer(transformedWord);
                        transformations.put(transformedWord, currentLength + 1);
                        visited.add(transformedWord);
                    }
                }
                currentChars[i] = originalChar;
            }
            
            // Step 5.3: Remove the current word from the wordSet and visited set
            wordSet.remove(currentWord);
            visited.remove(currentWord);
        }
        
        // Step 6: Return 0 if no transformation sequence exists
        return 0;
        
    }
}