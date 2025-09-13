/**https://leetcode.com/problems/ways-to-split-array-into-three-subarrays/ */
//A split of an integer array is good if:
//	The array is split into three non-empty contiguous subarrays - named left, mid, right respectively from left to right.
//	The sum of the elements in left is less than or equal to the sum of the elements in mid, and the sum of the elements in mid is less than or equal to the sum of the elements in right.
//Given nums, an array of non-negative integers, return the number of good ways to split nums. As the number may be too large, return it modulo 109 + 7.
// 
//Example 1:
//Input: nums = [1,1,1]
//Output: 1
//Explanation: The only good way to split nums is [1] [1] [1].
//Example 2:
//Input: nums = [1,2,2,2,5,0]
//Output: 3
//Explanation: There are three good ways of splitting nums:
//[1] [2] [2,2,5,0]
//[1] [2,2] [2,5,0]
//[1,2] [2,2] [5,0]
//Example 3:
//Input: nums = [3,2,1]
//Output: 0
//Explanation: There is no good way to split nums.
// 
//Constraints:
//	3 <= nums.length <= 105
//	0 <= nums[i] <= 104
class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int n = nums.size();
        long long prefixSum[n + 1], sum = 0, modulo = 1e9 + 7;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            prefixSum[i + 1] = sum;
        }
        int ans = 0;
        for (int i = 1; i < n - 1; ++i) {
            
            // Try to find the rightmost index j that satisfies the condition

            long long leftSum = prefixSum[i], rightSum = sum - leftSum;
            int j = lower_bound(prefixSum + i, prefixSum + n, leftSum + rightSum / 2) - prefixSum;
            
            // If it's possible to split nums[i:j-1] and nums[j:n-1], then increment the answer
            if (j < n && prefixSum[j] == leftSum + rightSum / 2) ans = (ans + 1) % modulo;
        }
        return ans;
    }
};