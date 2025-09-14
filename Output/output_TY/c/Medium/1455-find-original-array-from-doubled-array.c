/**https://leetcode.com/problems/find-original-array-from-doubled-array/ */
//An integer array original is transformed into a doubled array changed by appending twice the value of every element in original, and then randomly shuffling the resulting array.
//Given an array changed, return original if changed is a doubled array. If changed is not a doubled array, return an empty array. The elements in original may be returned in any order.
// 
//Example 1:
//Input: changed = [1,3,4,2,6,8]
//Output: [1,3,4]
//Explanation: One possible original array could be [1,3,4]:
//- Twice the value of 1 is 1 * 2 = 2.
//- Twice the value of 3 is 3 * 2 = 6.
//- Twice the value of 4 is 4 * 2 = 8.
//Other original arrays could be [4,3,1] or [3,1,4].
//Example 2:
//Input: changed = [6,3,0,1]
//Output: []
//Explanation: changed is not a doubled array.
//Example 3:
//Input: changed = [1]
//Output: []
//Explanation: changed is not a doubled array.
// 
//Constraints:
//	1 <= changed.length <= 105
//	0 <= changed[i] <= 105
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findOriginalArray(int* changed, int changedSize, int* returnSize){
    int i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
    int a[100001]={0};
    int b[100001]={0};
    int c[100001]={0};
    int d[100001]={0};
    int e[100001]={0};
    int f[100001]={0};
    for(i=0;i<changedSize;i++){
        a[changed[i]]++;
    }
    for(i=0;i<100001;i++){
        if(a[i]%2==1){
            returnSize[0]=0;
            return NULL;
        }
        else{
            b[i]=a[i]/2;
        }
    }
    for(i=0;i<100001;i++){
        if(b[i]==0){
            continue;
        }
        else{
            for(j=0;j<b[i];j++){
                c[i]++;
                d[i*2]++;
            }
        }
    }
    for(i=0;i<100001;i++){
        if(d[i]==c[i]){
            e[i]=1;
        }
        else{
            returnSize[0]=0;
            return NULL;
        }
    }
    for(i=0;i<100001;i++){
        if(e[i]==1){
            f[i]=1;
        }
        else{
            f[i]=0;
        }
    }
    returnSize[0]=100001;
    return f;
}