/**https://leetcode.com/problems/substring-with-concatenation-of-all-words/ */
//You are given a string s and an array of strings words. All the strings of words are of the same length.
//A concatenated substring in s is a substring that contains all the strings of any permutation of words concatenated.
//	For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab" are all concatenated strings. "acdbef" is not a concatenated substring because it is not the concatenation of any permutation of words.
//Return the starting indices of all the concatenated substrings in s. You can return the answer in any order.
// 
//Example 1:
//Input: s = "barfoothefoobarman", words = ["foo","bar"]
//Output: [0,9]
//Explanation: Since words.length == 2 and words[i].length == 3, the concatenated substring has to be of length 6.
//The substring starting at 0 is "barfoo". It is the concatenation of ["bar","foo"] which is a permutation of words.
//The substring starting at 9 is "foobar". It is the concatenation of ["foo","bar"] which is a permutation of words.
//The output order does not matter. Returning [9,0] is fine too.
//Example 2:
//Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
//Output: []
//Explanation: Since words.length == 4 and words[i].length == 4, the concatenated substring has to be of length 16.
//There is no substring of length 16 is s that is equal to the concatenation of any permutation of words.
//We return an empty array.
//Example 3:
//Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
//Output: [6,9,12]
//Explanation: Since words.length == 3 and words[i].length == 3, the concatenated substring has to be of length 9.
//The substring starting at 6 is "foobarthe". It is the concatenation of ["foo","bar","the"] which is a permutation of words.
//The substring starting at 9 is "barthefoo". It is the concatenation of ["bar","the","foo"] which is a permutation of words.
//The substring starting at 12 is "thefoobar". It is the concatenation of ["the","foo","bar"] which is a permutation of words.
// 
//Constraints:
//	1 <= s.length <= 104
//	1 <= words.length <= 5000
//	1 <= words[i].length <= 30
//	s and words[i] consist of lowercase English letters.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findSubstring(char * s, char ** words, int wordsSize, int* returnSize){
    int* res = (int*)malloc(sizeof(int) * 1000);
    int* word_len = (int*)malloc(sizeof(int) * wordsSize);
    int* word_count = (int*)malloc(sizeof(int) * wordsSize);
    int* word_count_tmp = (int*)malloc(sizeof(int) * wordsSize);
    int* word_len_tmp = (int*)malloc(sizeof(int) * wordsSize);
    int i, j, k, l, m, n, o, p, q, r, t, u, v, w, x, y, z;
    for (i = 0; i < wordsSize; i++) {
        word_len[i] = strlen(words[i]);
    }
    for (i = 0; i < wordsSize; i++) {
        word_count[i] = 0;
    }
    for (i = 0; i < wordsSize; i++) {
        for (j = 0; j < wordsSize; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                word_count[i]++;
            }
        }
    }
    for (i = 0; i < wordsSize; i++) {
        word_count_tmp[i] = word_count[i];
    }
    for (i = 0; i < wordsSize; i++) {
        word_len_tmp[i] = word_len[i];
    }
    for (i = 0; i < strlen(s) - wordsSize * word_len[0] + 1; i++) {
        for (j = 0; j < wordsSize; j++) {
            for (k = 0; k < wordsSize; k++) {
                if (strncmp(s + i + j * word_len[0], words[k], word_len[k]) == 0) {
                    word_count_tmp[k]--;
                }
            }
        }
    }
    for (i = 0; i < wordsSize; i++) {
        if (word_count_tmp[i] != 0) {
            goto end;
        }
    }
    for (i = 0; i < strlen(s) - wordsSize * word_len[0] + 1; i++) {
        for (j = 0; j < wordsSize; j++) {
            for (k = 0; k < wordsSize; k++) {
                if (strncmp(s + i + j * word_len[0], words[k], word_len[k]) == 0) {
                    word_count_tmp[k]--;
                }
            }
        }
    }
    for (i = 0; i < wordsSize; i++) {
        if (word_count_tmp[i] != 0) {
            goto end;
        }
        for (j = 0; j < wordsSize; j++) {
            if (strncmp(s + i + j * word_len[0], words[j], word_len[j]) == 0) {
                word_count_tmp[j]--;
            }
        }
        for (j = 0; j < wordsSize; j++) {
            if (word_count_tmp[j] != 0) {
                goto end;
            }
        }
        result[result_size++] = i;
        for (j = 0; j < wordsSize; j++) {
            word_count_tmp[j] = word_count[j];
        }
        i += word_len[0];
        if (i + word_len[0] * wordsSize > len) {
            break;
        }
    }
    end:i += word_len[0];
    return result;
}