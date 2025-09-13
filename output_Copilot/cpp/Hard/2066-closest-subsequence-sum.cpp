/**https://leetcode.com/problems/closest-subsequence-sum/ */
//You are given an integer array nums and an integer goal.
//You want to choose a subsequence of nums such that the sum of its elements is the closest possible to goal. That is, if the sum of the subsequence's elements is sum, then you want to minimize the absolute difference abs(sum - goal).
//Return the minimum possible value of abs(sum - goal).
//Note that a subsequence of an array is an array formed by removing some elements (possibly all or none) of the original array.
// 
//Example 1:
//Input: nums = [5,-7,3,5], goal = 6
//Output: 0
//Explanation: Choose the whole array as a subsequence, with a sum of 6.
//This is equal to the goal, so the absolute difference is 0.
//Example 2:
//Input: nums = [7,-9,15,-2], goal = -5
//Output: 1
//Explanation: Choose the subsequence [7,-9,-2], with a sum of -4.
//The absolute difference is abs(-4 - (-5)) = abs(1) = 1, which is the minimum.
//Example 3:
//Input: nums = [1,2,3], goal = -7
//Output: 7
// 
//Constraints:
//	1 <= nums.length <= 40
//	-107 <= nums[i] <= 107
//	-109 <= goal <= 109
class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        int n1 = n / 2, n2 = n - n1;
        vector<int> sum1(1 << n1), sum2(1 << n2);
        for (int i = 0; i < 1 << n1; ++i) {
            for (int j = 0; j < n1; ++j) {
                if (i >> j & 1) sum1[i] += nums[j];
            }
        }
        for (int i = 0; i < 1 << n2; ++i) {
            for (int j = 0; j < n2; ++j) {
                if (i >> j & 1) sum2[i] += nums[n1 + j];
            }
        }
        sort(sum2.begin(), sum2.end());
        int res = INT_MAX;
        for (int x : sum1) {
            int y = goal - x;
            int i = lower_bound(sum2.begin(), sum2.end(), y) - sum2.begin();
            if (i < sum2.size()) res = min(res, abs(y - sum2[i]));
            if (i > 0) res = min(res, abs(y - sum2[i - 1]));
        }
        return res;        
    }
};