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
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());
        
        int left = n - 1, right = 0;
        while (left >= 0 && right < n && nums[left] == sortedNums[left]) --left;
        while (left >= 0 && right < n && nums[right] == sortedNums[right]) ++right;
        
        if (left < 0 || right >= n) return 0;
        
        int minVal = INT_MAX, maxVal = INT_MIN;
        for (int i = left; i <= right; ++i) {
            minVal = min(minVal, nums[i]);
            maxVal = max(maxVal, nums[i]);
        }
        
        while (left >= 0 && nums[left] > minVal) --left;
        while (right < n && nums[right] < maxVal) ++right;
        
        return right - left - 1;
        
    }
};