/**https://leetcode.com/problems/substring-with-concatenation-of-all-words/ */
//You are given a string s and an array of strings words. All the strings of words are of the same length.
//A concatenated string is a string that exactly contains all the strings of any permutation of words concatenated.
//	For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab" are all concatenated strings. "acdbef" is not a concatenated string because it is not the concatenation of any permutation of words.
//Return an array of the starting indices of all the concatenated substrings in s. You can return the answer in any order.
// 
//Example 1:
//Input: s = "barfoothefoobarman", words = ["foo","bar"]
//Output: [0,9]
//Explanation:
//The substring starting at 0 is "barfoo". It is the concatenation of ["bar","foo"] which is a permutation of words.
//The substring starting at 9 is "foobar". It is the concatenation of ["foo","bar"] which is a permutation of words.
//Example 2:
//Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
//Output: []
//Explanation:
//There is no concatenated substring.
//Example 3:
//Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
//Output: [6,9,12]
//Explanation:
//The substring starting at 6 is "foobarthe". It is the concatenation of ["foo","bar","the"].
//The substring starting at 9 is "barthefoo". It is the concatenation of ["bar","the","foo"].
//The substring starting at 12 is "thefoobar". It is the concatenation of ["the","foo","bar"].
// 
//Constraints:
//	1 <= s.length <= 104
//	1 <= words.length <= 5000
//	1 <= words[i].length <= 30
//	s and words[i] consist of lowercase English letters.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
    int* result = malloc(sizeof(int) * (sSize - wordsSize * words[0]->length + 1));
    *returnSize = 0;
    if (s == NULL || words == NULL || wordsSize == 0 || words[0]->length == 0) {
        return result;
    }
    int wordLen = words[0]->length;
    int wordCount = wordsSize;
    int* wordDict = malloc(sizeof(int) * wordCount);
    for (int i = 0; i < wordCount; i++) {
        wordDict[i] = 0;
    }
    for (int i = 0; i <= sSize - wordLen * wordCount; i++) {
        for (int j = 0; j < wordCount; j++) {
            if (wordDict[j] == 0) {
                if (strncmp(s + i, words[j], wordLen) == 0) {
                    wordDict[j] = 1;
                    break;
                }
            } else if (strncmp(s + i, words[j], wordLen)!= 0) {
                wordDict[j] = 0;
                break;
            }
        }
        if (j == wordCount) {
            result[*returnSize] = i;
            (*returnSize)++;
        }
    }
    free(wordDict);
    return result;
}