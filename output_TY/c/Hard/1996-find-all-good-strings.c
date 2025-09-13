/**https://leetcode.com/problems/find-all-good-strings/ */
//Given the strings s1 and s2 of size n and the string evil, return the number of good strings.
//A good string has size n, it is alphabetically greater than or equal to s1, it is alphabetically smaller than or equal to s2, and it does not contain the string evil as a substring. Since the answer can be a huge number, return this modulo 109 + 7.
// 
//Example 1:
//Input: n = 2, s1 = "aa", s2 = "da", evil = "b"
//Output: 51 
//Explanation: There are 25 good strings starting with 'a': "aa","ac","ad",...,"az". Then there are 25 good strings starting with 'c': "ca","cc","cd",...,"cz" and finally there is one good string starting with 'd': "da". 
//Example 2:
//Input: n = 8, s1 = "leetcode", s2 = "leetgoes", evil = "leet"
//Output: 0 
//Explanation: All strings greater than or equal to s1 and smaller than or equal to s2 start with the prefix "leet", therefore, there is not any good string.
//Example 3:
//Input: n = 2, s1 = "gx", s2 = "gz", evil = "x"
//Output: 2
// 
//Constraints:
//	s1.length == n
//	s2.length == n
//	s1 <= s2
//	1 <= n <= 500
//	1 <= evil.length <= 50
//	All strings consist of lowercase English letters.
int findGoodStrings(int n, char * s1, char * s2, char * evil){  
    int i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
    int a[26][26][2][2];
    memset(a,0,sizeof(a));
    int b[26][26][2][2];
    memset(b,0,sizeof(b));
    int c[26][26][2][2];
    memset(c,0,sizeof(c));
    int d[26][26][2][2];
    memset(d,0,sizeof(d));
    int e[26][26][2][2];
    memset(e,0,sizeof(e));
    for(i=0;i<26;i++){
        for(j=0;j<26;j++){
            for(k=0;k<2;k++){
                for(l=0;l<2;l++){
                    if(i==j&&k==l){
                        a[i][j][k][l]=1;
                    }
                }
            }
        }
    }
    for(i=0;i<26;i++){
        for(j=0;j<26;j++){
            for(k=0;k<2;k++){
                for(l=0;l<2;l++){
                    for(m=0;m<26;m++){
                        if(s1[i]==m+'a'){
                            b[i][j][k][l]+=a[j][m][k][l];
                        }
                    }
                }
            }
        }
    }

    for(i=0;i<26;i++){
        for(j=0;j<26;j++){
            for(k=0;k<2;k++){
                for(l=0;l<2;l++){
                    for(m=0;m<26;m++){
                        if(s2[i]==m+'a'){
                            c[i][j][k][l]+=b[j][m][k][l];   
                        }
                    }
                }
            }
        }
    }
    for(i=0;i<26;i++){
        for(j=0;j<26;j++){
            for(k=0;k<2;k++){
                for(l=0;l<2;l++){
                    for(m=0;m<26;m++){
                        if(evil[0]==m+'a'){
                            d[i][j][k][l]+=c[j][m][k][l];
                            for(n=0;n<26;n++){
                                if(evil[1]==n+'a'){
                                    e[i][j][k][l]+=d[j][n][k][l];
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return e[0][0][0][0];
}