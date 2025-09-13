/**https://leetcode.com/problems/count-of-range-sum/ */
//Given an integer array nums and two integers lower and upper, return the number of range sums that lie in [lower, upper] inclusive.
//Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j inclusive, where i <= j.
// 
//Example 1:
//Input: nums = [-2,5,-1], lower = -2, upper = 2
//Output: 3
//Explanation: The three ranges are: [0,0], [2,2], and [0,2] and their respective sums are: -2, -1, 2.
//Example 2:
//Input: nums = [0], lower = 0, upper = 0
//Output: 1
// 
//Constraints:
//	1 <= nums.length <= 105
//	-231 <= nums[i] <= 231 - 1
//	-105 <= lower <= upper <= 105
//	The answer is guaranteed to fit in a 32-bit integer.
int countRangeSum(int* nums, int numsSize, int lower, int upper){    
    int i,j,k,l,r,m,n,sum,count=0;
    int *arr=(int *)malloc(sizeof(int)*(numsSize+1));
    for(i=0;i<numsSize;i++)
    {
        arr[i+1]=arr[i]+nums[i];
    }
    for(i=0;i<numsSize;i++)
    {
        for(j=i+1;j<=numsSize;j++)
        {
            sum=arr[j]-arr[i];
            if(sum>=lower&&sum<=upper)
            {
                count++;
            }
        }
    }
    return count;
}