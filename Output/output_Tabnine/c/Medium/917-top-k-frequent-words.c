/**https://leetcode.com/problems/top-k-frequent-words/ */
//Given an array of strings words and an integer k, return the k most frequent strings.
//Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.
// 
//Example 1:
//Input: words = ["i","love","leetcode","i","love","coding"], k = 2
//Output: ["i","love"]
//Explanation: "i" and "love" are the two most frequent words.
//Note that "i" comes before "love" due to a lower alphabetical order.
//Example 2:
//Input: words = ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
//Output: ["the","is","sunny","day"]
//Explanation: "the", "is", "sunny" and "day" are the four most frequent words, with the number of occurrence being 4, 3, 2 and 1 respectively.
// 
//Constraints:
//	1 <= words.length <= 500
//	1 <= words[i].length <= 10
//	words[i] consists of lowercase English letters.
//	k is in the range [1, The number of unique words[i]]
// 
//Follow-up: Could you solve it in O(n log(k)) time and O(n) extra space?
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** topKFrequent(char** words, int wordsSize, int k, int* returnSize) {
    // Create a hash map to count the frequency of each word
    int* freq = malloc(wordsSize * sizeof(int));
    for (int i = 0; i < wordsSize; i++) {
        freq[i] = 0;
    }
    for (int i = 0; i < wordsSize; i++) {
        for (int j = 0; words[i][j]; j++) {
            freq[i]++;
        }
    }
    
    // Create a max heap to store the top k frequent words
    int* heap = malloc((k + 1) * sizeof(int));
    for (int i = 0; i <= k; i++) {
        heap[i] = -1;
    }
    int heapSize = 0;
    
    // Build the max heap
    for (int i = 0; i < wordsSize; i++) {
        int wordFreq = freq[i];
        if (wordFreq > 0) {
            int parent = (wordFreq - 1) / 2;
            while (wordFreq > heap[parent]) {
                int temp = heap[wordFreq];
                heap[wordFreq] = heap[parent];
                heap[parent] = temp;
                wordFreq = parent;
                parent = (wordFreq - 1) / 2;
            }
            if (wordFreq <= k) {
                heap[wordFreq] = i;
                heapSize++;
            }
        }
    }
    
    // Extract the top k frequent words
    char** result = malloc(k * sizeof(char*));
    *returnSize = k;
    for (int i = k - 1; i >= 0; i--) {
        result[i] = strdup(words[heap[i]]);
    }
    
    // Free the allocated memory
    free(freq);
    free(heap);
    
    return result;
    
}