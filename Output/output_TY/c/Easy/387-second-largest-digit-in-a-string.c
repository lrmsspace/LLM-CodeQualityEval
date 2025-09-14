/**https://leetcode.com/problems/second-largest-digit-in-a-string/ */
//Given an alphanumeric string s, return the second largest numerical digit that appears in s, or -1 if it does not exist.
//An alphanumeric string is a string consisting of lowercase English letters and digits.
// 
//Example 1:
//Input: s = "dfa12321afd"
//Output: 2
//Explanation: The digits that appear in s are [1, 2, 3]. The second largest digit is 2.
//Example 2:
//Input: s = "abc1111"
//Output: -1
//Explanation: The digits that appear in s are [1]. There is no second largest digit. 
// 
//Constraints:
//	1 <= s.length <= 500
//	s consists of only lowercase English letters and/or digits.
int secondHighest(char * s){
    int i,j,k,l,m,n,o,p,q,r,s1,t,u,v,w,x,y,z,a,b,c,d,e,f,g,h,j,k1,l1,m1,n1,o1,p1,q1,r1,s2,t1,u1,v1,w1,x1,y1,z1;
    a=b=c=d=e=f=g=h=i=j=k=l=m=n=o=p=q=r=s=t=u=v=w=x=y=z=-1;
    for(i=0;i<strlen(s);i++){
        if(s[i]>='0'&&s[i]<='9'){
            if(s[i]-'0'>a){
                b=a;
                a=s[i]-'0';
            }
            else if(s[i]-'0'>b){
                b=s[i]-'0';
            }
        }
    }
    return b;
}