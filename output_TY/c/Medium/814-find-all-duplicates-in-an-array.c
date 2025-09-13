/**https://leetcode.com/problems/find-all-duplicates-in-an-array/ */
//Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.
//You must write an algorithm that runs in O(n) time and uses only constant extra space.
// 
//Example 1:
//Input: nums = [4,3,2,7,8,2,3,1]
//Output: [2,3]
//Example 2:
//Input: nums = [1,1,2]
//Output: [1]
//Example 3:
//Input: nums = [1]
//Output: []
// 
//Constraints:
//	n == nums.length
//	1 <= n <= 105
//	1 <= nums[i] <= n
//	Each element in nums appears once or twice.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDuplicates(int* nums, int numsSize, int* returnSize){
    int i,j,k;
    for(i=0;i<numsSize;i++){
        j=nums[i]-1;
        if(nums[i]!=nums[j]){
            nums[i]=nums[j];
            i--;
        }
    }
    for(i=0;i<numsSize;i++){
        j=nums[i]-1;
        if(nums[i]!=nums[j]){
            nums[j]=nums[i];
        }
    }
    for(i=0,k=0;i<numsSize;i++){
        j=nums[i]-1;
        if(i!=j){
            nums[k++]=nums[i];
        }
    }
    *returnSize=k;
    return nums;
}