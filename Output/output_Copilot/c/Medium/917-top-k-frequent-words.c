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
    *returnSize = k;
    char **res = (char **)malloc(sizeof(char *) * k);
    int i, j, l, r, m, n = 0;
    char *tmp;
    int *count = (int *)malloc(sizeof(int) * wordsSize);
    char **word = (char **)malloc(sizeof(char *) * wordsSize);
    for (i = 0; i < wordsSize; i++) {
        for (j = 0; j < n; j++) {
            if (strcmp(words[i], word[j]) == 0) {
                count[j]++;
                break;
            }
        }
        if (j == n) {
            word[n] = words[i];
            count[n++] = 1;
        }
    }
    for (i = 0; i < k; i++) {
        for (j = i + 1; j < n; j++) {
            if (count[i] < count[j] || (count[i] == count[j] && strcmp(word[i], word[j]) > 0)) {
                tmp = word[i];
                word[i] = word[j];
                word[j] = tmp;
                m = count[i];
                count[i] = count[j];
                count[j] = m;
            }
        }
        res[i] = (char *)malloc(sizeof(char) * (strlen(word[i]) + 1));
        strcpy(res[i], word[i]);
    }
    return res;    
}