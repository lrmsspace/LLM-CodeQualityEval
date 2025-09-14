/**https://leetcode.com/problems/partition-equal-subset-sum/ */
//Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.
// 
//Example 1:
//Input: nums = [1,5,11,5]
//Output: true
//Explanation: The array can be partitioned as [1, 5, 5] and [11].
//Example 2:
//Input: nums = [1,2,3,5]
//Output: false
//Explanation: The array cannot be partitioned into equal sum subsets.
// 
//Constraints:
//	1 <= nums.length <= 200
//	1 <= nums[i] <= 100
class Solution {
    public boolean canPartition(int[] nums) {
        int sum = 0;
        for(int i:nums)
            sum+=i;
        if(sum%2==1)
            return false;
        int target = sum/2;
        boolean[] dp = new boolean[target+1];
        dp[0] = true;
        for(int i=0;i<nums.length;i++){
            for(int j=target;j>=nums[i];j--){
                dp[j] = dp[j]||dp[j-nums[i]];
            }
        }
        return dp[target];
    }
}