/**https://leetcode.com/problems/monotonic-array/ */
//An array is monotonic if it is either monotone increasing or monotone decreasing.
//An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j]. An array nums is monotone decreasing if for all i <= j, nums[i] >= nums[j].
//Given an integer array nums, return true if the given array is monotonic, or false otherwise.
// 
//Example 1:
//Input: nums = [1,2,2,3]
//Output: true
//Example 2:
//Input: nums = [6,5,4,4]
//Output: true
//Example 3:
//Input: nums = [1,3,2]
//Output: false
// 
//Constraints:
//	1 <= nums.length <= 105
//	-105 <= nums[i] <= 105
bool isMonotonic(int* nums, int numsSize){
    int i,j,k;
    for(i=0;i<numsSize-1;i++){
        if(nums[i]>nums[i+1]){
            for(j=i+1;j<numsSize-1;j++){
                if(nums[j]<nums[j+1])
                    return false;
            }
            break;
        }
    }
    for(k=i+1;k<numsSize-1;k++){
        if(nums[k]<nums[k+1])
            return false;
    }
    return true;
}