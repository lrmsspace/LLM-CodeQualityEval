/**https://leetcode.com/problems/array-of-doubled-pairs/ */
//Given an integer array of even length arr, return true if it is possible to reorder arr such that arr[2 * i + 1] = 2 * arr[2 * i] for every 0 <= i < len(arr) / 2, or false otherwise.
// 
//Example 1:
//Input: arr = [3,1,3,6]
//Output: false
//Example 2:
//Input: arr = [2,1,2,6]
//Output: false
//Example 3:
//Input: arr = [4,-2,2,-4]
//Output: true
//Explanation: We can take two groups, [-2,-4] and [2,4] to form [-2,-4,2,4] or [2,4,-2,-4].
// 
//Constraints:
//	2 <= arr.length <= 3 * 104
//	arr.length is even.
//	-105 <= arr[i] <= 105
bool canReorderDoubled(int* arr, int arrSize){
    int i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
    int a[200000],b[200000],c[200000],d[200000],e[200000],f[200000],g[200000],h[200000],i0,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11,i12,i13;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    memset(d,0,sizeof(d));
    memset(e,0,sizeof(e));
    memset(f,0,sizeof(f));
    memset(g,0,sizeof(g));
    memset(h,0,sizeof(h));
    for(i=0;i<arrSize;i++){
        if(arr[i]>=0){
            a[arr[i]]++;
        }else{
            b[-arr[i]]++;
        }
    }
    for(i=0;i<=50000;i++){
        if(a[i]%2==1){
            return false;
        }
    }
    for(i=1;i<=50000;i++){
        if(a[i]>0){
            c[i]=(a[i]-1)/2;
            d[i]=1;
        }
    }
    for(i=1;i<=50000;i++){
        if(b[i]>0){
            if(c[i]>=b[i]){
                c[i]-=b[i];
                b[i]=0;
            }else{
                b[i]-=c[i];
                c[i]=0;
            }
        }
    }
    for(i=1;i<=50000;i++){
        if(c[i]>0){
            return false;
        }
    }
    return true;
}