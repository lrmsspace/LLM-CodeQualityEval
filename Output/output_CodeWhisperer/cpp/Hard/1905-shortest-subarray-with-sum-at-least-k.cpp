/**https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/ */
//Given an integer array nums and an integer k, return the length of the shortest non-empty subarray of nums with a sum of at least k. If there is no such subarray, return -1.
//A subarray is a contiguous part of an array.
// 
//Example 1:
//Input: nums = [1], k = 1
//Output: 1
//Example 2:
//Input: nums = [1,2], k = 4
//Output: -1
//Example 3:
//Input: nums = [2,-1,2], k = 3
//Output: 3
// 
//Constraints:
//	1 <= nums.length <= 105
//	-105 <= nums[i] <= 105
//	1 <= k <= 109
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> pre(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + nums[i];
        }
        deque<int> q;
        int res = n + 1;
        for (int i = 0; i <= n; i++) {
            while (!q.empty() && pre[i] - pre[q.front()] >= k) {
                res = min(res, i - q.front());
                q.pop_front();
            }
            while (!q.empty() && pre[i] <= pre[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        return res <= n ? res : -1;      
    }
};