/**https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/ */
//Given an integer array nums and an integer k, find three non-overlapping subarrays of length k with maximum sum and return them.
//Return the result as a list of indices representing the starting position of each interval (0-indexed). If there are multiple answers, return the lexicographically smallest one.
// 
//Example 1:
//Input: nums = [1,2,1,2,6,7,5,1], k = 2
//Output: [0,3,5]
//Explanation: Subarrays [1, 2], [2, 6], [7, 5] correspond to the starting indices [0, 3, 5].
//We could have also taken [2, 1], but an answer of [1, 3, 5] would be lexicographically larger.
//Example 2:
//Input: nums = [1,2,1,2,1,2,1,2,1], k = 2
//Output: [0,2,4]
// 
//Constraints:
//	1 <= nums.length <= 2 * 104
//	1 <= nums[i] < 216
//	1 <= k <= floor(nums.length / 3)
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefixSum(n + 1);
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        
        vector<int> left(n, 0);
        vector<int> right(n, n - 1);
        int maxSum = INT_MIN;
        for (int i = k; i <= n - 2 * k; ++i) {
            int sum = prefixSum[i + k] - prefixSum[i];
            if (sum > maxSum) {
                maxSum = sum;
                left[i] = i - k + 1;
            }
        }
        
        maxSum = INT_MIN;
        for (int i = n - 2 * k - 1; i >= k; --i) {
            int sum = prefixSum[i + k] - prefixSum[i];
            if (sum > maxSum) {
                maxSum = sum;
                right[i] = i + k - 1;
            }
        }
        
        vector<int> result;
        maxSum = INT_MIN;
        for (int i = k; i <= n - 2 * k; ++i) {
            int sum = prefixSum[left[i - k] + k] + prefixSum[i + k] - prefixSum[right[i + k] + k];
            if (sum > maxSum) {
                maxSum = sum;
                result = {left[i - k], i, right[i + k]};
            }
        }
        return result;
        
    }
};