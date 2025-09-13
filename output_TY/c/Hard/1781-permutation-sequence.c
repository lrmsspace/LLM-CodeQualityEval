/**https://leetcode.com/problems/permutation-sequence/ */
//The set [1, 2, 3, ..., n] contains a total of n! unique permutations.
//By listing and labeling all of the permutations in order, we get the following sequence for n = 3:
//	"123"
//	"132"
//	"213"
//	"231"
//	"312"
//	"321"
//Given n and k, return the kth permutation sequence.
// 
//Example 1:
//Input: n = 3, k = 3
//Output: "213"
//Example 2:
//Input: n = 4, k = 9
//Output: "2314"
//Example 3:
//Input: n = 3, k = 1
//Output: "123"
// 
//Constraints:
//	1 <= n <= 9
//	1 <= k <= n!
char * getPermutation(int n, int k){
    int i,j,t,k1,k2,k3,k4,k5,k6,k7,k8,k9,k10;
    char *s=(char*)malloc(sizeof(char)*n+1);    
    s[n]='\0';
    for(i=0;i<n;i++){
        s[i]=i+1+'0';
    }
    for(i=0;i<k;i++){
        for(j=0;j<n-1;j++){
            if(s[j]>s[j+1]){
                t=s[j];
                s[j]=s[j+1];
                s[j+1]=t;
            }
        }
    }
    return s;
}