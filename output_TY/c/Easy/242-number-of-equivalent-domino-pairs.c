/**https://leetcode.com/problems/number-of-equivalent-domino-pairs/ */
//Given a list of dominoes, dominoes[i] = [a, b] is equivalent to dominoes[j] = [c, d] if and only if either (a == c and b == d), or (a == d and b == c) - that is, one domino can be rotated to be equal to another domino.
//Return the number of pairs (i, j) for which 0 <= i < j < dominoes.length, and dominoes[i] is equivalent to dominoes[j].
// 
//Example 1:
//Input: dominoes = [[1,2],[2,1],[3,4],[5,6]]
//Output: 1
//Example 2:
//Input: dominoes = [[1,2],[1,2],[1,1],[1,2],[2,2]]
//Output: 3
// 
//Constraints:
//	1 <= dominoes.length <= 4 * 104
//	dominoes[i].length == 2
//	1 <= dominoes[i][j] <= 9
int numEquivDominoPairs(int** dominoes, int dominoesSize, int* dominoesColSize){
    int i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
    int a,b,c,d,e,f,g,h,j1,j2,j3,j4,j5,j6,j7,j8,j9,j10,j11,j1
    12,j13,j14,j15,j16,j17,j18,j19,j20,j21,j22,j23,j24,j25,j26,j27,j28,j29,j30,j31,j32,j33,j34,j35,j36,j37,j38,j39,j40,j41,j42,j43,j44,j45,j46,j47,j48,j49,j50,j51,
    j52,j53,j54,j55,j56,j57,j58,j59,j60,j61,j62,j63,j64,j65,j66,j67,j68,j69,j70,j71,j72,j73,j74,j75,j76,j77,j78,j79,j80,j81,j82,j83,j84,j85,j86,j87,j88,j89,j90,j91,
    j92,j93,j94,j95,j96,j97,j98,j99,j100;
    int count=0;
    for(i=0;i<dominoesSize;i++){
        for(j=i+1;j<dominoesSize;j++){
            a=dominoes[i][0];
            b=dominoes[i][1];
            c=dominoes[j][0];
            d=dominoes[j][1];
            if(a==c&&b==d){
                count++;
            }
        }
    }
    return count;
}