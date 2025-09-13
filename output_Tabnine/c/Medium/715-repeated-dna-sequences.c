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
    int n = strlen(s);
    if (n < 10) {
        *returnSize = 0;
        return NULL;
    }
    
    int mask = (1 << 20) - 1;
    int* count = (int*)calloc(mask + 1, sizeof(int));
    int* prev = (int*)calloc(mask + 1, sizeof(int));
    char** ans = (char**)malloc(n * sizeof(char*));
    *returnSize = 0;
    
    for (int i = 0; i <= n - 10; i++) {
        int code = 0;
        for (int j = 0; j < 10; j++) {
            code = (code << 2) | (s[i + j] - 'A');
        }
        
        if (count[code] == 1 && prev[code]!= i - 9) {
            ans[*returnSize] = (char*)malloc(11 * sizeof(char));
            strncpy(ans[*returnSize], s + i, 10);
            ans[*returnSize][10] = '\0';
            (*returnSize)++;
        }
        
        count[code]++;
        prev[code] = i;
    }
    
    free(count);
    free(prev);
    
    return ans;
    
}