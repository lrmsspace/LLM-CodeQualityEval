/**https://leetcode.com/problems/most-frequent-even-element/ */
//Given an integer array nums, return the most frequent even element.
//If there is a tie, return the smallest one. If there is no such element, return -1.
// 
//Example 1:
//Input: nums = [0,1,2,2,4,4,1]
//Output: 2
//Explanation:
//The even elements are 0, 2, and 4. Of these, 2 and 4 appear the most.
//We return the smallest one, which is 2.
//Example 2:
//Input: nums = [4,4,4,9,2,4]
//Output: 4
//Explanation: 4 is the even element appears the most.
//Example 3:
//Input: nums = [29,47,21,41,13,37,25,7]
//Output: -1
//Explanation: There is no even element.
// 
//Constraints:
//	1 <= nums.length <= 2000
//	0 <= nums[i] <= 105
int mostFrequentEven(int* nums, int numsSize){
    int i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
    int a[100000]={0};
    int b[100000]={0};
    int c[100000]={0};
    int d[100000]={0};
    int e[100000]={0};
    int f[100000]={0};
    for(i=0;i<numsSize;i++){
        if(nums[i]%2==0){
            a[nums[i]]++;
        }
    }
    for(i=0;i<100000;i++){
        if(a[i]>0){
            b[i]=a[i];
            c[i]=i;
        }
    }
    for(i=0;i<100000;i++){
        for(j=0;j<100000;j++){
            if(b[i]<b[j]){
                t=b[i];
                b[i]=b[j];
                b[j]=t;
                t=c[i];
                c[i]=c[j];
                c[j]=t;
            }
        }
    }
    for(i=0;i<100000;i++){
        if(b[i]>0){
            d[i]=b[i];
            e[i]=c[i];
        }
    }
    for(i=0;i<100000;i++){
        if(d[i]==0){
            return -1;
        }
    }
    return e[0];
}