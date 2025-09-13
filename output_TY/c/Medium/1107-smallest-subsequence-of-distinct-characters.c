/**https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/ */
//Given a string s, return the lexicographically smallest subsequence of s that contains all the distinct characters of s exactly once.
// 
//Example 1:
//Input: s = "bcabc"
//Output: "abc"
//Example 2:
//Input: s = "cbacdcbc"
//Output: "acdb"
// 
//Constraints:
//	1 <= s.length <= 1000
//	s consists of lowercase English letters.
// 
//Note: This question is the same as 316: https://leetcode.com/problems/remove-duplicate-letters/
char * smallestSubsequence(char * s){
    int n=strlen(s);
    int i,j;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(s[i]==s[j]){
                s[j]='0';
            }
        }
    }
    for(i=0;i<n;i++){
        if(s[i]!='0'){
            break;
        }
    }
    for(j=i+1;j<n;j++){
        if(s[j]==s[i]){
            s[j]='0';
        }
    }
    return s+i;
}