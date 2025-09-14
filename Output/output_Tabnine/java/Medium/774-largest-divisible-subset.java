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
class Solution {
    public List<Integer> largestDivisibleSubset(int[] nums) {
        int n = nums.length;
        if (n == 0) return new ArrayList<>();
        
        Arrays.sort(nums);
        int[] dp = new int[n];
        Arrays.fill(dp, 1);
        int[] pre = new int[n];
        Arrays.fill(pre, -1);
        
        int maxLen = 1;
        int maxIndex = 0;
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    pre[i] = j;
                }
            }
            
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                maxIndex = i;
            }
        }
        
        List<Integer> result = new ArrayList<>();
        for (int i = maxIndex; i != -1; i = pre[i]) {
            result.add(nums[i]);
        }
        
        Collections.reverse(result);
        return result;
        
    }
}