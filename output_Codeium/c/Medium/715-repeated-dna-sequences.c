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
    int sLen = strlen(s);
    char** result = (char**)malloc(1 * sizeof(char*));
    *returnSize = 0;
    if (sLen <= 10) return result;
    
    char* temp = (char*)malloc(11 * sizeof(char));
    temp[10] = '\0';
    int seen[1 << 20] = {0};
    for (int i = 0; i < sLen - 9; i++) {
        memcpy(temp, &s[i], 10);
        int t = 0;
        for (int j = 0; j < 10; j++) {
            t |= (s[i + j] - 'A' + 1) << (j * 2);
        }
        if (seen[t] == 1) {
            result[*returnSize] = (char*)malloc(11 * sizeof(char));
            memcpy(result[*returnSize], temp, 11);
            (*returnSize)++;
        }
        seen[t] = (seen[t] + 1) % 2;
    }
    free(temp);
    return result;
}