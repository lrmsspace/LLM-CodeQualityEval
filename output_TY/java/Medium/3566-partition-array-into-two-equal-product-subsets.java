/*
 You are given an integer array nums containing distinct positive integers and an integer target.
 Determine if you can partition nums into two non-empty disjoint subsets, with each element belonging to exactly one subset, such that the product of the elements in each subset is equal to target.
 Return true if such a partition exists and false otherwise.
 A subset of an array is a selection of elements of the array.
 Example 1:
 Input: nums = [3,1,6,8,4], target = 24
 Output: true
 Explanation: The subsets [3, 8] and [1, 6, 4] each have a product of 24. Hence, the output is true.
 Example 2:
 Input: nums = [2,5,3,7], target = 15
 Output: false
 Explanation: There is no way to partition nums into two non-empty disjoint subsets such that both subsets have a product of 15. Hence, the output is false.
 Constraints:
 3 <= nums.length <= 12
 1 <= target <= 1015
 1 <= nums[i] <= 100
 All elements of nums are distinct.
*/

class Solution {
    public boolean checkEqualPartitions(int[] nums, long target) {
        int n = nums.length;
        long sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
        }
        if(sum % 2 != 0)
        {
            return false;
        }
        target = sum / 2;
        boolean[][] dp = new boolean[n + 1][(int)target + 1];
        for(int i = 0; i <= n; i++)
        {
            dp[i][0] = true;
        }
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= target; j++)
            {
                if(j >= nums[i - 1])
                {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][target];
        
    }
}