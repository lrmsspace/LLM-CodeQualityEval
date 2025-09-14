/**https://leetcode.com/problems/maximum-subarray-min-product/ */
//The min-product of an array is equal to the minimum value in the array multiplied by the array's sum.
//	For example, the array [3,2,5] (minimum value is 2) has a min-product of 2 * (3+2+5) = 2 * 10 = 20.
//Given an array of integers nums, return the maximum min-product of any non-empty subarray of nums. Since the answer may be large, return it modulo 109 + 7.
//Note that the min-product should be maximized before performing the modulo operation. Testcases are generated such that the maximum min-product without modulo will fit in a 64-bit signed integer.
//A subarray is a contiguous part of an array.
// 
//Example 1:
//Input: nums = [1,2,3,2]
//Output: 14
//Explanation: The maximum min-product is achieved with the subarray [2,3,2] (minimum value is 2).
//2 * (2+3+2) = 2 * 7 = 14.
//Example 2:
//Input: nums = [2,3,3,1,2]
//Output: 18
//Explanation: The maximum min-product is achieved with the subarray [3,3] (minimum value is 3).
//3 * (3+3) = 3 * 6 = 18.
//Example 3:
//Input: nums = [3,1,5,6,4,2]
//Output: 60
//Explanation: The maximum min-product is achieved with the subarray [5,6,4] (minimum value is 4).
//4 * (5+6+4) = 4 * 15 = 60.
// 
//Constraints:
//	1 <= nums.length <= 105
//	1 <= nums[i] <= 107
class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size(), res = 0, sum = 0;
        vector<int> left(n), right(n);
        stack<int> s;
        for (int i = 0; i < n; ++i) {
            while (s.size() && nums[s.top()] > nums[i]) {
                int idx = s.top(); s.pop();
                right[idx] = i - idx - 1;
            }
            s.push(i);
        }
        while (s.size()) {
            int idx = s.top(); s.pop();
            right[idx] = n - idx - 1;
        }
        s = stack<int>();
        for (int i = n - 1; i >= 0; --i) {
            while (s.size() && nums[s.top()] >= nums[i]) {
                int idx = s.top(); s.pop();
                left[idx] = idx - i - 1;
            }
            s.push(i);
        }
        while (s.size()) {
            int idx = s.top(); s.pop();
            left[idx] = idx;
        }
        for (int i = 0; i < n; ++i) {
            int l = left[i], r = right[i];
            sum += nums[i];
            res = max(res, nums[i] * sum);
            if (l > 0) res = max(res, nums[i] * (sum - (l > 0 ? nums[i - l] : 0)));
            if (r > 0) res = max(res, nums[i] * (sum - (r > 0 ? nums[i + r] : 0)));
        }
        return res % (int)(1e9 + 7);
    }
};