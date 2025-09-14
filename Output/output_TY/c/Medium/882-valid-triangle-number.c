/**https://leetcode.com/problems/valid-triangle-number/ */
//Given an integer array nums, return the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.
// 
//Example 1:
//Input: nums = [2,2,3,4]
//Output: 3
//Explanation: Valid combinations are: 
//2,3,4 (using the first 2)
//2,3,4 (using the second 2)
//2,2,3
//Example 2:
//Input: nums = [4,2,3,4]
//Output: 4
// 
//Constraints:
//	1 <= nums.length <= 1000
//	0 <= nums[i] <= 1000
int triangleNumber(int* nums, int numsSize){
    int i,j,k,sum,count=0;
    for(i=0;i<numsSize-2;i++){
        for(j=i+1;j<numsSize-1;j++){
            for(k=j+1;k<numsSize;k++){
                sum=nums[i]+nums[j];
                if(sum>nums[k]) count++;
            }
        }
    }
    return count;
}       