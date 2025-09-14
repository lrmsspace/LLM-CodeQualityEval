/**https://leetcode.com/problems/count-the-number-of-consistent-strings/ */
//You are given a string allowed consisting of distinct characters and an array of strings words. A string is consistent if all characters in the string appear in the string allowed.
//Return the number of consistent strings in the array words.
// 
//Example 1:
//Input: allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
//Output: 2
//Explanation: Strings "aaab" and "baa" are consistent since they only contain characters 'a' and 'b'.
//Example 2:
//Input: allowed = "abc", words = ["a","b","c","ab","ac","bc","abc"]
//Output: 7
//Explanation: All strings are consistent.
//Example 3:
//Input: allowed = "cad", words = ["cc","acd","b","ba","bac","bad","ac","d"]
//Output: 4
//Explanation: Strings "cc", "acd", "ac", and "d" are consistent.
// 
//Constraints:
//	1 <= words.length <= 104
//	1 <= allowed.length <= 26
//	1 <= words[i].length <= 10
//	The characters in allowed are distinct.
//	words[i] and allowed contain only lowercase English letters.


int countConsistentStrings(char * allowed, char ** words, int wordsSize){
    int i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z;
    int count=0;
    for(i=0;i<wordsSize;i++){
        for(j=0;j<26;j++){
            for(k=0;k<26;k++){
                if(allowed[j]==words[i][k]){
                    count++;
                    break;
                }
            }
        }
    }
    return count;
}