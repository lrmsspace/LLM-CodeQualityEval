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
    int maxProduct = 0;
    int* charCount = (int*)calloc(26, sizeof(int));
    
    for (int i = 0; i < wordsSize; i++) {
        int product = 0;
        for (int j = 0; j < words[i][j]; j++) {
            charCount[words[i][j] - 'a']++;
        }
        
        for (int j = 0; j < 26; j++) {
            product += charCount[j];
            if (product == 0) break;
        }
        
        maxProduct = fmax(maxProduct, product * (words[i][words[i] - 1] - 'a' + 1));
        
        for (int j = 0; j < 26; j++) {
            charCount[j] = 0;
        }
    }
    
    free(charCount);
    return maxProduct;
    
}