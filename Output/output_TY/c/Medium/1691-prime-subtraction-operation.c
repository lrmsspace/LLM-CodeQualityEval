/**https://leetcode.com/problems/prime-subtraction-operation/ */
//You are given a 0-indexed integer array nums of length n.
//You can perform the following operation as many times as you want:
//	Pick an index i that you haven’t picked before, and pick a prime p strictly less than nums[i], then subtract p from nums[i].
//Return true if you can make nums a strictly increasing array using the above operation and false otherwise.
//A strictly increasing array is an array whose each element is strictly greater than its preceding element.
// 
//Example 1:
//Input: nums = [4,9,6,10]
//Output: true
//Explanation: In the first operation: Pick i = 0 and p = 3, and then subtract 3 from nums[0], so that nums becomes [1,9,6,10].
//In the second operation: i = 1, p = 7, subtract 7 from nums[1], so nums becomes equal to [1,2,6,10].
//After the second operation, nums is sorted in strictly increasing order, so the answer is true.
//Example 2:
//Input: nums = [6,8,11,12]
//Output: true
//Explanation: Initially nums is sorted in strictly increasing order, so we don't need to make any operations.
//Example 3:
//Input: nums = [5,8,3]
//Output: false
//Explanation: It can be proven that there is no way to perform operations to make nums sorted in strictly increasing order, so the answer is false.
// 
//Constraints:
//	1 <= nums.length <= 1000
//	1 <= nums[i] <= 1000
//	nums.length == n
bool primeSubOperation(int* nums, int numsSize){
    int i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
    int a[1000]={0};
    int b[1000]={0};
    int c[1000]={0};
    int d[1000]={0};
    int e[1000]={0};
    int f[1000]={0};
    for(i=0;i<numsSize;i++){
        if(nums[i]==2){
            a[i]=1;
        }
    }
    for(i=0;i<numsSize;i++){
        if(nums[i]==3){
            b[i]=1;
        }
    }
    for(i=0;i<numsSize;i++){
        if(nums[i]==5){
            c[i]=1;
        }
    }
    for(i=0;i<numsSize;i++){
        if(nums[i]==7){
            d[i]=1;
        }
    }
    for(i=0;i<numsSize;i++){
        if(nums[i]==11){
            e[i]=1;
        }
    }
    for(i=0;i<numsSize;i++){
        if(nums[i]==13){
            f[i]=1;
        }
    }
    for(i=0;i<numsSize;i++){
        if(nums[i]==1){
            nums[i]=0;
        }
    }
    for(i=0;i<numsSize;i++){
        if(nums[i]==4){
            nums[i]=3;
        }
    }
    for(i=0;i<numsSize;i++){
        if(nums[i]==6){
            nums[i]=5;
        }
    }
    for(i=0;i<numsSize;i++){
       if(nums[i]==8){
          nums[i]=7;
       }
    }
    for(i=0;i<numsSize;i++){
        if(nums[i]==9){
            nums[i]=8;
        }
    }
    printf("%d",nums[0]);
    for(i=1;i<numsSize;i++){
        if(nums[i]==10){
            nums[i]=9;
        }
    }
    for(i=0;i<numsSize;i++){
        if(nums[i]==12){
            nums[i]=11;
        }
    }
    for(i=0;i<numsSize;i++){
        if(nums[i]==14){
            nums[i]=13;
        }
    }
    for(i=0;i<numsSize;i++){
       if(nums[i]==15){
          nums[i]=14;
          return 0;
       }
    }
    return 1;
}