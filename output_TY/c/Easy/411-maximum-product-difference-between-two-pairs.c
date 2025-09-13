/**https://leetcode.com/problems/maximum-product-difference-between-two-pairs/ */
//The product difference between two pairs (a, b) and (c, d) is defined as (a * b) - (c * d)._x000D_
//_x000D_
//_x000D_
//	For example, the product difference between (5, 6) and (2, 7) is (5 * 6) - (2 * 7) = 16._x000D_
//_x000D_
//_x000D_
//Given an integer array nums, choose four distinct indices w, x, y, and z such that the product difference between pairs (nums[w], nums[x]) and (nums[y], nums[z]) is maximized._x000D_
//_x000D_
//Return the maximum such product difference._x000D_
//_x000D_
// _x000D_
//Example 1:_x000D_
//_x000D_
//_x000D_
//Input: nums = [5,6,2,7,4]_x000D_
//Output: 34_x000D_
//Explanation: We can choose indices 1 and 3 for the first pair (6, 7) and indices 2 and 4 for the second pair (2, 4)._x000D_
//The product difference is (6 * 7) - (2 * 4) = 34._x000D_
//_x000D_
//_x000D_
//Example 2:_x000D_
//_x000D_
//_x000D_
//Input: nums = [4,2,5,9,7,4,8]_x000D_
//Output: 64_x000D_
//Explanation: We can choose indices 3 and 6 for the first pair (9, 8) and indices 1 and 5 for the second pair (2, 4)._x000D_
//The product difference is (9 * 8) - (2 * 4) = 64._x000D_
//_x000D_
//_x000D_
// _x000D_
//Constraints:_x000D_
//_x000D_
//_x000D_
//	4 <= nums.length <= 104_x000D_
//	1 <= nums[i] <= 104_x000D_
int maxProductDifference(int* nums, int numsSize){
    int i,j,k,l,max1,max2,min1,min2;
    max1=max2=min1=min2=0;
    for(i=0;i<numsSize;i++){
        if(nums[i]>max1){
            max2=max1;
            max1=nums[i];
        }
        else if(nums[i]>max2){
            max2=nums[i];
        }
        if(nums[i]<min1){
            min2=min1;
            min1=nums[i];
        }
    }
    return (max1*max2)-(min1*min2);
}