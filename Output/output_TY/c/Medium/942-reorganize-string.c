/**https://leetcode.com/problems/reorganize-string/ */
//Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.
//Return any possible rearrangement of s or return "" if not possible.
// 
//Example 1:
//Input: s = "aab"
//Output: "aba"
//Example 2:
//Input: s = "aaab"
//Output: ""
// 
//Constraints:
//	1 <= s.length <= 500
//	s consists of lowercase English letters.
char * reorganizeString(char * s){
    int i,j,k,l,m,n,o,p,q,r,s1,t,u,v,w,x,y,z;
    int a[26]={0};
    char b[5001];
    char c[5001];
    char d[5001];
    char e[5001];
    char f[5001];
    char g[5001];
    char h[5001];
    for(i=0;i<strlen(s);i++){
        a[s[i]-'a']++;
    }
    for(i=0;i<26;i++){
        if(a[i]>0){
            for(j=0;j<a[i];j++){
                b[k++]=i+'a';
            }
        }
    }
    for(i=0;i<strlen(s);i++){
        c[i]=s[i];
    }
    for(i=0;i<strlen(s);i++){
        if(c[i]=='a'||c[i]=='e'||c[i]=='i'||c[i]=='o'||c[i]=='u'){
            d[i]=c[i];
        }
    }
    for(i=0;i<strlen(s);i++){
        if(c[i]=='a'||c[i]=='e'||c[i]=='i'||c[i]=='o'||c[i]=='u'){
            c[i]=' ';
        }
    }
    for(i=0;i<strlen(s);i++){
        if(c[i]!=' '){
            c[i]=d[j];
            j++;
        }
    }
    return c;
}