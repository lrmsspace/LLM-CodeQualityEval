/**https://leetcode.com/problems/ways-to-split-array-into-good-subarrays/ */
//You are given a binary array nums.
//A subarray of an array is good if it contains exactly one element with the value 1.
//Return an integer denoting the number of ways to split the array nums into good subarrays. As the number may be too large, return it modulo 109 + 7.
//A subarray is a contiguous non-empty sequence of elements within an array.
// 
//Example 1:
//Input: nums = [0,1,0,0,1]
//Output: 3
//Explanation: There are 3 ways to split nums into good subarrays:
//- [0,1] [0,0,1]
//- [0,1,0] [0,1]
//- [0,1,0,0] [1]
//Example 2:
//Input: nums = [0,1,0]
//Output: 1
//Explanation: There is 1 way to split nums into good subarrays:
//- [0,1,0]
// 
//Constraints:
//	1 <= nums.length <= 105
//	0 <= nums[i] <= 1
class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            pre[i] = pre[i - 1] + nums[i - 1];
        }
        int res = 0;
        int mod = 1e9 + 7;
        for (int i = 1; i < n; i++) {
            int l = i + 1, r = n - 1;
            while (l <= r) {
                int mid = l + r >> 1;
                if (pre[mid] - pre[i] >= pre[i]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            res = (res + l - i) % mod;
        }    
        return res;    
    }
};