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
        long long res = 0;
        long long sum = 0;
        int n = nums.size();
        priority_queue<int> maxQ;
        priority_queue<int, vector<int>, greater<int>> minQ;
        
        for (int i = 0; i < k; ++i) {
            sum += nums[i];
            maxQ.push(nums[i]);
            minQ.push(nums[i]);
        }
        
        res += sum;
        
        for (int i = k; i < n; ++i) {
            sum = sum - maxQ.top() + nums[i];
            maxQ.pop();
            maxQ.push(nums[i]);
            
            sum = sum - minQ.top() + nums[i];
            minQ.pop();
            minQ.push(nums[i]);
            
            res += sum;
        }
        
        return res;
    }
};