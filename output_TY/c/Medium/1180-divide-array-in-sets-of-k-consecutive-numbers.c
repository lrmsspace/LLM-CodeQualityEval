/**https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/ */
//Given an array of integers nums and a positive integer k, check whether it is possible to divide this array into sets of k consecutive numbers.
//Return true if it is possible. Otherwise, return false.
// 
//Example 1:
//Input: nums = [1,2,3,3,4,4,5,6], k = 4
//Output: true
//Explanation: Array can be divided into [1,2,3,4] and [3,4,5,6].
//Example 2:
//Input: nums = [3,2,1,2,3,4,3,4,5,9,10,11], k = 3
//Output: true
//Explanation: Array can be divided into [1,2,3] , [2,3,4] , [3,4,5] and [9,10,11].
//Example 3:
//Input: nums = [1,2,3,4], k = 3
//Output: false
//Explanation: Each array should be divided in subarrays of size 3.
// 
//Constraints:
//	1 <= k <= nums.length <= 105
//	1 <= nums[i] <= 109
// 
//Note: This question is the same as 846: https://leetcode.com/problems/hand-of-straights/
bool isPossibleDivide(int* nums, int numsSize, int k){
    int i,j,k1,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
    int a[100005]={0};
    int b[100005]={0};
    int c[100005]={0};
    int d[100005]={0};
    int e[100005]={0};
    int f[100005]={0};
    for(i=0;i<numsSize;i++){
        a[nums[i]]++;
    }
    for(i=1;i<=100000;i++){
        if(a[i]>0){
            b[i]=1;
        }
    }
    for(i=1;i<=100000;i++){
        if(b[i]==1){
            for(j=i+1;j<=100000;j++){
                if(b[j]==1){
                    if(a[i]==a[j]){
                        b[j]=0;
                        break;
                    }
                }
            }
        }
    }
    for(i=1;i<=100000;i++){
        if(b[i]==1){
            c[i]=1;
        }
    }
    for(i=1;i<=100000;i++){
        if(c[i]==1){
            for(j=i+1;j<=100000;j++){
                if(c[j]==1){
                    if(a[i]==a[j]){
                        c[j]=0;
                        break;
                    }
                }
            }
        }
    }
    for(i=1;i<=100000;i++){
        if(c[i]==1){
            d[i]=1;
        }
    }
    for(i=1;i<=100000;i++){
        if(d[i]==1){
            for(j=i+1;j<=100000;j++){
                if(d[j]==1){
                    if(a[i]==a[j]){
                        d[j]=0;
                        break;
                    }
                }
            }
        }
    }
    for(i=1;i<=100000;i++){
        if(d[i]==1){
            e[i]=1;
        }
    }
    for(i=1;i<=100000;i++){
        if(e[i]==1){
            f[i]=1;
        }
    }
    for(i=1;i<=100000;i++){
        if(f[i]==1){
            return false;
        }
    }
    return true;
}