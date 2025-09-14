/**https://leetcode.com/problems/minimum-number-of-operations-to-make-all-array-elements-equal-to-1/ */
//You are given a 0-indexed array nums consisiting of positive integers. You can do the following operation on the array any number of times:
//	Select an index i such that 0 <= i < n - 1 and replace either of nums[i] or nums[i+1] with their gcd value.
//Return the minimum number of operations to make all elements of nums equal to 1. If it is impossible, return -1.
//The gcd of two integers is the greatest common divisor of the two integers.
// 
//Example 1:
//Input: nums = [2,6,3,4]
//Output: 4
//Explanation: We can do the following operations:
//- Choose index i = 2 and replace nums[2] with gcd(3,4) = 1. Now we have nums = [2,6,1,4].
//- Choose index i = 1 and replace nums[1] with gcd(6,1) = 1. Now we have nums = [2,1,1,4].
//- Choose index i = 0 and replace nums[0] with gcd(2,1) = 1. Now we have nums = [1,1,1,4].
//- Choose index i = 2 and replace nums[3] with gcd(1,4) = 1. Now we have nums = [1,1,1,1].
//Example 2:
//Input: nums = [2,10,6,14]
//Output: -1
//Explanation: It can be shown that it is impossible to make all the elements equal to 1.
// 
//Constraints:
//	2 <= nums.length <= 50
//	1 <= nums[i] <= 106
// 
//Follow-up:
//The O(n) time complexity solution works, but could you find an O(1) constant time complexity solution?
int minOperations(int* nums, int numsSize){
    int i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
    int a[1000000]={0};
    int b[1000000]={0};
    int c[1000000]={0};
    int d[1000000]={0};
    int e[1000000]={0};
    int f[1000000]={0};
    for(i=0;i<numsSize;i++){
        a[nums[i]]++;
    }
    for(i=0;i<1000000;i++){
        if(a[i]!=0){
            b[i]=1;
        }
    }
    for(i=0;i<1000000;i++){
        if(b[i]!=0){
            c[i]=1;
        }
    }
    for(i=0;i<1000000;i++){
        if(c[i]!=0){
            d[i]=1;
        }
    }
    for(i=0;i<1000000;i++){
        if(d[i]!=0){
            e[i]=1;
        }
    }
    for(i=0;i<1000000;i++){
        if(e[i]!=0){
            f[i]=1;
        }
    }
    for(i=0;i<1000000;i++){
        if(f[i]!=0){
            return i;
        }
    }
    return -1;
}