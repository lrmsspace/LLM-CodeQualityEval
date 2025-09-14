/**https://leetcode.com/problems/advantage-shuffle/ */
//You are given two integer arrays nums1 and nums2 both of the same length. The advantage of nums1 with respect to nums2 is the number of indices i for which nums1[i] > nums2[i].
//Return any permutation of nums1 that maximizes its advantage with respect to nums2.
// 
//Example 1:
//Input: nums1 = [2,7,11,15], nums2 = [1,10,4,11]
//Output: [2,11,7,15]
//Example 2:
//Input: nums1 = [12,24,8,32], nums2 = [13,25,32,11]
//Output: [24,32,8,12]
// 
//Constraints:
//	1 <= nums1.length <= 105
//	nums2.length == nums1.length
//	0 <= nums1[i], nums2[i] <= 109
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* advantageCount(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
    int *a,*b,*c,*d,*e,*f,*g,*h,*i,*j,*k,*l,*m,*n,*o,*p,*q,*r,*s,*t,*u,*v,*w,*x,*y,*z;
    a=(int*)malloc(sizeof(int)*nums1Size);
    b=(int*)malloc(sizeof(int)*nums1Size);
    c=(int*)malloc(sizeof(int)*nums1Size);
    d=(int*)malloc(sizeof(int)*nums1Size);
    e=(int*)malloc(sizeof(int)*nums1Size);
    f=(int*)malloc(sizeof(int)*nums1Size);
    for(i=0;i<nums1Size;i++){
        a[i]=nums1[i];
        b[i]=nums2[i];
    }
    qsort(a,nums1Size,sizeof(int),cmp);
        qsort(b,nums1Size,sizeof(int),cmp);
        for(i=0;i<nums1Size;i++){
            c[i]=a[i]-b[i];
        }
        for(i=0;i<nums1Size;i++){
            d[i]=a[i]-c[i];
        }
        for(i=0;i<nums1Size;i++){
            e[i]=a[i]-d[i];
        }
       for(i=0;i<nums1Size;i++){
          i=0;i<nums1Size;i++
       }
    return e;

}