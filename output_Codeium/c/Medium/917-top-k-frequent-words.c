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
static int compare(const void* a, const void* b) {
    struct TrieNode* node1 = *(struct TrieNode**)a; 
    struct TrieNode* node2 = *(struct TrieNode**)b;
    if (node1->count != node2->count) {
        return node2->count - node1->count;
    }
    return strcmp(node1->key, node2->key);
}
char** topKFrequent(char** words, int wordsSize, int k, int* returnSize) {
    *returnSize = 0;
    
    struct TrieNode {
        int count;
        struct TrieNode* children[26];
        UT_hash_handle hh;
    };
    struct TrieNode* root = NULL;
    for (int i = 0; i < wordsSize; ++i) {
        struct TrieNode* node = NULL;
        HASH_FIND_STR(root, words[i], node);
        if (!node) {
            node = (struct TrieNode*)malloc(sizeof(struct TrieNode));
            memset(node, 0, sizeof(struct TrieNode));
            HASH_ADD_STR(root, key, node);
        }
        ++node->count;
    }
    struct TrieNode* nodes[wordsSize];
    int i = 0;
    for (struct TrieNode* node = root; node; node = node->hh.next) {
        nodes[i++] = node;
    }
    qsort(nodes, i, sizeof(struct TrieNode*), compare);
    char** result = (char**)malloc(sizeof(char*) * k);
    for (int j = 0; j < k; ++j) {
        result[j] = (char*)malloc(strlen(words[j]) + 1);
        strcpy(result[j], words[j]);
    }
    *returnSize = k;
    return result;
}


