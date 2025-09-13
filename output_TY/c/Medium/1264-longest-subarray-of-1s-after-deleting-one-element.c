/**https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/ */
//Given a binary array nums, you should delete one element from it.
//Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.
// 
//Example 1:
//Input: nums = [1,1,0,1]
//Output: 3
//Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.
//Example 2:
//Input: nums = [0,1,1,1,0,1,1,0,1]
//Output: 5
//Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].
//Example 3:
//Input: nums = [1,1,1]
//Output: 2
//Explanation: You must delete one element.
// 
//Constraints:
//	1 <= nums.length <= 105
//	nums[i] is either 0 or 1.
int longestSubarray(int* nums, int numsSize){
    int i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
    i=0;
    j=0;
    k=0;
    l=0;
    m=0;
    n=0;
    o=0;
    p=0;
    q=0;
    r=0;
    s=0;
   t=0;
   u=0;
   v=0;
   w=0;
   x=0;
   y=0;
   z=0;
   for(i=0;i<numsSize;i++){
       if(nums[i]==1){
           k++;
       }
       else{
           if(k>l){
               l=k;
           }
           k=0;
       }
   }
   if(k>l){
       l=k;
   }
   return l-1;
}