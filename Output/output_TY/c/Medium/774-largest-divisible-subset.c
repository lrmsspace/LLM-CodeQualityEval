/**https://leetcode.com/problems/largest-divisible-subset/ */
//Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:
//	answer[i] % answer[j] == 0, or
//	answer[j] % answer[i] == 0
//If there are multiple solutions, return any of them.
// 
//Example 1:
//Input: nums = [1,2,3]
//Output: [1,2]
//Explanation: [1,3] is also accepted.
//Example 2:
//Input: nums = [1,2,4,8]
//Output: [1,2,4,8]
// 
//Constraints:
//	1 <= nums.length <= 1000
//	1 <= nums[i] <= 2 * 109
//	All the integers in nums are unique.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* largestDivisibleSubset(int* nums, int numsSize, int* returnSize){
    int i,j,k;
    int *dp,*pre;
    dp=(int*)malloc(numsSize*sizeof(int));
    pre=(int*)malloc(numsSize*sizeof(int));
    for(i=0;i<numsSize;i++){
        dp[i]=1;
        pre[i]=-1;
    }
    for(i=1;i<numsSize;i++){
        for(j=i-1;j>=0;j--){
            if(nums[i]%nums[j]==0){
                if(dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                    pre[i]=j;
                }
            }
        }
    }
    max=0;
    for(i=0;i<numsSize;i++){
        if(dp[i]>max){
            max=dp[i];
            end=i;
        }
    }
    for(i=0;i<max;i++){
        res[i]=nums[end];
        end=pre[end];
    }
    return res;
}