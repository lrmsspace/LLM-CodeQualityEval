/**https://leetcode.com/problems/subarrays-with-k-different-integers/ */
//Given an integer array nums and an integer k, return the number of good subarrays of nums.
//A good array is an array where the number of different integers in that array is exactly k.
//	For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
//A subarray is a contiguous part of an array.
// 
//Example 1:
//Input: nums = [1,2,1,2,3], k = 2
//Output: 7
//Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]
//Example 2:
//Input: nums = [1,2,1,3,4], k = 3
//Output: 3
//Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].
// 
//Constraints:
//	1 <= nums.length <= 2 * 104
//	1 <= nums[i], k <= nums.length
int subarraysWithKDistinct(int* nums, int numsSize, int k){
    int i,j,count,count1,count2,ans;
    count=count1=count2=ans=0;
    for(i=0,j=0;i<numsSize;i++){
        if(count1<k){
            if(count1==0||nums[i]!=nums[i-1]){
                count1++;
            }
        }
        if(count2<k){
            if(count2==0||nums[i]!=nums[i-1]){
                count2++;
           }
        }
    }
    while(j<i){
        if(count1==k&&count2==k){
            ans+=i-j+1;
        }
        if(nums[j]!=nums[i]){
            if(nums[j]==nums[j-1]){
                count1--;
            }
            else{
                count2--;
            }
        }
        j++;
    }
    return ans;
}