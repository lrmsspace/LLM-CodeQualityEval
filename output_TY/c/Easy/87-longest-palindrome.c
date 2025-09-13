/**https://leetcode.com/problems/longest-palindrome/ */
//Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.
//Letters are case sensitive, for example, "Aa" is not considered a palindrome here.
// 
//Example 1:
//Input: s = "abccccdd"
//Output: 7
//Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.
//Example 2:
//Input: s = "a"
//Output: 1
//Explanation: The longest palindrome that can be built is "a", whose length is 1.
// 
//Constraints:
//	1 <= s.length <= 2000
//	s consists of lowercase and/or uppercase English letters only.
int longestPalindrome(char * s){
    int i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,count,max,flag;
    count=0;
    max=0;
    for(i=0;i<26;i++){
        flag=0;
        for(j=0;j<26;j++){
            if(i==j){
                continue;
            }
            if(s[i]==s[j]){
                flag=1;
                break;
            }
        }
        if(flag==0){
            count++;
        }
    }
    if(count%2==0){
        return count;
    }
    return count-1;
}