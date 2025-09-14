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
    int* count = (int*)calloc(wordsSize, sizeof(int));
    for (int i = 0; i < wordsSize; i++) {
        count[i] = 1;
        for (int j = i - 1; j >= 0; j--) {
            if (strcmp(words[i], words[j]) == 0) {
                count[j]++;
                break;
            }
        }
    }
    char** result = (char**)malloc(k * sizeof(char*));
    *returnSize = 0;
    while (*returnSize < k) {
        int max = 0;
        int maxIndex = 0;
        for (int i = 0; i < wordsSize; i++) {
            if (count[i] > max) {
                max = count[i];
                maxIndex = i;
            }
        }
        if (max == 0) {
            break;
        }
        result[*returnSize] = (char*)malloc((strlen(words[maxIndex]) + 1) * sizeof(char));
        strcpy(result[*returnSize], words[maxIndex]);
        count[maxIndex] = 0;
        (*returnSize)++;
    }
    free(count);
    return result;
}