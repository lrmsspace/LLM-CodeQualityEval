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
char ** findRepeatedDnaSequences(char * s, int* returnSize){
    int i,j,k;
    int hash[26]={0};
    char **ans=(char**)malloc(sizeof(char*)*1000);
    int ans_size=0;
    for(i=0;i<26;i++){
        hash[i]=i+1;
    }
    for(i=0;i<strlen(s)-9;i++){
        int num=0;
        for(j=i;j<i+10;j++){
            num=num*4+hash[s[j]-'A'];
        }
    }
    for(i=0;i<strlen(s)-9;i++){
        int num=0;
        for(j=i;j<i+10;j++){
            num=num*4+hash[s[j]-'A'];
        }
        for(k=0;k<ans_size;k++){
            if(strcmp(ans[k],s+i)==0){
                break;
           }
        }
    }
    *returnSize=ans_size;
    return ans;
}