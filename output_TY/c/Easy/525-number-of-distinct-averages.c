/**https://leetcode.com/problems/number-of-distinct-averages/ */
//You are given a 0-indexed integer array nums of even length.
//As long as nums is not empty, you must repetitively:
//	Find the minimum number in nums and remove it.
//	Find the maximum number in nums and remove it.
//	Calculate the average of the two removed numbers.
//The average of two numbers a and b is (a + b) / 2.
//	For example, the average of 2 and 3 is (2 + 3) / 2 = 2.5.
//Return the number of distinct averages calculated using the above process.
//Note that when there is a tie for a minimum or maximum number, any can be removed.
// 
//Example 1:
//Input: nums = [4,1,4,0,3,5]
//Output: 2
//Explanation:
//1. Remove 0 and 5, and the average is (0 + 5) / 2 = 2.5. Now, nums = [4,1,4,3].
//2. Remove 1 and 4. The average is (1 + 4) / 2 = 2.5, and nums = [4,3].
//3. Remove 3 and 4, and the average is (3 + 4) / 2 = 3.5.
//Since there are 2 distinct numbers among 2.5, 2.5, and 3.5, we return 2.
//Example 2:
//Input: nums = [1,100]
//Output: 1
//Explanation:
//There is only one average to be calculated after removing 1 and 100, so we return 1.
// 
//Constraints:
//	2 <= nums.length <= 100
//	nums.length is even.
//	0 <= nums[i] <= 100
int distinctAverages(int* nums, int numsSize){
    int i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
    int a[10000],b[10000],c[10000],d[10000],e[10000],f[10000],g[10000],h[10000],i[10000],j[10000],k[10000],l[10000],m[10000],n[10000],o[10000],p[10000],
    q[10000],r[10000],s[10000],t[10000],u[10000],v[10000],w[10000],x[10000],y[10000],z[10000];
    for(i=0;i<numsSize;i++){
        a[i]=nums[i];
    }
    for(i=0;i<numsSize;i++){
        for(j=0;j<numsSize;j++){
            if(a[i]>a[j]){
                b[i]=a[j];
                c[i]=a[i];
            }
        }
    }
    for(i=0;i<numsSize;i++){
        d[i]=b[i];
        e[i]=c[i];
    }
    for(i=0;i<numsSize;i++){
        for(j=0;j<numsSize;j++){
            if(d[i]>d[j]){
                f[i]=d[j];
                g[i]=d[i];
            }
        }
    }
    for(i=0;i<numsSize;i++){
        h[i]=f[i];
        i[i]=g[i];
    }
    for(i=0;i<numsSize;i++){
        for(j=0;j<numsSize;j++){
            if(i[i]>i[j]){
                j[i]=i[j];
                k[i]=i[i];
            }
        }
    }
    for(i=0;i<numsSize;i++){
        l[i]=j[i];
        m[i]=k[i];
    }
    for(i=0;i<numsSize;i++){
        for(j=0;j<numsSize;j++){
            if(l[i]>l[j]){
                n[i]=l[j];
                o[i]=l[i];
            }
        }
    }
    for(i=0;i<numsSize;i++){
        p[i]=n[i];
        q[i]=o[i];
    }

        for(i=0;i<numsSize;i++){
            r[i]=p[i]+q[i];
            s[i]=r[i]/2;
        }
    return s[numsSize-1];
}