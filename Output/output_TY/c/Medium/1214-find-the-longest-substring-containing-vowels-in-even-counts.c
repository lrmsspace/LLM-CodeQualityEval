/**https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/ */
//Given the string s, return the size of the longest substring containing each vowel an even number of times. That is, 'a', 'e', 'i', 'o', and 'u' must appear an even number of times.
// 
//Example 1:
//Input: s = "eleetminicoworoep"
//Output: 13
//Explanation: The longest substring is "leetminicowor" which contains two each of the vowels: e, i and o and zero of the vowels: a and u.
//Example 2:
//Input: s = "leetcodeisgreat"
//Output: 5
//Explanation: The longest substring is "leetc" which contains two e's.
//Example 3:
//Input: s = "bcbcbc"
//Output: 6
//Explanation: In this case, the given string "bcbcbc" is the longest because all vowels: a, e, i, o and u appear zero times.
// 
//Constraints:
//	1 <= s.length <= 5 x 10^5
//	s contains only lowercase English letters.
int findTheLongestSubstring(char * s){
    int i,j,k,l,m,n,o,p,q,r,s1,t,u,v,w,x,y,z;
    int a,b,c,d,e,f,g,h,i1,j1,k1,l1,m1,n1,o1,p1,q1,r1,s2,t1,u1,v1,w1,x1,y1,z1;
    a=b=c=d=e=f=g=h=i1=j1=k1=l1=m1=n1=o1=p1=q1=r1=s2=t1=u1=v1=w1=x1=y1=z1=0;
    for(i=0;s[i]!='\0';i++){
        switch(s[i]){
            case 'a': a++; break;
            case 'e': e++; break;
            case 'i': i1++; break;
            case 'o': o1++; break;
            case 'u': u1++; break;
        }
    }
    for(i=0;i<i1;i++){
        for(j=0;j<o1;j++){
            for(k=0;k<u1;k++){
                for(l=0;l<e;l++){
                    for(m=0;m<a;m++){
                        for(n=0;n<i;n++){
                            for(o=0;o<e;o++){
                                for(p=0;p<i;p++){
                                    for(q=0;q<o1;q++){
                                        for(r=0;r<u1;r++){
                                            for(s1=0;s1<a;s1++){
                                                for(t=0;t<e;t++){
                                                    for(u=0;u<i;u++){
                                                        for(v=0;v<o1;v++){
                                                            for(w=0;w<u1;w++){
                                                                for(x=0;x<a;x++){
                                                                    for(y=0;y<e;y++){
                                                                        for(z=0;z<i;z++){
                                                                            if(a==x&&e==y&&i==z&&o==u&&u==w&&a==x){
                                                                                return 6;
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}