/*
 You are given an integer array nums and a positive integer k. Return the sum of the maximum and minimum elements of all subarrays with at most k elements.
 Example 1:
 Input: nums = [1,2,3], k = 2
 Output: 20
 Explanation:
 The subarrays of nums with at most 2 elements are:
 Subarray
 Minimum
 Maximum
 Sum
 [1]
 1
 1
 2
 [2]
 2
 2
 4
 [3]
 3
 3
 6
 [1, 2]
 1
 2
 3
 [2, 3]
 2
 3
 5
 Final Total
 20
 The output would be 20.
 Example 2:
 Input: nums = [1,-3,1], k = 2
 Output: -6
 Explanation:
 The subarrays of nums with at most 2 elements are:
 Subarray
 Minimum
 Maximum
 Sum
 [1]
 1
 1
 2
 [-3]
 -3
 -3
 -6
 [1]
 1
 1
 2
 [1, -3]
 -3
 1
 -2
 [-3, 1]
 -3
 1
 -2
 Final Total
 -6
 The output would be -6.
 Constraints:
 1 <= nums.length <= 80000
 1 <= k <= nums.length
 -106 <= nums[i] <= 106
*/

class Solution {
public:
    long long minMaxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long res = 0;
        vector<long long> sum(n+1, 0);
        for(int i = 0; i < n; i++){
            sum[i+1] = sum[i] + nums[i];
        }
        deque<int> dq;
        for(int i = 0; i < n; i++){
            while(!dq.empty() && dq.front() < i - k + 1) dq.pop_front();
            while(!dq.empty() && nums[dq.back()] > nums[i]) dq.pop_back();
            dq.push_back(i);
            if(i >= k - 1) res = max(res, sum[dq.front() + 1] - sum[i - k + 1] + nums[dq.front()]);
        }
        for(int i = 0; i < n; i++){
            while(!dq.empty() && dq.front() < i - k + 1) dq.pop_front();
            while(!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
            dq.push_back(i);
            if(i >= k - 1) res = min(res, sum[dq.front() + 1] - sum[i - k + 1] + nums[dq.front()]);
        }
        return res;
 
    }
};