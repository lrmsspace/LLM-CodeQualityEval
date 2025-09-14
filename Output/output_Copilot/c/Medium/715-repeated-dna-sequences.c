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
    char** res = (char**)malloc(sizeof(char*) * len);
    int* hash = (int*)malloc(sizeof(int) * 1048576);
    memset(hash, 0, sizeof(int) * 1048576);
    int i = 0, j = 0, k = 0;
    for (i = 0; i < 10; i++) {
        k = k << 2 | (s[i] == 'A' ? 0 : (s[i] == 'C' ? 1 : (s[i] == 'G' ? 2 : 3)));
    }
    hash[k]++;
    for (i = 10; i < len; i++) {
        k = ((k & 0x3ffff) << 2) | (s[i] == 'A' ? 0 : (s[i] == 'C' ? 1 : (s[i] == 'G' ? 2 : 3)));
        hash[k]++;
        if (hash[k] == 2) {
            res[j] = (char*)malloc(sizeof(char) * 11);
            for (int l = 0; l < 10; l++) {
                res[j][l] = (k >> (18 - l * 2) & 0x3) == 0 ? 'A' : ((k >> (18 - l * 2) & 0x3) == 1 ? 'C' : ((k >> (18 - l * 2) & 0x3) == 2 ? 'G' : 'T'));
            }
            res[j++][10] = '\0';
        }
    }
    *returnSize = j;
    return res;    
}