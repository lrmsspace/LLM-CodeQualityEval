/**https://leetcode.com/problems/distant-barcodes/ */
//In a warehouse, there is a row of barcodes, where the ith barcode is barcodes[i].
//Rearrange the barcodes so that no two adjacent barcodes are equal. You may return any answer, and it is guaranteed an answer exists.
// 
//Example 1:
//Input: barcodes = [1,1,1,2,2,2]
//Output: [2,1,2,1,2,1]
//Example 2:
//Input: barcodes = [1,1,1,1,2,2,3,3]
//Output: [1,3,1,3,1,2,1,2]
// 
//Constraints:
//	1 <= barcodes.length <= 10000
//	1 <= barcodes[i] <= 10000
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* rearrangeBarcodes(int* barcodes, int barcodesSize, int* returnSize){
    int i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
    int a[10001],b[10001],c[10001],d[10001],e[10001],f[10001],g[10001],h[10001],i[10001],j[10001],k[10001],l[10001],m[10001],n[10001],o[10001];
    for(i=0;i<barcodesSize;i++){
        a[barcodes[i]]++;
    }
    for(i=1;i<=10000;i++){
        if(a[i]>0){
            b[a[i]]++;
        }
    }
    for(i=1;i<=10000;i++){
        if(b[i]>0){
            c[b[i]]++;
        }
    }
    for(i=1;i<=10000;i++){
        if(c[i]>0){
            d[c[i]]++;
        }
    }
        for(i=1;i<=10000;i++){
            if(d[i]>0){
                for(j=1;j<=d[i];j++){
                    ans[k++]=i;
                }
            }
        }
        for(i=0;i<n;i++){
            printf("%d ",ans[i]);
        }
        return 0;
}