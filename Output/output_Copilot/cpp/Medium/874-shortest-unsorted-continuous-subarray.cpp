/**https://leetcode.com/problems/shortest-unsorted-continuous-subarray/ */
//Given an integer array nums, you need to find one continuous subarray such that if you only sort this subarray in non-decreasing order, then the whole array will be sorted in non-decreasing order.
//Return the shortest such subarray and output its length.
// 
//Example 1:
//Input: nums = [2,6,4,8,10,9,15]
//Output: 5
//Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
//Example 2:
//Input: nums = [1,2,3,4]
//Output: 0
//Example 3:
//Input: nums = [1]
//Output: 0
// 
//Constraints:
//	1 <= nums.length <= 104
//	-105 <= nums[i] <= 105
// 
//Follow up: Can you solve it in O(n) time complexity?
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l < r && nums[l] <= nums[l + 1]) l++;
        if (l == r) return 0;
        while (nums[r] >= nums[r - 1]) r--;
        int mn = INT_MAX, mx = INT_MIN;
        for (int i = l; i <= r; i++) {
            mn = min(mn, nums[i]);
            mx = max(mx, nums[i]);
        }
        int l1 = 0, r1 = n - 1;
        while (nums[l1] <= mn) l1++;
        while (nums[r1] >= mx) r1--;
        return r1 - l1 + 1;        
    }
};