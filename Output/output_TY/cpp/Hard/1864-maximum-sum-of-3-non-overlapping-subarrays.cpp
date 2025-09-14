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
        vector<int> preSum(n, 0);
        preSum[0] = nums[0];
        for(int i = 1; i < n; i++){
            preSum[i] = preSum[i - 1] + nums[i];
        }
        vector<int> left(n, 0), right(n, 0);
        for(int i = 0; i < n; i++){
            if(i >= k){
                left[i] = max(left[i - 1], preSum[i] - preSum[i - k]);
            }else{
                left[i] = preSum[i];
            }
        }
        for(int i = n - 1; i >= 0; i--){
            if(i + k <= n){
                right[i] = max(right[i + 1], preSum[i + k - 1] - preSum[i]);
            }else{
                right[i] = preSum[n - 1] - preSum[i];
            }
        }
        vector<int> ans(3, 0);
        for(int i = k; i < n - 2 * k; i++){
            if(left[i - 1] + right[i + k] > ans[2]){
                ans[0] = left[i - 1];
                ans[1] = i;
                ans[2] = left[i - 1] + right[i + k];
            }
        }
        return ans;
    }
};