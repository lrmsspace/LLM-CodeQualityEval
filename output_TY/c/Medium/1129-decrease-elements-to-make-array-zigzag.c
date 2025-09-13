/**https://leetcode.com/problems/decrease-elements-to-make-array-zigzag/ */
//Given an array nums of integers, a move consists of choosing any element and decreasing it by 1.
//An array A is a zigzag array if either:
//	Every even-indexed element is greater than adjacent elements, ie. A[0] > A[1] < A[2] > A[3] < A[4] > ...
//	OR, every odd-indexed element is greater than adjacent elements, ie. A[0] < A[1] > A[2] < A[3] > A[4] < ...
//Return the minimum number of moves to transform the given array nums into a zigzag array.
// 
//Example 1:
//Input: nums = [1,2,3]
//Output: 2
//Explanation: We can decrease 2 to 0 or 3 to 1.
//Example 2:
//Input: nums = [9,6,1,6,2]
//Output: 4
// 
//Constraints:
//	1 <= nums.length <= 1000
//	1 <= nums[i] <= 1000
int movesToMakeZigzag(int* nums, int numsSize){
    int i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
    int a[2]={0,0};
    for(i=0;i<numsSize;i++){
        j=i-1;
        k=i+1;
        l=i-2;
        m=i+2;
        n=nums[i];
    }
    for(i=0;i<numsSize;i++){
        j=i-1;
        k=i+1;
        l=i-2;
        m=i+2;
        n=nums[i];
        if(j>=0){
            o=nums[j];
        }else{
            o=INT_MAX;
        }
        if(k<numsSize){
            p=nums[k];
        }
    }
    for(i=0;i<numsSize;i++){
        j=i-1;
        k=i+1;
        l=i-2;
        m=i+2;
        n=nums[i];
        if(j>=0){
            o=nums[j];
        }else{
            o=INT_MAX;
        }
        if(k<numsSize){
            p=nums[k];
        }
    }
    for(i=0;i<numsSize;i++){
        j=i-1;
        k=i+1;
        l=i-2;
        m=i+2;
        n=nums[i];
        if(j>=0){
            o=nums[j];
        }else{
            o=INT_MAX;
        }
        if(k<numsSize){
            p=nums[k];
        }
    }
    for(i=0;i<numsSize;i++){
        j=i-1;
        k=i+1;
        l=i-2;
        m=i+2;
        n=nums[i];
        if(j>=0){
            o=nums[j];
        }else{
            o=INT_MAX;
        }
        if(k<numsSize){
            p=nums[k];
        }
    }
    return a[0]+a[1];
}