/**https://leetcode.com/problems/repeated-dna-sequences/ */
//The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.
//	For example, "ACGAATTCCG" is a DNA sequence.
//When studying DNA, it is useful to identify repeated sequences within the DNA.
//Given a string s that represents a DNA sequence, return all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule. You may return the answer in any order.
// 
//Example 1:
//Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
//Output: ["AAAAACCCCC","CCCCCAAAAA"]
//Example 2:
//Input: s = "AAAAAAAAAAAAA"
//Output: ["AAAAAAAAAA"]
// 
//Constraints:
//	1 <= s.length <= 105
//	s[i] is either 'A', 'C', 'G', or 'T'.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findRepeatedDnaSequences(char* s, int* returnSize) {
    int len = strlen(s);
    if (len < 10) {
        *returnSize = 0;
        return NULL;
    }
    int* hash = (int*)calloc(1 << 20, sizeof(int));
    char** ans = (char**)malloc(sizeof(char*) * len);
    int ansSize = 0;
    int key = 0;
    for (int i = 0; i < 9; i++) {
        key = (key << 2) | (s[i] & 3);
    }
    for (int i = 9; i < len; i++) {
        key = ((key << 2) & ((1 << 20) - 1)) | (s[i] & 3);
        if (hash[key]++ == 1) {
            ans[ansSize] = (char*)malloc(sizeof(char) * 11);
            strncpy(ans[ansSize], s + i - 9, 10);
            ans[ansSize][10] = '\0';
            ansSize++;
        }
    }
    *returnSize = ansSize;
    free(hash);
    return ans;
}