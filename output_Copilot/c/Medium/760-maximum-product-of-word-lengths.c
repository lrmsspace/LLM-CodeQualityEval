/**https://leetcode.com/problems/maximum-product-of-word-lengths/ */
//Given a string array words, return the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. If no such two words exist, return 0.
// 
//Example 1:
//Input: words = ["abcw","baz","foo","bar","xtfn","abcdef"]
//Output: 16
//Explanation: The two words can be "abcw", "xtfn".
//Example 2:
//Input: words = ["a","ab","abc","d","cd","bcd","abcd"]
//Output: 4
//Explanation: The two words can be "ab", "cd".
//Example 3:
//Input: words = ["a","aa","aaa","aaaa"]
//Output: 0
//Explanation: No such pair of words.
// 
//Constraints:
//	2 <= words.length <= 1000
//	1 <= words[i].length <= 1000
//	words[i] consists only of lowercase English letters.
int maxProduct(char** words, int wordsSize) {
    int *mask = (int *)malloc(sizeof(int) * wordsSize);
    int *len = (int *)malloc(sizeof(int) * wordsSize);
    int i, j, k, max = 0;
    for (i = 0; i < wordsSize; i++) {
        mask[i] = 0;
        for (j = 0; words[i][j]; j++) {
            mask[i] |= 1 << (words[i][j] - 'a');
        }
        len[i] = j;
    }
    for (i = 0; i < wordsSize; i++) {
        for (j = i + 1; j < wordsSize; j++) {
            if ((mask[i] & mask[j]) == 0) {
                k = len[i] * len[j];
                if (k > max) {
                    max = k;
                }
            }
        }
    }
    free(mask);
    free(len);
    return max;    
}