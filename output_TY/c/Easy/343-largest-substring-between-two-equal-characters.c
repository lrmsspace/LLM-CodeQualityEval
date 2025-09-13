/**https://leetcode.com/problems/largest-substring-between-two-equal-characters/ */
//Given a string s, return the length of the longest substring between two equal characters, excluding the two characters. If there is no such substring return -1.
//A substring is a contiguous sequence of characters within a string.
// 
//Example 1:
//Input: s = "aa"
//Output: 0
//Explanation: The optimal substring here is an empty substring between the two 'a's.
//Example 2:
//Input: s = "abca"
//Output: 2
//Explanation: The optimal substring here is "bc".
//Example 3:
//Input: s = "cbzxy"
//Output: -1
//Explanation: There are no characters that appear twice in s.
// 
//Constraints:
//	1 <= s.length <= 300
//	s contains only lowercase English letters.
int maxLengthBetweenEqualCharacters(char * s){
    int i,j,k,l,m,n,o,p,q,r,s1,t,u,v,w,x,y,z;
    i=0;
    j=0;
    k=0;
    l=0;
    m=0;
    n=0;
    o=0;
    p=0;
    q=0;
    r=0;
    s1=0;
    t=0;
    u=0;
    v=0;
    w=0;
    x=0;
    y=0;
    z=0;
    while(s[i]!='\0'){
        j=i+1;
        while(s[j]!='\0'){
            if(s[i]==s[j]){
                k=j-i-1;
                if(k>s1){
                    s1=k;
                }
            }
            j++;
        }
        i++;
    }
    return s1;
}